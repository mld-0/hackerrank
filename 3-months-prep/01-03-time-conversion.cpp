//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <numeric>
#include <cassert>
#include "bits-stdc++.h"
//	{{{2
using namespace std;

string timeConversion(string s) 
{
	string time_range = s.substr(s.size()-2, s.size());

	int time_H = stoi(s.substr(0,2));
	int time_M = stoi(s.substr(3,5));
	int time_S = stoi(s.substr(6,8));

	if (time_range == "PM" && time_H != 12) {
		time_H = time_H + 12;
	} else if (time_range == "AM" and time_H == 12) {
		time_H = 0;
	}

	//	Using sprintf()
	char BUFFER[1024];
	sprintf(BUFFER, "%02i:%02i:%02i", time_H, time_M, time_S);
	string result_str_i(BUFFER);

	//	Using stringstream
	stringstream ss;
	ss << setfill('0') << setw(2) << time_H << ":";
	ss << setfill('0') << setw(2) << time_M << ":";
	ss << setfill('0') << setw(2) << time_S;
	string result_str_ii = ss.str();

	assert (result_str_i == result_str_ii);

	return result_str_i;
}

void test_timeConversion(string input_str, string check_str)
{
	string result = timeConversion(input_str);
	cout << "result=(" << result << ")\n";
	assert (result == check_str);
}

int main()
{
	vector<string> input_values = { "07:05:45PM", "12:40:22AM", "06:40:03AM", "12:05:39AM", };
	vector<string> input_checks = { "19:05:45", "00:40:22", "06:40:03", "00:05:39", };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i != input_values.size(); ++i) {
		test_timeConversion(input_values.at(i), input_checks.at(i));
	}

}


