//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <numeric>
#include "bits-stdc++.h"
//	{{{2
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void miniMaxSum(vector<int> arr) 
{
	//	Finding max/min/sum 'manually'
	long values_max = LONG_MIN;
	long values_min = LONG_MAX;
	long values_sum = 0;
	for (auto x: arr) {
		if (x > values_max) { values_max = x; }
		if (x < values_min) { values_min = x; }
		values_sum += x;
	}

	//	Using standard library
	values_max = *std::max_element(std::begin(arr), std::end(arr));
	values_min = *std::min_element(std::begin(arr), std::end(arr));
	values_sum = std::accumulate(arr.begin(), arr.end(), 0l);

	//	Print output
	cout << values_sum - values_max << " " << values_sum - values_min << "\n";
}

void test_miniMaxSum(string input_str, string check_str)
{
	stringstream ss_in(input_str);

	string arr_temp_temp;
	getline(ss_in, arr_temp_temp);
	vector<string> arr_temp = split(rtrim(arr_temp_temp));

	vector<int> arr(5);
	for (int i = 0; i < arr.size(); ++i) {
		int arr_item = stoi(arr_temp[i]);
		arr[i] = arr_item;
	}

	streambuf *coutbuf = cout.rdbuf();
	stringstream ss_out;
	cout.rdbuf(ss_out.rdbuf());

	miniMaxSum(arr);

	cout.rdbuf(coutbuf);

	cout << "ss_out.str()=(" << ss_out.str() << ")\n";

	assert (check_str == ss_out.str());
}

int main()
{
	string input_str_i = "1 2 3 4 5\n";
	string check_str_i = "10 14\n";
	test_miniMaxSum(input_str_i, check_str_i);

	string input_str_ii = "256741038 623958417 467905213 714532089 938071625\n";
	string check_str_ii = "2063136757 2744467344\n";
	test_miniMaxSum(input_str_ii, check_str_ii);

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


