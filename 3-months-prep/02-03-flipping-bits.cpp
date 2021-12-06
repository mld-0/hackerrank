//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <map>
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


long flippingBits(long n)
{
	//	UINT_MAX = 0xFFFFFFFF, whereas ULONG_MAX does not (both for g++ on Minerva, and hackerrank)
	//return (n ^ UINT_MAX);
	return (n ^ 0xFFFFFFFF);
}


int main()
{
	vector<vector<long>> input_values = { {2147483647, 1, 0}, };
	vector<vector<long>> input_checks = { {2147483648, 4294967294, 4294967295}, };
	assert (input_values.size() == input_checks.size() );

	for (int i = 0; i < input_values.size(); ++i) {
		vector<long> &loop_values = input_values[i];
		vector<long> &loop_check = input_checks[i];
		assert (loop_values.size() == loop_check.size());

		vector<long> loop_results(loop_values.size());
		for (int j = 0; j < loop_values.size(); ++j) {
			long value = loop_values[j];
			long check = loop_check[j];

			long result = flippingBits(value);
			loop_results[j] = result;
		}

		printVector("loop_values", loop_values);
		printVector("loop_check", loop_check);
		printVector("loop_results", loop_results);
		cerr << "\n";
	}

	return 0;
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

