//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <sstream>
#include <climits>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
//	{{{2
//	ltrim(), rtrim(), split(), join(), printVector(), printMap()
//	{{{
string ltrim(const string &str) {
//	{{{
    string s(str);
    auto it = std::find_if(s.begin(), s.end(),
                    [](char c) {
                        return !std::isspace<char>(c, std::locale::classic());
                    });
    s.erase(s.begin(), it);
    return s;
}
//	}}}
string rtrim(const string &str) {
//	{{{
    string s(str);
    auto it = std::find_if(s.rbegin(), s.rend(),
                    [](char c) {
                        return !std::isspace<char>(c, std::locale::classic());
                    });
    s.erase(it.base(), s.end());
    return s;
}
//	}}}
vector<string> split(const string &str, const char delim=' ') {
//	{{{
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(delim, start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
//	}}}
template <typename T>
string join(const vector<T> words, const char delim=' ') {
	//	{{{
	string result = "";
	for (int i = 0; i < words.size(); ++i) {
		result += std::to_string(words[i]);
		if (i != words.size()-1) { result += delim; }
	}
	return result;
}
	//	}}}
template <typename T>
void printVector(string varname, const vector<T> words, const char delim=' ') {
	//	{{{
	string vector_str = join(words, delim);
	cerr << varname << "=(" << vector_str << ")\n";
}
	//	}}}
template <typename A, typename B>
void printMap(string varname, const map<A,B> m, const char delim=' ') {
	//	{{{
	string m_str = "";
	for (auto const &x: m) {
		m_str += std::to_string(x.first);
		m_str += ":";
		m_str += std::to_string(x.second);
		m_str += delim;
	}
	m_str.pop_back();
	cerr << varname << "=(" << m_str << ")\n";
}
	//	}}}
//	}}}


bool subarray_difference_valid(const vector<int> values)
{
	const int n = 1;
	set<int> values_set(values.begin(), values.end());
	vector<int> values_set_list(values_set.begin(), values_set.end());
	if (values_set_list.size() > n+1) {
		return false;
	}
	if (values_set_list.size() > 1 && abs(values_set_list[0]-values_set_list[1]) > n) {
		return false;
	}
	return true;
}

int pickingNumbers_i(vector<int> a)
{
	stable_sort(a.begin(), a.end());
	vector<int> result_list;
	for (int k = 1; k < a.size(); ++k) {
		for (int l = 0; l < a.size() - k; ++l) {
			int r = l + k;
			vector<int> subarray(a.begin()+l, a.begin()+r+1);
			if (subarray_difference_valid(subarray)) { 
				if (subarray.size() > result_list.size()) {
					result_list = subarray;
				}
			}
		}
	}
	return result_list.size();
}


int pickingNumbers_ii(vector<int> a)
{
	//	a_counts = Counter(a)
	map<int,int> a_counts;
	for (int i = 0; i < a.size(); ++i) {
		if (a_counts.find(a[i]) == a_counts.end()) {
			a_counts[a[i]] = 1;
		} else {
			a_counts[a[i]]++;
		}
	}

	//	nums: unique values from a
	vector<int> nums(a_counts.size());
	int ix = 0;
	for (const auto &x: a_counts) {
		nums[ix] = x.first;
		ix++;
	}
	stable_sort(nums.begin(), nums.end());

	//	possible_values[ {a[,b]} ] = count(a[,b])
	map<vector<int>,int> possible_values;
	int previous = INT_MIN;
	vector<int> k;
	for (const auto &x: nums) {
		k = { x };
		possible_values[k] = a_counts[x];
		if (x-1 == previous) {
			k = { previous, x }; 
			possible_values[k] = a_counts[previous] + a_counts[x];
		}
		previous = x;
	}

	//	result = max(possible_values.values())
	auto result = max_element(possible_values.begin(), possible_values.end(), 
			[](const auto& p1, const auto& p2) 
				{ return p1.second < p2.second; }
		)->second;

	return result;
}


int main()
{
	vector<vector<int>> input_values = { {4,6,5,3,3,1}, {1,2,2,3,1,2}, {98,3,99,1,97,2}, {4,2,3,4,4,9,98,98,3,3,3,4,2,98,1,98,98,1,1,4,98,2,98,3,9,9,3,1,4,1,98,9,9,2,9,4,2,2,9,98,4,98,1,3,4,9,1,98,98,4,2,3,98,98,1,99,9,98,98,3,98,98,4,98,2,98,4,2,1,1,9,2,4}, {84,43,11,41,2,99,31,32,56,53,42,14,98,27,64,57,16,33,48,21,46,61,87,90,28,12,62,49,29,77,82,70,80,89,95,52,13,19,9,79,35,67,51,39,7,1,66,8,17,85,71,97,34,73,75,6,91,40,96,65,37,74,20,68,23,47,76,55,24,3,30,22,55,5,69,86,54,50,10,59,15,4,36,38,83,60,72,63,78,58,88,93,45,18,94,44,92,81,25,26}, {7,12,13,19,17,7,3,18,9,18,13,12,3,13,7,9,18,9,18,9,13,18,13,13,18,18,17,17,13,3,12,13,19,17,19,12,18,13,7,3,3,12,7,13,7,3,17,9,13,13,13,12,18,18,9,7,19,17,13,18,19,9,18,18,18,19,17,7,12,3,13,19,12,3,9,17,13,19,12,18,13,18,18,18,17,13,3,18,19,7,12,9,18,3,13,13,9,7}, {66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66}, {4,97,5,97,97,4,97,4,97,97,97,97,4,4,5,5,97,5,97,99,4,97,5,97,97,97,5,5,97,4,5,97,97,5,97,4,97,5,4,4,97,5,5,5,4,97,97,4,97,5,4,4,97,97,97,5,5,97,4,97,97,5,4,97,97,4,97,97,97,5,4,4,97,4,4,97,5,97,97,97,97,4,97,5,97,5,4,97,4,5,97,97,5,97,5,97,5,97,97,97}, {9,6,13,16,5,18,4,10,3,19,4,5,8,1,13,10,20,17,15,10,6,10,13,20,18,17,7,10,6,5,16,18,13,20,19,7,16,13,20,17,4,17,8,19,12,7,17,1,18,3,16,4,5,3,15,17,6,17,14,11,11,7,11,6,15,15,12,6,17,19,8,6,13,9,10,19,14,18,7,9,11,16,11,20,4,20,10,7,8,4,2,12,11,8,12,13,19,8,8,5}, {14,18,17,10,9,20,4,13,19,19,8,15,15,17,6,5,15,12,18,2,18,7,20,8,2,8,11,2,16,2,12,9,3,6,9,9,13,7,4,6,19,7,2,4,3,4,14,3,4,9,17,9,4,20,10,16,12,1,16,4,15,15,9,13,6,3,8,4,7,14,16,18,20,11,20,14,20,12,15,4,5,10,10,20,11,18,5,20,13,4,18,1,14,3,20,19,14,2,5,13}, };
	vector<int> input_checks = { 3, 5, 2, 22, 3, 30, 100, 50, 13, 15, };
	assert (input_values.size() == input_checks.size());

	vector<function<int(vector<int>)>> test_functions = { pickingNumbers_i, pickingNumbers_ii, };
	vector<string> test_functions_names = { "pickingNumbers_i", "pickingNumbers_ii", };
	int i_test_func = 0;
	for (const auto &test_func: test_functions) {
		cerr << test_functions_names[i_test_func] << ":\n";
		for (int i = 0; i < input_values.size(); ++i) {
			vector<int> &a = input_values[i];
			printVector("a", a);
			int check = input_checks[i];
			cerr << "check=(" << check << ")\n";
			int result = test_func(a);
			cerr << "result=(" << result << ")\n";
			assert (result == check);
		}
		cerr << "\n";
		i_test_func++;
	}

	return 0;
}


