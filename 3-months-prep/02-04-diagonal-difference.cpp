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
template <typename T>
void printGridVector(string varname, const vector<vector<T>> grid, const char delim=' ');


/*	Calculate the absolute difference between the sums of the diagonals of 'arr' */
int diagonalDifference(vector<vector<int>> arr)
{
	int LR = 0;
	int RL = 0;
	for (int i = 0; i < arr.size(); ++i) {
		RL += arr[i][i];
		LR += arr[arr.size()-i-1][i];
	}
	return abs(RL - LR);
}


int main()
{
	vector<vector<vector<int>>> input_values = { {{11,2,4},{4,5,6},{10,8,-12}}, {{-1,1,-7,-8},{-10,-8,-5,-2},{0,9,7,-1},{4,4,-2,1}}, };
	vector<int> input_checks = { 15, 1, };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i != input_values.size(); ++i) {
		vector<vector<int>> &loop_values = input_values[i];
		int loop_check = input_checks[i];
		printGridVector("loop_values", loop_values);
		cerr << "loop_check=(" << loop_check << ")\n";

		int result = diagonalDifference(loop_values);
		cerr << "result=(" << result << ")\n";

		assert (result == loop_check);

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

template <typename T>
void printGridVector(string varname, const vector<vector<T>> grid, const char delim) {
	//	{{{
	cerr << varname << ":\n";
	for (int i = 0; i != grid.size(); ++i) {
		const vector<T> &loop_row = grid[i];
		string line = join(loop_row, delim);
		cerr << line << "\n";
	}
}
	//	}}}

