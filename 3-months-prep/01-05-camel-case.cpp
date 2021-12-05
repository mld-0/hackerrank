//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
//	{{{2

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &, const char);

string inputLineSplit(char kind, string s)
{
	//	Remove trailing parenthesis from method str
	if (kind == 'M') {
		s = s.substr(0,s.size()-2);
	}
	vector<string> words;

	//	As lower case letter
	string loop_word;
	loop_word.push_back(tolower(s.at(0)));

	for (int i = 1; i < s.size(); ++i) {
		char x = s.at(i);
		if (isupper(x)) {
			//	Ongoing: 2021-12-05T21:08:34AEDT necessary to make a copy? Not a pointer/reference (so no?), 'mutability' of C++ strings?
			words.push_back(string(loop_word));
			loop_word = "";
			loop_word.push_back(tolower(x));
		} else {
			loop_word.push_back(x);
		}
	}
	words.push_back(loop_word);

	//	Combine words as sentence
	string result = "";
	for (int i = 0; i < words.size(); ++i) {
		result += words[i];
		if (i != words.size()-1) {
			result += " ";
		}
	}

	return result;
}

string inputLineCombine(char kind, string s)
{
	vector<string> words = split(s, ' ');
	
	if (kind == 'C') {
		string temp; 
		temp.push_back(toupper(words[0].at(0)));
		temp += words[0].substr(1, words[0].size());
		words[0] = temp;
	}

	for (int i = 1; i < words.size(); ++i) {
		string temp; 
		temp.push_back(toupper(words[i].at(0)));
		temp += words[i].substr(1, words[0].size());
		words[i] = temp;
	}

	//	Combine as single word
	string result = "";
	for (int i = 0; i < words.size(); ++i) {
		result += words[i];
	}

	if (kind == 'M') {
		result += "()";
	}

	return result;
}

void test(string input_str, string check_str)
{
	//cout << "input_str=(" << input_str << ")\n";
	//cout << "check_str=(" << check_str << ")\n";

	vector<string> input_str_split = split(input_str, '\n');
	vector<string> check_str_split = split(check_str, '\n');
	assert (input_str_split.size() == check_str_split.size());

	//for (auto input_line: input_str_split) {
	for (int i = 0; i < input_str_split.size(); ++i) {
		string input_line = input_str_split[i];
		string check_line = check_str_split[i];
		cerr << "input_line=(" << input_line << ")\n";
		cerr << "check_line=(" << check_line << ")\n";

		vector<string> input_line_split = split(rtrim(input_line), ';');
		assert (input_line_split.size() == 3);
		char op = input_line_split[0].at(0);
		char kind = input_line_split[1].at(0);
		string s = input_line_split[2];
		cerr << "op=(" << op << "), kind=(" << kind << "), s=(" << s << ")\n";

		string result;
		if (op == 'S') {
			result = inputLineSplit(kind, s);
		} else {
			result = inputLineCombine(kind, s);
		}
		cout << "result=(" << result << ")\n";

		assert (result == check_line);
	}

}

int main()
{
	vector<string> input_values = { "S;V;iPad\nC;M;mouse pad\nC;C;code swarm\nS;C;OrangeHighlighter", "C;V;can of coke\nS;M;sweatTea()\nS;V;epsonPrinter\nC;M;santa claus\nC;C;mirror", };
	vector<string> input_checks = { "i pad\nmousePad()\nCodeSwarm\norange highlighter", "canOfCoke\nsweat tea\nepson printer\nsantaClaus()\nMirror", };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i != input_values.size(); ++i) {
		string input_str = input_values[i];
		string check_str = input_checks[i];
		test(input_str, check_str);
		cout << "\n";
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


