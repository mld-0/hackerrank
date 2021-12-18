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

//    Return the minimum number of characters needed to make the password strong
int minimumNumber(int n, string password)
{
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";

    //   length at least 6
    int needed_length = 6 - n;

    bool needs_digit = true;
    bool needs_lower = true;
    bool needs_upper = true;
    bool needs_special = true;

	//	at least 1 digit
	for  (const auto &c: numbers) {
		if (password.find(c) != string::npos) {
			needs_digit = false;
		}
	}
	//    at least 1 lower
	for (const auto &c: lower_case) {
		if (password.find(c) != string::npos) {
			needs_lower = false;
		}
	}
	//    at least 1 upper
	for (const auto &c: upper_case) {
		if (password.find(c) != string::npos) {
			needs_upper = false;
		}
	}
	//    at least 1 special
	for (const auto &c: special_characters) {
		if (password.find(c) != string::npos) {
			needs_special = false;
		}
	}

    int needed_categories = 0;

	if (needs_digit) {
		needed_categories++;
	}
	if (needs_lower) {
		needed_categories++;
	}
	if (needs_upper) {
		needed_categories++;
	}
	if (needs_special) {
		needed_categories++;
	}

	int result = max(needed_length, needed_categories);
	return result;
}


int main()
{
	vector<pair<int,string>> input_values = { {3,"Ab1"}, {11, "#HackerRank"}, {1, "9"}, {1, "z"}, {1, "A"}, {3, "0H2"}, {3, "a4A"}, {5, "A98#+"}, {100, "espUIjGnwLfHyiCqATSqBzkTOGNZTzbVCewFJrguXzjFzjChkpqZUXntPqxVAZTvkydYHYvXdVFIYxfxHwjvAFNyrJZpjBCYSCto", }, {100, "DZ*1G!#0%(73$7599@851K#208M5+0JQ-P8!*07B1YL89$31$21B(0*K0X))LFK2)Q0&X0VPT974X68@3%9Z!DUQ2LH-&3G1+9&5"}, };
	vector<int> input_checks = { 3, 1, 5, 5, 5, 3, 3, 1, 2, 1, };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i < input_values.size(); ++i) {
		int n = input_values[i].first;
		string s = input_values[i].second;
		cerr << "n=(" << n << "), s=(" << s << ")\n";
		int check = input_checks[i];
		int result = minimumNumber(n, s);
		cerr << "result=(" << result << ")\n";
		assert (result == check);
		cerr << "\n";
	}

	return 0;
}

