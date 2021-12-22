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
string join(const vector<string> words, const char delim=' ') {
	//	{{{
	string result = "";
	for (int i = 0; i < words.size(); ++i) {
		result += words[i];
		if (i != words.size()-1) { result += delim; }
	}
	return result;
}
	//	}}}
string join(const vector<char> words, const char delim=' ') {
	//	{{{
	string result = "";
	for (int i = 0; i < words.size(); ++i) {
		result += words[i];
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

string isValid_i(string s)
{
	//	s_counts[letter] = count-value
	map<char,int> s_counts;
	for (const auto& x: s) {
		if (s_counts.find(x) == s_counts.end()) {
			s_counts[x] = 1;
		} else {
			s_counts[x]++;
		}
	}

	//	s_counts_counts[count-value] = frequency-of-count-value
	map<int,int> s_counts_counts;
	for (const auto& x: s_counts) {
		if (s_counts_counts.find(x.second) == s_counts_counts.end()) {
			s_counts_counts[x.second] = 1;
		} else {
			s_counts_counts[x.second]++;
		}
	}

	//	Only 1 count-value, word is valid without deletions
	if (s_counts_counts.size() == 1) {
		return "YES";
	}

	//	More than 2 count-values, word is not valid with any single deletion
	if (s_counts_counts.size() > 2) {
		return "NO";
	}

	//	s_counts_freq: [ (count-value, frequency-of-count-value), ]
	//	sorted by frequency-of-count-value, descending
	vector<pair<int,int>> s_counts_freq;
	for (const auto& x: s_counts_counts) {
		s_counts_freq.push_back( { x.first, x.second } );
	}
	stable_sort(s_counts_freq.begin(), s_counts_freq.end(), 
			[](const pair<int,int>& a, const pair<int,int>& b) {
				return a.second > b.second;
			});

	//	The less-frequent count-value must occur once, and it must eithe be 1 (letter disappears with deletion), or 1 more than value of more-frequent count (count-values become same upon deletion)
	if ((s_counts_freq[0].first == s_counts_freq[1].first - 1 || s_counts_freq[1].first == 1) && s_counts_freq[1].second == 1) {
		return "YES";
	} else {
		return "NO";
	}
}

string isValid_ii(string s)
{
	map<char,int> hash;
	for (const auto& i: s) {
		if (hash.find(i) == hash.end()) {
			hash[i] = 1;
		} else {
			hash[i]++;
		}
	}
	map<int,int> hash2;
	for (const auto& item: hash) {
		if (hash2.find(item.second) == hash2.end()) {
			hash2[item.second] = 1;
		} else {
			hash2[item.second]++;
		}
	}
	if (hash2.size() == 1) {
		return "YES";
	}
	if (hash2.size() > 2) {
		return "NO";
	}
	if (hash2.size() == 2) {
		vector<int> hash2_keys;
		for (const auto& x: hash2) {
			hash2_keys.push_back(x.first);
		}
		int hash2_keys_max = *max_element(hash2_keys.begin(), hash2_keys.end());
		int hash2_keys_min = *min_element(hash2_keys.begin(), hash2_keys.end());
		if (hash2[hash2_keys_max] == 1 && hash2_keys_max - hash2_keys_min == 1) {
			return "YES";
		} else if (hash2[hash2_keys_min] == 1) {
			return "YES";
		}
	}
	return "NO";
}

int main()
{
	vector<std::function<string(string)>> test_functions = { isValid_i, isValid_ii, };
	vector<string> test_functions_names = { "isValid_i", "isValid_ii", };
	assert (test_functions.size() == test_functions_names.size());

	vector<string> input_values = { "aabbc", "aabbcd", "aabbccddeefghi", "abcdefghhgfedecba", };
	vector<string> input_checks = { "YES", "NO", "NO", "YES", };
	assert (input_values.size() == input_checks.size());

	int test_func_i = 0;
	for (const auto &test_func: test_functions) {
		cerr << test_functions_names[test_func_i++] << "\n";
		for (int i = 0; i < input_values.size(); ++i) {
			string s = input_values[i];
			string check = input_checks[i];
			cerr << "s=(" << s << ")\n";
			string result = test_func(s);
			cerr << "result=(" << result << ")\n";
			assert (result == check);
		}
		cerr << "\n";
	}

	return 0;
}

