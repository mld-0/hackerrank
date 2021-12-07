//	VEER SETTINGS: {{{3
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


string pangrams(string s) 
{
	for_each(s.begin(), s.end(), [](char &c) { c = ::tolower(c); });

	map<char,int> count_letters;
	for (char const &x: s) {
		if (isspace(x)) {
			continue;
		}
		if (count_letters.find(x) == count_letters.end()) {
			count_letters[x] += 1;
		} else {
			count_letters[x] = 1;
		}
	}

	for (char c = 'a'; c <= 'z'; ++c) {
		if (count_letters.find(c) == count_letters.end()) {
			return "not pangram";
		}
	}

	return "pangram";
}

int main()
{
	vector<string> input_values = { "We promptly judged antique ivory buckles for the next prize", "We promptly judged antique ivory buckles for the prize", };
	vector<string> input_checks = { "pangram", "not pangram", };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i < input_values.size(); ++i) { 
		string s = input_values[i];
		string check = input_checks[i];

		cerr << "s=(" << s << ")\n";
		cerr << "check=(" << check << ")\n";

		string result = pangrams(s);
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



