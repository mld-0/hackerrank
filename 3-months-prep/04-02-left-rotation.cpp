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

vector<int> rotateLeft_i(int d, vector<int> arr) 
{
	while (d > arr.size()) {
		d -= arr.size();
	}

	vector<int> result(arr.size());
	int i_result = 0;

	for (int i = d; i < arr.size(); ++i) {
		result[i_result++] = arr[i];
	}
	for (int i = 0; i < d; ++i) {
		result[i_result++] = arr[i];
	}

	return result;
}

vector<int> rotateLeft_ii(int d, vector<int> arr)
{
	rotate(arr.begin(), arr.begin()+d, arr.end());
	return arr;
}


int main()
{
	vector<pair<int,vector<int>>> input_values = { {4, {1,2,3,4,5}}, {10, {41,73,89,7,10,1,59,58,84,77,77,97,58,1,86,58,26,10,86,51}}, {7, {98,67,35,1,74,79,7,26,54,63,24,17,32,81}}, {48, {431,397,149,275,556,362,852,789,601,357,516,575,670,507,127,888,284,405,806,27,495,879,976,467,342,356,908,750,769,947,425,643,754,396,653,595,108,75,347,394,935,252,683,966,553,724,629,567,93,494,693,965,328,187,728,389,70,288,509,252,449}}, {2, {344,210,102}}, };
	vector<vector<int>> input_checks = { {5,1,2,3,4}, {77,97,58,1,86,58,26,10,86,51,41,73,89,7,10,1,59,58,84,77}, {26,54,63,24,17,32,81,98,67,35,1,74,79,7}, {93,494,693,965,328,187,728,389,70,288,509,252,449,431,397,149,275,556,362,852,789,601,357,516,575,670,507,127,888,284,405,806,27,495,879,976,467,342,356,908,750,769,947,425,643,754,396,653,595,108,75,347,394,935,252,683,966,553,724,629,567}, {102,344, 210}, };
	assert (input_values.size() == input_checks.size());

	vector<std::function<vector<int>(int,vector<int>)>> test_functions = { rotateLeft_i, rotateLeft_ii, };
	vector<string> test_functions_names = { "rotateLeft_i", "rotateLeft_ii", };
	assert (test_functions.size() == test_functions_names.size());

	int i_test_func = 0;
	for (const auto &test_func: test_functions) {
		cerr << test_functions_names[i_test_func++] << ":\n";
		for (int i = 0; i < input_values.size(); ++i) {
			const vector<int> &arr = input_values[i].second;
			printVector("arr", arr);

			const int &d = input_values[i].first;
			cerr << "d=(" << d << ")\n";

			const vector<int> &check = input_checks[i];
			printVector("check", check);

			vector<int> result = test_func(d, arr);
			printVector("result", result);

			assert (result == check);
		}
		cerr << "\n";
	}

}

