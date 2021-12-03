#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

string input_str = 
	"4 3\n"
	"<tag1 value = \"HelloWorld\">\n"
	"<tag2 name = \"Name1\">\n"
	"</tag2>\n"
	"</tag1>\n"
	"tag1.tag2~name\n"
	"tag1~name\n"
	"tag1~value\n";

stringstream ss(input_str);

map <string, string> tagMap;

void createMap(int &n, string pretag) {
    if(!n) return;
    
    string line, tag, attr, value;
    getline(ss, line);
    
    int i=1;
    if(line[i]=='/') {           // found closing tag
        while(line[i]!='>') i++;
        if(pretag.size()>(i-2))		// update tag
            tag = pretag.substr(0,pretag.size()-i+1);
        else
            tag = "";
    }
    else {                       // found opening tag
        while(line[i]!=' ' && line[i]!='>') i++;
        tag = line.substr(1,i-1);	// update tag
        if(pretag!="") tag = pretag + "." + tag;
        
        int j;
        while(line[i]!='>') { // go through attributes
            j = ++i;
            while(line[i]!=' ') i++;
            attr = line.substr(j,i-j);	// attribute name
            
            while(line[i]!='\"') i++;
            j = ++i;
            while(line[i]!='\"') i++;
            value = line.substr(j,i-j);	// attribute value
            i+= 1;
            
            tagMap[tag + "~" + attr] = value;
        }
    }
    createMap(--n, tag);
}

int main() 
{
    int n, q;
    ss >> n >> q;
    ss.ignore();
    createMap(n,"");

	//	print tagMap:
	for (const auto& element : tagMap) {
		cout << "k=(" << element.first << "), v=(" << element.second << ")\n";
	}
    
    string attr, value;
    while(q--) {
        getline(ss,attr);
        value = tagMap[attr];
        if(value=="") value = "Not Found!";
        cout << value << endl;
    }

    return 0;
}

