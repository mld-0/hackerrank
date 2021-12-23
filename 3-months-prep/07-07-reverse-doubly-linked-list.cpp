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

class DoublyLinkedListNode {
public:
	int data;
	DoublyLinkedListNode* next;
	DoublyLinkedListNode* prev;

	DoublyLinkedListNode()
	{
		this->next = NULL;
		this->prev = NULL;
	}

	static DoublyLinkedListNode* from_list(vector<int> values)
	{
		if (values.size() == 0) {
			return NULL;
		}
		DoublyLinkedListNode* head = new DoublyLinkedListNode();
		DoublyLinkedListNode* curr = head;
		DoublyLinkedListNode* prev = curr;
		for (const auto& v: values) {
			curr->data = v;
			curr->next = new DoublyLinkedListNode();
			prev = curr;
			curr= curr->next;
			curr->prev = prev;
		}
		prev->next = NULL;
		head->prev = NULL;
		return head;
	}

	static vector<int> to_list(DoublyLinkedListNode* head)
	{
		vector<int> result;
		DoublyLinkedListNode* curr = head;
		while (curr != NULL) {
			result.push_back(curr->data);
			curr = curr->next;
		}
		return result;
	}

	static void free_linked_list(DoublyLinkedListNode* head)
	{
		DoublyLinkedListNode* curr = head;
		DoublyLinkedListNode* prev = NULL;
		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			//cerr << "delete prev, prev->data=(" << prev->data << ")\n";
			prev->next = NULL;
			delete prev;
		}
	}
};

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) 
{
	DoublyLinkedListNode* prev = NULL;
	DoublyLinkedListNode *curr = llist;
	while (curr != NULL) {
		DoublyLinkedListNode* temp = curr->next;
		curr->prev = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}


int main()
{
	vector<vector<int>> input_values = { {1,2,3,4,5,6,7,8,9}, };

	for (const auto input_list: input_values) {
		vector<int> check_list(input_list.begin(), input_list.end());
		reverse(check_list.begin(), check_list.end());

		DoublyLinkedListNode* head = DoublyLinkedListNode::from_list(input_list);
		DoublyLinkedListNode* result = reverse(head);

		vector<int> result_list = DoublyLinkedListNode::to_list(result);
		printVector("result_list", result_list);

		assert (result_list == check_list);

		DoublyLinkedListNode::free_linked_list(result);
	}

	return 0;
}

