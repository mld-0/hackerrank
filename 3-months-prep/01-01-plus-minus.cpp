//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <cassert>
#include "bits-stdc++.h"
using namespace std;
//	{{{2

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void plusMinus(vector<int> arr) 
{
	int count_positive = 0;
	int count_negative = 0;

	for (auto &x : arr) {
		if (x > 0) {
			count_positive++;
		} else if (x < 0) {
			count_negative++;
		}
	}

	int count_zero = arr.size() - (count_positive + count_negative);

	double ratio_positive = static_cast<double>(count_positive) / static_cast<double>(arr.size());
	double ratio_negative = static_cast<double>(count_negative) / static_cast<double>(arr.size());
	double ratio_zero = static_cast<double>(count_zero) / static_cast<double>(arr.size());

	cout << std::setprecision(6) << std::fixed;
	cout << ratio_positive << "\n";
	cout << ratio_negative << "\n";
	cout << ratio_zero << "\n";
}

void test_plusMinus(string input_str, string check_str)
{
	stringstream ss_in;
	ss_in.str(input_str);

	string n_temp;
	getline(ss_in, n_temp);
	int n = stoi(ltrim(rtrim(n_temp)));

	string arr_temp_temp;
	getline(ss_in, arr_temp_temp);
	vector<string> arr_temp = split(rtrim(arr_temp_temp));

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		int arr_item = stoi(arr_temp[i]);
		arr[i] = arr_item;
	}

	std::streambuf *coutbuf = std::cout.rdbuf();
	stringstream ss_out;
	std::cout.rdbuf(ss_out.rdbuf());

	plusMinus(arr);

	std::cout.rdbuf(coutbuf);

	//	TODO: 2021-12-05T17:48:37AEDT compare ss_out to check_str (moar properly)
	cout << "ss_out.str()=(" << ss_out.str() << ")\n";

	assert (check_str == ss_out.str());
}

int main()
{
	string input_str_i = "6\n-4 3 -9 0 4 1";
	string check_str_i = "0.500000\n0.333333\n0.166667\n";

	test_plusMinus(input_str_i, check_str_i);

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

