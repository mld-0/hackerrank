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

string gridChallenge(vector<string> grid)
{
	//	Sort letters in each row
	for (auto& x: grid) {
		stable_sort(x.begin(), x.end());
	}
	//	Convert vector<string> to vector<vector<char>>
	vector<vector<char>> grid_letters;
	for (auto& x: grid) {
		vector<char> temp;
		copy(x.begin(), x.end(), back_inserter(temp));
		grid_letters.push_back(temp);
	}
	//	Transpose grid_letters
	vector<vector<char>> grid_letters_T;
	for (int col = 0; col < grid_letters[0].size(); ++col) {
		grid_letters_T.push_back( {} );
		for (int row = 0; row < grid_letters.size(); ++row) {
			char temp = grid_letters[row][col];
			grid_letters_T[col].push_back(temp);
		}
	}
	//	Convert vector<vector<char>> to vector<string>
	vector<string> grid_T;
	for (auto& x: grid_letters_T) {
		string temp(x.begin(), x.end());
		grid_T.push_back(temp);
	}
	//	Sort letters of each row
	vector<string> grid_T_sorted(grid_T.begin(), grid_T.end());
	for (auto& x: grid_T_sorted) {
		stable_sort(x.begin(), x.end());
	}
	//	Were rows of grid_T already sorted?
	if (grid_T == grid_T_sorted) {
		return "YES";
	}
	return "NO";
}


int main()
{
	vector<vector<string>> input_values = { {"eabcd", "fghij", "olkmn", "trpqs", "xywuv"}, {"abc", "lmp", "qrt"}, {"mpxz", "abcd", "wlmf"}, {"abc", "hjk", "mpq", "rtv"}, };
	vector<string> input_checks = { "YES", "YES", "NO", "YES", };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i < input_values.size(); ++i) {
		vector<string>& grid = input_values[i];
		printVector("grid", grid);
		string check = input_checks[i];
		string result = gridChallenge(grid);
		cerr << "result=(" << result << ")\n";
		assert (result == check);
		cerr << "\n";
	}

	return 0;
}
