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


string twoArrays(int k, vector<int> A, vector<int> B)
{
	stable_sort(A.begin(), A.end());
	stable_sort(B.begin(), B.end());
	reverse(B.begin(), B.end());
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] + B[i] < k) {
			return "NO";
		}
	}
	return "YES";
}

int main()
{
	vector<tuple<int,vector<int>,vector<int>>> input_values = { {10,{2,1,3},{7,8,9}}, {5,{1,2,2,1},{3,3,3,4}}, };
	vector<string> input_checks = { "YES", "NO", };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i < input_values.size(); ++i) {
		int k = get<0>(input_values[i]);
		vector<int> A = get<1>(input_values[i]);
		vector<int> B = get<2>(input_values[i]);
		assert(A.size() == B.size());

		cerr << "k=(" << k << ")\n";
		printVector("A", A);
		printVector("B", B);

		string check = input_checks[i];
		cerr << "check=(" << check << ")\n";

		string result = twoArrays(k, A, B);
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




