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
template <typename T>
void printVector(string varname, const vector<T> words, const char delim=' ') {
	//	{{{
	string vector_str = join(words, delim);
	cerr << varname << "=(" << vector_str << ")\n";
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
//	}}}

vector<int> dynamicArray(int n, vector<vector<int>> queries)
{
	vector<int> result;
	vector<vector<int>> arr;
	for (int i = 0; i < n; ++i) {
		arr.push_back( {} );
	}
	int lastAnswer = 0;
	for (const auto &q: queries) {
		int qtype = q[0];
		int x = q[1];
		int y = q[2];
		int idx;
		if (qtype == 1) {
			idx = ( (x ^ lastAnswer) % n);
			arr[idx].push_back(y);
		} else if (qtype == 2) {
			idx = ( (x ^ lastAnswer) % n);
			lastAnswer = arr[idx][y%arr[idx].size()];
			result.push_back(lastAnswer);
		} else {
			throw domain_error("Invalid qtype");
		}
	}
	return result;
}


int main()
{
	vector<pair<int,vector<vector<int>>>> input_values = { {2, {{1,0,5},{1,1,7},{1,0,3},{2,1,0},{2,1,1}}}, {100, {{1,345255357,205970905}, {1,570256166,75865401}, {1,94777800,645102173}, {1,227496730,16649450}, {1,82987157,486734305}, {1,917920354,757848208}, {1,61379773,817694251}, {1,330547128,112869154}, {1,328743001,855677723}, {1,407951306,669798718}, {1,21506172,676980108}, {1,49911390,342109400}, {1,980306253,305632965}, {2,736380701,402184046}, {2,798108301,416334323}, {1,254839279,1370035}, {1,109701362,2800586}, {1,374257441,165208824}, {1,624259835,477431250}, {1,629066664,454406245}, {1,135821145,763845832}, {1,480298791,138234911}, {1,553575409,835718837}, {1,13022848,624652920}, {1,974893519,882630870}, {1,137832930,216177975}, {1,453349691,969255659}, {1,138396076,91038209}, {1,699822497,941751038}, {1,116800806,64071662}, {1,815273934,8835809}, {1,658534867,657771609}, {1,183760807,179377441}, {1,93984556,636425656}, {1,231506463,836238924}, {1,214074594,709571211}, {1,649641434,509698468}, {2,523656673,709717705}, {2,261443586,330808140}, {1,75924023,449768243}, {1,849537714,354568873}, {2,641743742,124196560}, {1,19829224,995759639}, {1,244389335,108315212}, {1,877758467,421383626}, {1,573278148,474192994}, {2,561031511,448889978}, {1,773294404,980994962}, {2,33088709,716646168}, {1,760927835,441983538}, {1,273540687,783321829}, {1,5933845,384358662}, {1,543628702,372160176}, {2,136400466,910559291}, {2,546568738,393221347}, {1,812227065,694221123}, {1,311065574,103905420}, {2,571344361,185289590}, {1,99638520,173318136}, {1,854060080,407068012}, {2,980658213,778573744}, {2,412539660,476853104}, {1,530145366,36493537}, {1,604875364,100141497}, {2,650812104,64817757}, {1,141060009,766603553}, {1,598398952,418245941}, {1,262344011,431865586}, {2,56413893,546484833}, {1,400736735,673588153}, {1,642955232,803851098}, {1,917782037,935143105}, {1,658284524,745224102}, {1,103202288,501551287}, {1,162144918,12888783}, {1,16486753,67467208}, {1,671120703,941541277}, {1,47399694,77707668}, {1,122011395,946116527}, {1,924363862,886726236}, {2,657761235,540240467}, {1,203175991,279882007}, {2,304620923,162838413}, {1,440453449,117964712}, {2,941868853,887850334}, {1,293198923,466812643}, {1,461688477,532794906}, {1,315016797,733095902}, {1,265008751,913972757}, {1,887405255,139170948}, {2,754223230,426836947}, {1,945967814,852589735}, {1,168866283,309720694}, {1,373861145,94596540}, {2,984122495,20702849}, {2,233835636,180460242}, {1,172787631,643823473}, {1,273611372,616819555}, {1,196104599,690080895}, {1,527554061,434103342}}}, };
	vector<vector<int>> input_checks = { {7,3}, {855677723,75865401,763845832,75865401,709571211,645102173,112869154,763845832,449768243,757848208,91038209,205970905,783321829,372160176,384358662,67467208,935143105,384358662,309720694,138234911}, };
	assert (input_values.size() == input_checks.size());

	for (int i = 0; i < input_values.size(); ++i) {
		int n = input_values[i].first;
		vector<vector<int>>& queries = input_values[i].second;
		print2DVector("queries", queries);
		cerr << "n=(" << n << ")\n";
		vector<int> check = input_checks[i];
		vector<int> result = dynamicArray(n, queries);
		printVector("result", result);
		assert (result == check);
		cerr << "\n";
	}

}
