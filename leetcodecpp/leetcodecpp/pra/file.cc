#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>

using namespace std;

void funiq(const string &file) {
    fstream myFile;
    string linebuf;
    unordered_set<string> uniq;

    try {
        myFile.exceptions(ios_base::failbit | ios_base::badbit);
        myFile.open(file, ios_base::in);
        myFile.exceptions(ios_base::goodbit);


        while(getline(myFile, linebuf)) {
            uniq.insert(linebuf);
        }
    }catch(const ios_base::failure &e) {
        cout<<"error reading file: "<<e.what() <<endl;
    }


    for(auto x : uniq) {
        cout << x <<endl;
    }
}

int main() {
    funiq("file.cc");
    return 0;
}
