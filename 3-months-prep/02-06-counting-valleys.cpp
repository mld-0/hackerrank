//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
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


int countingValleys(int steps, string path) 
{
	int count_valleys = 0;
	int current_height = 0;
	int previous_height = 0;

	for (char const &x: path) {
		previous_height = current_height;
		if (x == 'D') {
			current_height -= 1;
		} else if (x == 'U') {
			current_height += 1;
		}

		if (previous_height == 0 && current_height < 0) {
			count_valleys += 1;
		}
	}

	return count_valleys;
}


int main()
{
	vector<tuple<int,string>> input_values = { {8,"UDDDUDUU"}, {12,"DDUUDDUDUUUD"}, };
	vector<int> input_checks = { 1, 2, };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i < input_values.size(); ++i) {
		int steps = get<0>(input_values[i]);
		string path = get<1>(input_values[i]);
		int check = input_checks[i];

		cerr << "steps=(" << steps << "), path=(" << path << ")\n";
		cerr << "check=(" << check << ")\n";
		
		int result = countingValleys(steps, path);
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



