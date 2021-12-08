//	VIM SETTINGS: {{{3
//	vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
//	vim: set foldlevel=2 foldcolumn=2:
//	}}}1
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <tuple>
#include <set>
#include <sstream>
#include <climits>
#include <cassert>
using namespace std;
//	{{{2

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &, const char);
template <typename T>
string join(const vector<T>, const char);
template <typename T>
void printVector(string varname, const vector<T> words, const char delim=' ');
template <typename A, typename B>
void printMap(string varname, const map<A,B> m, const char delim=' ');

//	LINK: https://stackoverflow.com/questions/37368787/c-sort-one-vector-based-on-another-one
/* 	Fill the zipped vector with pairs consisting of the corresponding elements of a and b. (This assumes that the vectors have equal length) */
template <typename A, typename B>
void zip(const std::vector<A> &a, const std::vector<B> &b, std::vector<std::pair<A,B>> &zipped)
	//	{{{
{
    for (size_t i = 0; i < a.size(); ++i) {
        zipped.push_back(std::make_pair(a[i], b[i]));
    }
}
	//	}}}

/* Write the first and second element of the pairs in the given zipped vector into a and b. (This assumes that the vectors have equal length) */
template <typename A, typename B>
void unzip(const std::vector<std::pair<A, B>> &zipped, std::vector<A> &a, std::vector<B> &b)
	//	{{{
{
    for (size_t i = 0; i < a.size(); i++) {
        a[i] = zipped[i].first;
        b[i] = zipped[i].second;
    }
}
	//	}}}

bool isValidTriangle(tuple<int,int,int> x)
{
	int a = get<0>(x);
	int b = get<1>(x);
	int c = get<2>(x);
	return (a + b > c) && (a + c > b) && (b + c > a);
}

//	LINK: https://www.geeksforgeeks.org/make-combinations-size-k/
/*	Fill 'result_indexes' with all combinations of length 'k' in range [left, n] */
void _makeCombinationTripletsUtil(vector<vector<int>> &result_indexes, vector<int> &temp, int n, int left, int k)
{
    if (k == 0) {
        result_indexes.push_back(temp);
        return;
    }
    for (int i = left; i <= n; ++i) {
        temp.push_back(i);
        _makeCombinationTripletsUtil(result_indexes, temp, n, i + 1, k - 1);
        temp.pop_back();
    }
}

/* 	Get all unique combinations of lengths from 'sticks' that describe a valid triangle */
vector<tuple<int,int,int>> getValidTriplets(vector<int> sticks)
{
	//	Get all combinations of length 3 from [ 0, sticks.size()-1 ] as 'result_indexes'
	vector<vector<int>> result_indexes;
	vector<int> temp;
	int k = 3;
	_makeCombinationTripletsUtil(result_indexes, temp, sticks.size()-1, 0, k);
	//	Add the lengths corresponding to 'result_indexes' to 'result_set' if they describe a valid triangle
	set<tuple<int,int,int>> result_set;
	for (auto const &x: result_indexes) {
		assert(x.size() == 3);
		vector<int> trial_combination_vector = { sticks[x[0]], sticks[x[1]], sticks[x[2]] };
		stable_sort(trial_combination_vector.begin(), trial_combination_vector.end(), greater<>());
		tuple<int,int,int> trial_combination = { trial_combination_vector[0], trial_combination_vector[1], trial_combination_vector[2] };
		if (isValidTriangle(trial_combination)) {
			result_set.insert(trial_combination);
		}
	}
	vector<tuple<int,int,int>> result(result_set.begin(), result_set.end());
	return result;
}


vector<int> maximumPerimeterTriangle_i(vector<int> sticks)
{
	vector<tuple<int,int,int>> triplet_lengths = getValidTriplets(sticks);
	//for (auto const &x: triplet_lengths) {
	//	cerr << get<0>(x) << "," << get<1>(x) << "," << get<2>(x) << "\n";
	//}

	if (triplet_lengths.size() == 0) {
		return { -1 };
	}

	vector<int> triplet_perimeters(triplet_lengths.size());
	for (int i = 0; i < triplet_lengths.size(); ++i) {
		auto const &x = triplet_lengths[i];
		int length = get<0>(x) + get<1>(x) + get<2>(x);
		triplet_perimeters[i] = length;
	}

	//	TODO: 2021-12-08T15:42:50AEDT _hackerrank, C++, 03-06-max-perimeter, sorting multiple vectors together without using 'zip()/unzip()' functions sourced online
	//	Sort (triplet_perimeters, triplets_lengths)
	vector<pair<int,tuple<int,int,int>>> zipped;
	zip(triplet_perimeters, triplet_lengths, zipped);

	sort(begin(zipped), end(zipped), 
			[&](const auto &a, const auto &b) {
				if (a.first == b.first) {
					return a.second > b.second;
				} else {
					return a.first > b.first;
				}
		});
	//	This is same as default behaviour(?) 
	//stable_sort(begin(zipped), end(zipped), greater_equal<>());

	//for (auto const &x: zipped) {
	//	cerr << x.first << ", " << get<0>(x.second) << "," << get<1>(x.second) << "," << get<2>(x.second) << "\n";
	//}

	unzip(zipped, triplet_perimeters, triplet_lengths);

	tuple<int,int,int> result_triplet_lengths = triplet_lengths[0];
	return { get<2>(result_triplet_lengths), get<1>(result_triplet_lengths), get<0>(result_triplet_lengths) };
}

//	TODO: 2021-12-08T20:52:01AEDT _hackerrank, 03-06-max-perimeter, review simple solution (see discussion)
vector<int> maximumPerimeterTriangle_ii(vector<int> sticks)
{
	return { -1 };
}


int main()
{
	vector<vector<int>> input_values = { {1,2,3,4,5,10}, {1,1,1,3,3}, {1,2,3}, {1,1,1,2,3,5}, {3,9,2,15,3}, 
		{50,2430,134,6373,215,1502,926,10312,351,74,572,3938}, {9, 2015, 5294, 58768, 285, 477, 72, 13867, 97, 22445, 48, 36318, 764, 8573, 183, 3270, 81, 1251, 59, 95094},
		{34, 1924, 565, 80, 848, 2913, 819, 732, 431, 32981, 195, 86340, 688, 563, 7763, 314, 12608, 401, 4845, 439, 353, 52, 208, 20372, 626, 805, 19, 984, 939, 53354},
		{537, 6494, 4166, 7388, 19855, 6023, 6599, 6264, 2139, 9468, 129280, 29846, 546999, 7067, 208844, 885139, 79558, 2257, 49705, 9553, 3869, 6354, 7911, 5672, 914, 9990, 7701, 4744, 2399, 1432139, 6177, 5645, 4732, 7987, 6181, 1440, 8695, 9855, 338136, 4845},
		{1, 28657, 55, 1346269, 121393, 4181, 17711, 2584, 233, 3, 701408733, 63245986, 21, 75025, 13, 3524578, 34, 10946, 5, 196418, 46368, 8, 102334155, 987, 9227465, 1597, 610, 317811, 267914296, 1, 144, 2178309, 165580141, 514229, 832040, 377, 6765, 2, 89, 24157817, 433494437, 5702887, 39088169, 14930352},
		{76361, 69365, 78109, 44475, 13538, 5084, 1371, 6453, 83726, 94527, 401820417, 13839263, 768933, 22392673, 153481704, 88347, 44593, 5285782, 191555, 58624780, 248338678, 26826, 70078, 97005, 26139, 25664, 68595, 83568, 36232035, 3267536, 78837, 22863, 36133, 2409, 44739, 2018202, 35222, 650159152, 1249262, 31720, 66102, 39532, 94856906, 77216, 8553388, 480240, 288620, 59954, 36981},
		{585864, 30960, 397193, 982469, 275301, 815633, 500552, 1980053, 4956083, 563585, 619528, 879603, 467531, 927141, 393527, 917709, 350333, 54529145, 7932125, 963208, 520081, 142767080, 499865, 582730, 512174, 20820393, 575285, 592595, 33708702, 364190, 289354, 351506, 995836, 228962, 326149, 2975979, 420118, 984155, 620289, 508798, 199101, 517109, 12888237, 88237927, 928368, 137821, 825743, 274447, 411970, 951836},
		{3900717, 53516059, 288589053, 23189292, 21487730, 94997775, 260173, 41298280, 47784002, 23032379, 67686298, 48162481, 44775136, 47340544, 2165965, 34202258, 81746554, 57179615, 6240306, 33110389, 7424599, 41389013, 480910581, 86150390, 13777985, 96265144, 89266112, 316419, 74896112, 192317271, 63729818, 40712188, 19111441, 25556170, 33808338, 96043868, 90508879, 88229925, 62520492, 49835454, 78096135, 54610351, 78888361, 10300724, 34843471, 38439667, 81892481, 16254176, 24261693, 84190486},
		{1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000},
	};
	vector<vector<int>> input_checks = { {3,4,5}, {1,3,3}, {-1}, {1,1,1}, {2,3,3}, {-1}, {72,81,97}, {848,939,984}, {9553,9855,9990}, {-1}, {88347,94527,97005}, {982469,984155,995836}, {94997775,96043868,96265144}, {1000000000,1000000000,1000000000}, };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i < input_checks.size(); ++i) {
		vector<int> &sticks = input_values[i];
		vector<int> &check = input_checks[i];

		printVector("sticks", sticks);
		printVector("check", check);

		vector<int> result = maximumPerimeterTriangle_i(sticks);
		printVector("result", result);

		assert (result == check);
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

template <typename T>
string join(const vector<T> words, const char delim) {
	//	{{{
	string result = "";
	for (int i = 0; i < words.size(); ++i) {
		result += to_string(words[i]);
		if (i != words.size()-1) { result += delim; }
	}
	return result;
}
	//	}}}

template <typename T>
void printVector(string varname, const vector<T> words, const char delim) {
	//	{{{
	string vector_str = join(words, delim);
	cerr << varname << "=(" << vector_str << ")\n";
}
	//	}}}

template <typename A, typename B>
void printMap(string varname, const map<A,B> m, const char delim) {
	//	{{{
	string m_str = "";
	for (auto const &x: m) {
		m_str += to_string(x.first);
		m_str += ":";
		m_str += to_string(x.second);
		m_str += delim;
	}
	m_str.pop_back();
	cerr << varname << "=(" << m_str << ")\n";
}
	//	}}}


