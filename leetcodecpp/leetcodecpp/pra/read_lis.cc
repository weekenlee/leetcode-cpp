#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string get_node_name(const string& line) {
    int index1 = line.find_first_of("\"");
    int index2 = line.find_first_of("\"", index1 + 1);
    if(index1 != string::npos && index2 != string::npos) {
        string name = line.substr(index1 + 1, index2 - index1 - 1);
        if(name[name.length() - 1] == ' ') {
            return name.substr(0,name.length() - 1);
        }
        return name;
    }else {
        return "";
    }
}

string get_max_value(int linenums, const vector<string>& lines) {
    int endline = linenums;
    while(lines[endline].find("Summary of preceding table follows:") == string::npos) {
        endline++;
    }

    vector<string> values;
    for(int i = linenums+4; i < endline; i++) {
        vector<string> vals;
        stringstream ss(lines[i]);
        string word;
        while(ss >> word) {
            vals.push_back(word);
        }
        int times = stoi(vals[3]);
        for(int j = 0; j< times; j++) {
            values.push_back(vals[2]);
        }
    }

    sort(values.begin(), values.end());

    return values[values.size() - 3];
}

void process(int linenums, const vector<string>& lines) {
    string node_name = get_node_name(lines[linenums+1]);
    string max_value;
    if(node_name != "") {
        max_value = get_max_value(linenums, lines);
    }
    cout << node_name<<" "<<max_value<<endl;
}

int main() {
    fstream f_read("电厂侧合甲线a相重合闸.lis");
    string line;
    vector<string> lines;
    vector<int> linenums;
    int linenum = 0;
    while(getline(f_read, line)) {
        lines.push_back(line);
        if(line.find(" ) ------------------------------------------------------------------------------------------------------------------------------") != -1) {
            linenums.push_back(linenum);
        }
        linenum++;
    }

    for(auto linenum : linenums) {
        process(linenum, lines);
    }
    return 0;
}
