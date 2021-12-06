//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;
//	{{{2

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &, const char);

/*	Find the integer which occurs only once in 'a', or return -1 if not found */
int lonelyinteger(vector<int> a) 
{
	//	map<int,int> 'a_counter' = Counter(a)
	map<int,int> a_counter;
	for (int i = 0; i != a.size(); ++i) {
		if (a_counter.find(a[i]) == a_counter.end()) {
			a_counter[a[i]] = 1;
		} else {
			a_counter[a[i]] += 1;
		}
	}

	//	Print 'a_counter'
	cerr << "a_counter=(";
	int ix = 0;
	for (const auto &x: a_counter) {
		cerr << x.first << ":" << x.second;
		if (ix++ != a_counter.size()-1) { cerr << ", "; }
	}
	cerr << ")\n";

	//	Return key from 'a_counter' corresponding to 1 value
	for (const auto &x: a_counter) {
		if (x.second == 1) {
			return x.first;
		}
	}

	return -1;
}


void test_lonelyinteger(string input_str, string check_str)
{
	stringstream ss_in(input_str);
	int n;
	ss_in >> n;
	ss_in.ignore(1, '\n');

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		ss_in >> a[i];
	}
	
	cerr << "a=(";
	for (int i = 0; i < a.size(); ++i) {
		cerr << a[i]; if (i != a.size()-1) { cerr << " "; }
	}
	cerr << ")\n";

	int check = stoi(rtrim(check_str));
	cerr << "check=(" << check << ")\n";

	int result = lonelyinteger(a);
	cerr << "result=(" << result << ")\n";

	assert (result == check);
}

int main()
{
	vector<string> input_values = { "1\n1\n", "3\n1 1 2\n", "7\n1 2 3 4 3 2 1\n", "5\n0 0 1 2 1\n", };
	vector<string> input_checks = { "1\n", "2\n", "4\n",  "2\n", };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i < input_values.size(); ++i) {
		string input_str = input_values[i];
		string check_str = input_checks[i];
		test_lonelyinteger(input_str, check_str);
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
    while ((end = str.find(delim, start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
//	}}}

