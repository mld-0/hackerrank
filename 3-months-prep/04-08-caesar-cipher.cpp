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

//	Convert char -> int to prevent any issues with overflow when rotating

string caesarCipher(string s, int k)
{
	string result(s);
	for (char &x: result) {
		int x_code = (int) x;
		if (isalpha(x)) {
			if (isupper(x)) {
				x_code += k;
				while (x_code > 'Z') {
					x_code -= 26;
				}
			} else if (islower(x)) {
				x_code += k;
				while (x_code > 'z') {
					x_code -= 26;
				}
			}
		}
		x = (char) x_code;
	}
	return result;
}


int main()
{
	vector<function<string(string,int)>> test_functions = { caesarCipher, };
	vector<string> test_functions_names = { "caesarCipher", };
	assert (test_functions.size() == test_functions_names.size());

	vector<pair<string,int>> input_values = { {"middle-Outz", 2}, {"Always-Look-on-the-Bright-Side-of-Life", 5}, {"Ciphering.", 26}, {"www.abc.xy", 87}, };
	vector<string> input_checks = { "okffng-Qwvb", "Fqbfdx-Qttp-ts-ymj-Gwnlmy-Xnij-tk-Qnkj", "Ciphering.", "fff.jkl.gh", };
	assert (input_values.size() == input_checks.size());

	int test_func_i = 0;
	for (const auto& test_func: test_functions) {
		cerr << test_functions_names[test_func_i++] << ":\n";
		for (int i = 0; i < input_values.size(); ++i) {
			string s = input_values[i].first;
			int k = input_values[i].second;
			cerr << "s=(" << s << "), k=(" << k << ")\n";
			string check = input_checks[i];
			string result = test_func(s, k);
			cerr << "result=(" << result << ")\n";
			assert (result == check);
		}
		cerr << "\n";
	}

	return 0;
}

