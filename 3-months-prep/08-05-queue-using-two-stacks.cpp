//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <sstream>
#include <climits>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
//	{{{2
//	ltrim(), rtrim(), split(), join(), printVector(), printMap(), print2DVector()
//	{{{
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
vector<string> split(const string &str, const char delim=' ') {
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
template <typename T>
string join(const vector<T> words, const char delim=' ') {
	//	{{{
	string result = "";
	for (int i = 0; i < words.size(); ++i) {
		result += std::to_string(words[i]);
		if (i != words.size()-1) { result += delim; }
	}
	return result;
}
	//	}}}
string join(const vector<string> words, const char delim=' ') {
	//	{{{
	string result = "";
	for (int i = 0; i < words.size(); ++i) {
		result += words[i];
		if (i != words.size()-1) { result += delim; }
	}
	return result;
}
	//	}}}
string join(const vector<char> words, const char delim=' ') {
	//	{{{
	string result = "";
	for (int i = 0; i < words.size(); ++i) {
		result += words[i];
		if (i != words.size()-1) { result += delim; }
	}
	return result;
}
	//	}}}
template <typename T>
void printVector(string varname, const vector<T> words, const char delim=' ') {
	//	{{{
	string vector_str = join(words, delim);
	cerr << varname << "=(" << vector_str << ")\n";
}
	//	}}}
template <typename T>
void print2DVector(string varname, const vector<vector<T>> words, const char delim=' ') {
	//	{{{
	string result = "(";
	for (int i = 0; i < words.size(); ++i) {
		result += "(";
		string loop_result = join(words[i], ',');
		result += loop_result;
		result += ")";
		if (i != words.size()-1) {
			result += ", ";
		}
	}
	result += ")\n";
	cerr << varname << "=" << result;
}
	//	}}}
template <typename A, typename B>
void printMap(string varname, const map<A,B> m, const char delim=' ') {
	//	{{{
	string m_str = "";
	for (auto const &x: m) {
		m_str += std::to_string(x.first);
		m_str += ":";
		m_str += std::to_string(x.second);
		m_str += delim;
	}
	m_str.pop_back();
	cerr << varname << "=(" << m_str << ")\n";
}
	//	}}}
//	}}}

template< typename T >
class StacksQueue {
public:
	vector<T> inbox;
	vector<T> outbox;
	void enqueue(T x) {
		this->inbox.push_back(x);
	}
	void dequeue() {
		this->refill_outbox();
		this->outbox.pop_back();
	}
	T print_front() {
		this->refill_outbox();
		return this->outbox.back();
	}
private:
	void refill_outbox() {
		if (this->outbox.size() == 0) {
			while (this->inbox.size() > 0) {
				T temp = this->inbox.back();
				this->inbox.pop_back();
				this->outbox.push_back(temp);
			}
		}
	}
};

int main()
{
	vector<string> input_values = { "1 42\n2\n1 14\n3\n1 28\n3\n1 60\n1 78\n2\n2", "1 76\n1 33\n2\n1 23\n1 97\n1 21\n3\n3\n1 74\n3" };
	vector<vector<int>> input_checks = { {14,14}, {33,33,33}, };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i < input_values.size(); ++i) {
		vector<string> lines_split = split(input_values[i], '\n');
		vector<int>& check = input_checks[i];

		vector<vector<int>> values;
		for (const auto& line: lines_split) {
			vector<string> line_split = split(line, ' ');
			vector<int> line_split_ints;
			for (const auto& x: line_split) {
				line_split_ints.push_back(stoi(x));
			}
			values.push_back(line_split_ints);
		}
		print2DVector("values", values);

		vector<int> result;
		StacksQueue<int> queue;
		for (const auto& item: values) {
			printVector("item", item);
			if (item[0] == 1) {
				queue.enqueue(item[1]);
			} else if (item[0] == 2) {
				queue.dequeue();
			} else if (item[0] == 3) {
				result.push_back(queue.print_front());
			}
		}
		printVector("result", result);
		assert (result == check);
		cerr << "\n";
	}

	return 0;
}

