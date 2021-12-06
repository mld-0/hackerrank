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

vector<int> matchingStrings(vector<string> strings, vector<string> queries)
{
	vector<int> result(queries.size());

	//	Get map<string,int> 'strings_counter' = Counter(strings)
	map<string,int> strings_counter;
	for (const auto &x : strings) {
		if (strings_counter.find(x) == strings_counter.end()) {
			strings_counter[x] = 1;
		} else {
			strings_counter[x] += 1;
		}
	}

	//	Print map<string,int> 'strings_counter'
	cerr << "strings_counter=(";
	int ix = 0;
	for (const auto &x : strings_counter) {
		cerr << x.first << ":" << x.second;
		if (ix++ != strings_counter.size()-1) { cerr << ", "; }
	}
	cerr << ")\n";

	//	Fill vector<int> 'result'
	for (int i = 0; i != queries.size(); ++i) {
		string loop_query = queries[i];
		if (strings_counter.find(loop_query) != strings_counter.end()) {
			result[i] = strings_counter[loop_query];
		} else {
			result[i] = 0;
		}
	}

	return result;
}


void test_matchingStrings(string input_str, string check_str)
{
	stringstream ss_in(input_str);

	//	Read search strings to vector<string> 'strings'
	int strings_count;
	ss_in >> strings_count;
	ss_in.ignore(1, '\n');
	vector<string> strings(strings_count);
	for (int i = 0; i < strings_count; ++i) {
		string temp;
		getline(ss_in, temp);
		strings[i] = temp;
	}

	//	Read query strings to vector<string> 'queries'
	int queries_count;
	ss_in >> queries_count;
	ss_in.ignore(1, '\n');
	vector<string> queries(queries_count);
	for (int i = 0; i < queries_count; ++i) { 
		string temp;
		getline(ss_in, temp);
		queries[i] = temp;
	}

	//	Read check values to vector<int> 'check'
	vector<string> check_str_split = split(rtrim(check_str), '\n');
	vector<int> check(check_str_split.size());
	for (int i = 0; i < check_str_split.size(); ++i) {
		int temp = stoi(check_str_split[i]);
		check[i] = temp;
	}

	//	Print vectors 'strings', 'queries', 'check'
	cerr << "strings_count=(" << strings_count << ")\n";
	cerr << "strings=(";
	for (int i = 0; i < strings.size(); ++i) {
		cerr << strings[i]; if (i != strings.size()-1) { cerr << " "; }
	}
	cerr << ")\n";
	cerr << "queries_count=(" << queries_count << ")\n";
	cerr << "queries=(";
	for (int i = 0; i < queries.size(); ++i) {
		cerr << queries[i]; if (i != queries.size()-1) { cerr << " "; }
	}
	cerr << ")\n";
	cerr << "check=(";
	for (int i = 0; i < check.size(); ++i) {
		cerr << check[i]; if (i != check.size()-1) { cerr << " "; }
	}
	cerr << ")\n";

	//	Get vector<int> 'result', print, and compare to 'check'
	vector<int> result = matchingStrings(strings, queries);
	cerr << "result=(";
	for (int i = 0; i < result.size(); ++i) {
		cerr << result[i]; if (i != result.size()-1) { cerr << " "; } 
	}
	cerr << ")\n";

	assert (result == check);
}


int main()
{
	vector<string> input_values = { 
		"4\naba\nbaba\naba\nxzxb\n3\naba\nxzxb\nab\n", 
		"3\ndef\nde\nfgh\n3\nde\nlmn\nfgh",
	"13\nabcde\nsdaklfj\nasdjf\nna\nbasdn\nsdaklfj\nasdjf\nna\nasdjf\nna\nbasdn\nsdaklfj\nasdjf\n5\nabcde\nsdaklfj\nasdjf\nna\nbasdn\n",

	};
	vector<string> input_checks = { 
		"2\n1\n0\n", 
		"1\n0\n1\n",
		"1\n3\n4\n3\n2\n",
	};
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i != input_values.size(); ++i) { 
		string input_str = input_values[i];
		string check_str = input_checks[i];
		test_matchingStrings(input_str, check_str);
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


