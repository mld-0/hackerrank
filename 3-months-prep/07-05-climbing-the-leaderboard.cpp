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

vector<int> climbingLeaderboard_LinearSearch(vector<int> ranked, vector<int> player)
{
	vector<int> result;
	set<int,greater<int>> ranked_unique(ranked.begin(), ranked.end());
	for (const auto& score: player) {
		int index = 0;
		for (int i = 0; i < ranked_unique.size(); ++i) {
			index++;
			if (*next(ranked_unique.begin(), i) <= score) {
				break;
			}
		}
		if (*prev(ranked_unique.end(), 1) > score) {
			index++;
		}
		result.push_back(index);
	}
	return result;
}


vector<int> climbingLeaderboard_BisectRight(vector<int> ranked, vector<int> player)
{
	vector<int> result;
	set<int> ranked_unique(ranked.begin(), ranked.end());
	for (const auto& score: player) {
		auto bisect_right_it = upper_bound(ranked_unique.begin(), ranked_unique.end(), score);
		auto bisect_right_index = distance(ranked_unique.begin(), bisect_right_it);
		int index = ranked_unique.size() - bisect_right_index + 1;
		result.push_back(index);
	}
	return result;
}


vector<int> climbingLeaderboard_BinarySearch(vector<int> ranked, vector<int> player)
{
	vector<int> result;
	set<int> ranked_unique(ranked.begin(), ranked.end());
	for (const auto& score: player) {
		int low = 0;
		int high = ranked_unique.size() - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (*next(ranked_unique.begin(), mid) > score) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		int index = ranked_unique.size() - low + 1;
		result.push_back(index);
	}
	return result;
}


vector<int> climbingLeaderboard_TwoPointers(vector<int> ranked, vector<int> player)
{
	vector<int> result;
	set<int,greater<int>> ranked_unique(ranked.begin(), ranked.end());
	//	position in 'player'
	int i = 0;
	//	position in 'ranked_unique'
	int j = ranked_unique.size() - 1;
	while (i < player.size()) {
		if (j < 0) {
			result.push_back(1);
			i++;
		} else if (player[i] < *next(ranked_unique.begin(), j)) {
			result.push_back(j+2);
			i++;
		} else if (player[i] > *next(ranked_unique.begin(), j)) {
			j--;
		} else {
			result.push_back(j+1);
			i++;
		}
	}
	return result;
}


vector<int> climbingLeaderboard_Stack(vector<int> ranked, vector<int> player)
{
	vector<int> result;
	set<int,greater<int>> ranked_unique(ranked.begin(), ranked.end());
	vector<int> ranked_unique_vector(ranked_unique.begin(), ranked_unique.end());
	vector<int> player_sorted(player.begin(), player.end());
	stable_sort(player_sorted.begin(), player_sorted.end());
	assert (player_sorted == player);
	for (const auto& score: player) {
		while (ranked_unique_vector.size() > 0 && score >= ranked_unique_vector[ranked_unique_vector.size()-1]) {
			ranked_unique_vector.pop_back();
		}
		result.push_back(ranked_unique_vector.size()+1);
	}
	return result;
}


int main()
{
	vector<std::function<vector<int>(vector<int>,vector<int>)>> test_functions = { climbingLeaderboard_LinearSearch, climbingLeaderboard_BisectRight, climbingLeaderboard_BinarySearch, climbingLeaderboard_TwoPointers, climbingLeaderboard_Stack, };
	vector<string> test_functions_names = { "climbingLeaderboard_LinearSearch", "climbingLeaderboard_BisectRight", "climbingLeaderboard_BinarySearch", "climbingLeaderboard_TwoPointers", "climbingLeaderboard_Stack", };
	assert (test_functions.size() == test_functions_names.size());

	vector<pair<vector<int>,vector<int>>>  input_values = { {{100,100,50,40,40,20,10}, {5,25,50,120}}, {{100,90,90,80,75,60}, {50,65,77,90,102}},{{295,294,291,287,287,285,285,284,283,279,277,274,274,271,270,268,268,268,264,260,259,258,257,255,252,250,244,241,240,237,236,236,231,227,227,227,226,225,224,223,216,212,200,197,196,194,193,189,188,187,183,182,178,177,173,171,169,165,143,140,137,135,133,130,130,130,128,127,122,120,116,114,113,109,106,103,99,92,85,81,69,68,63,63,63,61,57,51,47,46,38,30,28,25,22,15,14,12,6,4}, {5,5,6,14,19,20,23,25,29,29,30,30,32,37,38,38,38,41,41,44,45,45,47,59,59,62,63,65,67,69,70,72,72,76,79,82,83,90,91,92,93,98,98,100,100,102,103,105,106,107,109,112,115,118,118,121,122,122,123,125,125,125,127,128,131,131,133,134,139,140,141,143,144,144,144,144,147,150,152,155,156,160,164,164,165,165,166,168,169,170,171,172,173,174,174,180,184,187,187,188,194,197,197,197,198,201,202,202,207,208,211,212,212,214,217,219,219,220,220,223,225,227,228,229,229,233,235,235,236,242,242,245,246,252,253,253,257,257,260,261,266,266,268,269,271,271,275,276,281,282,283,284,285,287,289,289,295,296,298,300,300,301,304,306,308,309,310,316,318,318,324,326,329,329,329,330,330,332,337,337,341,341,349,351,351,354,356,357,366,369,377,379,380,382,391,391,394,396,396,400}}, };
	vector<vector<int>> input_checks = { {6,4,2,1}, {6,5,4,2,1}, {88,88,87,85,84,84,83,82,81,81,80,80,80,80,79,79,79,79,79,79,79,79,77,75,75,74,73,73,73,71,71,71,71,71,71,70,70,69,69,68,68,68,68,67,67,67,66,66,65,65,64,64,62,61,61,60,59,59,59,59,59,59,58,57,56,56,55,55,53,52,52,51,51,51,51,51,51,51,51,51,51,51,51,51,50,50,50,50,49,49,48,48,47,47,47,45,43,42,42,41,38,36,36,36,36,35,35,35,35,35,35,34,34,34,33,33,33,33,33,32,30,28,28,28,28,27,27,27,26,23,23,22,22,20,20,20,18,18,15,15,14,14,13,13,11,11,10,10,8,8,7,6,5,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, };
	assert (input_values.size() == input_checks.size());

	int test_func_i = 0;
	for (const auto& test_func: test_functions) {
		cerr << test_functions_names[test_func_i++] << "\n";
		for (int i = 0; i < input_values.size(); ++i) {
			vector<int> ranked = input_values[i].first;
			vector<int> player = input_values[i].second;
			printVector("ranked", ranked);
			printVector("player", player);
			vector<int> check = input_checks[i];
			vector<int> result = test_func(ranked, player);
			printVector("result", result);
			assert (result == check);
		}
		cerr << "\n";
	}

	return 0;
}

