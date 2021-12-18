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
//	ltrim(), rtrim(), split(), join(), printVector(), printMap(), print2DVector()
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
template <typename T>
void print2DVector(string varname, const vector<vector<T>> words, const char delim=' ') {
	//	{{{
	string result = "(";
	for (int i = 0; i < words.size(); ++i) {
		result += "(";
		string loop_result = join(words[i], ',');
		result += loop_result;
		result += ")";
		if (i != words.size()-1) {
			result += ", ";
		}
	}
	result += ")\n";
	cerr << varname << "=" << result;
}
	//	}}}
//	}}}

vector<int> missingNumbers(vector<int> arr, vector<int> brr)
{
	vector<int> result;
	map<int,int> arr_counts;
	for (const auto &x: arr) {
		if (arr_counts.find(x) == arr_counts.end()) {
			arr_counts[x] = 1;
		} else {
			arr_counts[x]++;
		}
	}
	map<int,int> brr_counts;
	for (const auto &x: brr) {
		if (brr_counts.find(x) == brr_counts.end()) {
			brr_counts[x] = 1;
		} else {
			brr_counts[x]++;
		}
	}
	for (const auto& x: brr_counts) {
		int k = x.first; int v = x.second;
		if (arr_counts.find(k) == arr_counts.end() or v > arr_counts[k]) {
			result.push_back(k);
		}
	}
	stable_sort(result.begin(), result.end());
	return result;
}


int main()
{
	vector<pair<vector<int>,vector<int>>> input_values = { {{203,204,205,206,207,208,203,204,205,206},{203,204,204,205,206,207,205,208,203,206,205,206,204}}, {{11,4,11,7,13,4,12,11,10,14},{11,4,11,7,3,7,10,13,4,8,12,11,10,14,12}}, };
	vector<vector<int>> input_checks = { {204,205,206}, {3,7,8,10,12}, };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i < input_values.size(); ++i) {
		vector<int>& arr = input_values[i].first;
		vector<int>& brr = input_values[i].second;
		printVector("arr", arr);
		printVector("brr", brr);
		vector<int>& check = input_checks[i];
		vector<int> result = missingNumbers(arr, brr);
		printVector("result", result);
		assert (result == check);
		cerr << "\n";
	}

	return 0;
}
