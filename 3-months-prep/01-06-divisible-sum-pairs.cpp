//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;
//	{{{2

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &, const char);


int divisibleSumPairs(int n, int k, vector<int> ar)
{
	int result_count = 0;

	for (int l = 0; l != ar.size()-1; ++l) {
		for (int r = l+1; r != ar.size(); ++r) {
			int a = ar[l];
			int b = ar[r];
			int sum = a + b;
			int mod = sum % k;

			cerr << "a=(" << a << "), b=(" << b << "), sum=(" << sum << "), mod=(" << mod << ")\n";

			if (mod == 0) {
				result_count++;
			}
		}
	}

	return result_count;
}

void test_divisibleSumPairs(string input_str, string check_str)
{
	int n;
	int k;

	stringstream ss_in(input_str);
	ss_in >> n;
	ss_in >> k;
	ss_in.ignore(1, '\n');

	string ar_str;
	getline(ss_in, ar_str);

	vector<string> ar_str_split = split(rtrim(ar_str), ' ');
	vector<int> ar(n);
	for (int i = 0; i < n; ++i) { 
		int temp = stoi(ar_str_split[i]);
		ar[i] = temp;
	}

	cerr << "n=(" << n << "), k=(" << k << ")\n";
	cerr << "ar=(";
	for (int i = 0; i < ar.size(); ++i) {
		cerr << ar[i]; if (i != ar.size()-1) { cerr << " "; }
	}
	cerr << ")\n";

	int result = divisibleSumPairs(n, k, ar);

	int check;
	stringstream ss_check(check_str);
	ss_check >> check;

	cerr << "result=(" << result << ")\n";
	cerr << "check=(" << check << ")\n";

	assert (result == check);
}

int main()
{
	vector<string> input_values = { "6 3\n1 3 2 6 1 2\n", "5 2\n5 9 10 7 4\n", "2 2\n8 10\n", };
	vector<string> input_checks = { "5\n", "4\n", "1\n", };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i != input_values.size(); ++i) { 
		string input_str = input_values[i];
		string check_str = input_checks[i];
		test_divisibleSumPairs(input_str, check_str);
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


