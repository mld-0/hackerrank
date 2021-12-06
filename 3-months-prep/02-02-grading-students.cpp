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

int roundGrade(int grade)
{
	if (grade < 38) {
		return grade;
	}
	int nearest_mutiple_5 = grade;
	while ((nearest_mutiple_5 % 5) != 0) {
		nearest_mutiple_5 += 1;
	}
	if (nearest_mutiple_5 - grade < 3) {
		return nearest_mutiple_5;
	} else {
		return grade;
	}
}

vector<int> gradingStudents(vector<int> grades) 
{
	vector<int> result(grades.size());

	int ix = 0;
	for (const auto &x: grades) {
		result[ix] = roundGrade(x);
		ix += 1;
	}

	return result;
}

int main()
{
	vector<vector<int>> input_values = { {73, 67, 38, 33}, {37, 38}, {80, 96, 18, 73, 78, 60, 60, 15, 45, 15, 10, 5, 46, 87, 33, 60, 14, 71, 65, 2, 5, 97, 0}, };
	vector<vector<int>> input_checks = { {75, 67, 40, 33}, {37, 40}, {80, 96, 18, 75, 80, 60, 60, 15, 45, 15, 10, 5, 46, 87, 33, 60, 14, 71, 65, 2, 5, 97, 0}, };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i < input_values.size(); ++i) {
		vector<int> grades = input_values[i];
		vector<int> check = input_checks[i];
		printVector("grades", grades);
		printVector("check", check);

		vector<int> result = gradingStudents(grades);
		printVector("result", result);

		assert (result == check);
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


