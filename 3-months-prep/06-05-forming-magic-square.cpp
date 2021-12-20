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

vector<vector<vector<int>>> possible_magic_squares = { 
    {{8,1,6},{3,5,7},{4,9,2}},
    {{6,1,8},{7,5,3},{2,9,4}}, 
    {{4,9,2},{3,5,7},{8,1,6}},
    {{2,9,4},{7,5,3},{6,1,8}},
    {{8,3,4},{1,5,9},{6,7,2}},
    {{4,3,8},{9,5,1},{2,7,6}},
    {{6,7,2},{1,5,9},{8,3,4}},
    {{2,7,6},{9,5,1},{4,3,8}},
};

bool is_magic_square(vector<vector<int>> square)
{
	for (const auto& row: square) {
		if (row.size() != square.size()) {
			throw domain_error("square is not square");
		}
	}
	int expected = 15;
	for (int row = 0; row < square.size(); ++row) {
		int total = 0;
		for (int col = 0; col < square[0].size(); ++col) {
			total += square[row][col];
		}
		if (total != expected) {
			return false;
		}
	}
	for (int col = 0; col < square[0].size(); ++col) {
		int total = 0;
		for (int row = 0; row < square.size(); ++row) {
			total += square[row][col];
		}
		if (total != expected) {
			return false;
		}
	}
	return true;
}

int square_transform_cost(vector<vector<int>> square_to, vector<vector<int>> square_from)
{
	if (square_to.size() != square_from.size()) {
		throw domain_error("square_to, square_from length mismatch");
	}
	for (int i = 0; i < square_to.size(); ++i) {
		if (square_to[i].size() != square_to.size()) { 
			throw domain_error("square_to is not square"); 
		}
		if (square_from[i].size() != square_from.size()) { 
			throw domain_error("square_from is not square"); 
		}
	}
	int distance = 0;
	for (int row = 0; row < square_to.size(); ++row) {
		for (int col = 0; col < square_to[0].size(); ++col) {
			distance += abs(square_to[row][col] - square_from[row][col]);
		}
	}
	return distance;
}

int formingMagicSquare(vector<vector<int>> square) 
{
	int result = INT_MAX;
	for (const auto& square_from: possible_magic_squares) {
		int trial = square_transform_cost(square, square_from);
		result = min(result, trial);
	}
	return result;
}


int main()
{
	vector<vector<vector<int>>> input_values = { {{4,9,2},{3,5,7},{8,1,5}}, {{4,8,2},{4,5,7},{6,1,6}}, };
	vector<int> input_checks = { 1, 4, };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i < input_values.size(); ++i) {
		vector<vector<int>>& square = input_values[i];
		print2DVector("square", square);
		int check = input_checks[i];
		int result = formingMagicSquare(square);
		cerr << "result=(" << result << ")\n";
		assert (result == check);
		cerr << "\n";
	}

	return 0;
}

