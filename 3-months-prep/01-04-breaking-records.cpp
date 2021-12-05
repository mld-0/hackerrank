//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
//	{{{2
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> breakingRecords(vector<int> scores) 
{
	int record_min = scores[0];
	int update_record_min = 0;

	int record_max = scores[0];
	int update_record_max = 0;

	for (int i = 1; i < scores.size(); ++i) {
		int s = scores[i];
		if (s < record_min) {
			record_min = s;
			update_record_min += 1;
		}
		if (s > record_max) {
			record_max = s;
			update_record_max += 1;
		}
	}

	return { update_record_max, update_record_min };
}

void test_breakingRecords(string input_str, string check_str)
{
	stringstream ss_in(input_str);
	
	int n; 
	ss_in >> n;

	vector<int> scores(n);
	for (int i = 0; i < n; ++i) {
		ss_in >> scores[i];
	}

	cout << "scores=(";
	for (int i = 0; i < scores.size(); ++i) { 
		cout << scores[i]; if (i != scores.size()-1) { cout << " "; }
	}
	cout << ")\n";

	vector<int> result = breakingRecords(scores);
	cout << "result=(";
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i]; if (i != result.size()-1) { cout << " "; }
	}
	cout << ")\n";

	vector<string> check_str_split = split(check_str);
	vector<int> check;
	for (auto x: check_str_split) {
		check.push_back(stoi(x));
	}

	cout << "check=(";
	for (int i = 0; i < check.size(); ++i) {
		cout << check[i]; if (i != check.size()-1) { cout << " "; } 
	}
	cout << ")\n";

	assert (result == check);
}

int main()
{
	string input_str_i = "9\n10 5 20 20 4 5 2 25 1\n";
	string check_str_i = "2 4\n";
	test_breakingRecords(input_str_i, check_str_i);
	cout << "\n";

	string input_str_ii = "10\n3 4 21 36 10 28 35 5 24 42\n";
	string check_str_ii = "4 0\n";
	test_breakingRecords(input_str_ii, check_str_ii);
	cout << "\n";
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

vector<string> split(const string &str) {
//	{{{
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
//	}}}


