//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
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

int birthday(vector<int> s, int d, int m) 
{
	vector<vector<int>> results = {};
	for (int k = 0; k < s.size()-m+1; ++k) {
		vector<int> loop_group(s.begin()+k, s.begin()+k+m);
		int loop_group_sum = accumulate(loop_group.begin(), loop_group.end(), 0);
		if (loop_group_sum == d) {
			results.push_back(loop_group);
		}
	}
	return results.size();
}

int main()
{
	vector<tuple<vector<int>,int,int>> input_values = { {{1,1,1,1,1,1}, 3, 2}, {{1,2,1,3,2}, 3, 2}, {{4}, 4, 1}, };
	vector<int> input_checks = { 0, 2, 1, };
	assert(input_values.size() == input_checks.size());

	for (int i = 0; i < input_values.size(); ++i) {
		vector<int> s = get<0>(input_values[i]);
		int d = get<1>(input_values[i]);
		int m = get<2>(input_values[i]);

		printVector("s", s);
		cerr << "d=(" << d << "), m=(" << m << ")\n";

		int check = input_checks[i];
		cerr << "check=(" << check << ")\n";

		int result = birthday(s, d, m);
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





