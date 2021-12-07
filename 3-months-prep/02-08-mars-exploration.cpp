//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>
#include <sstream>
#include <climits>
#include <cassert>
using namespace std;
//	{{{2

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &, const char);
template <typename T>
string join(const vector<T>, const char);
template <typename T>
void printVector(string varname, const vector<T> words, const char delim=' ');


int marsExploration(string s)
{
	int result = 0;

	string expected_single = "SOS";
	string expected;
	for (int i = 0; i < s.size() / 3; ++i) {
		expected += expected_single;
	}
	cerr << "expected=(" << expected << ")\n";

	assert (expected.size() == s.size());
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		char x = expected[i];

		if (c != x) {
			result++;
		}
	}

	return result;
}

int main()
{
	vector<string> input_values = { "SOSSPSSQSSOR", "SOSSOT", "SOSSOSSOS", };
	vector<int> input_checks = { 3, 1, 0, };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i != input_values.size(); ++i) {
		string s = input_values[i];
		int check = input_checks[i];
		cerr << "s=(" << s << "), check=(" << check << ")\n";

		int result = marsExploration(s);
		cerr << "result=(" << result << ")\n";

		assert (result == check);
		cerr << "\n";
	}

}


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

vector<string> split(const string &str, const char delim) {
//	{{{
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    //while ((end = str.find(" ", start)) != string::npos) {
    while ((end = str.find(delim, start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
//	}}}

template <typename T>
string join(const vector<T> words, const char delim) {
	//	{{{
	string result = "";
	for (int i = 0; i < words.size(); ++i) {
		result += to_string(words[i]);
		if (i != words.size()-1) { result += delim; }
	}
	return result;
}
	//	}}}

template <typename T>
void printVector(string varname, const vector<T> words, const char delim) {
	//	{{{
	string vector_str = join(words, delim);
	cerr << varname << "=(" << vector_str << ")\n";
}
	//	}}}




