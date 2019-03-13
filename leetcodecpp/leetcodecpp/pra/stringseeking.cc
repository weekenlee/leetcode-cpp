#include<cassert>
#include<sstream>
#include<string>
#include<iostream>

using namespace std;

int main() {
    string text = "we will hook no fish";
    stringstream ss(text);
    ss.seekp(0, ios::end);
    ss << " before its time.";
    assert(ss.str() == "we will hook no fish before its time.");
    cout <<ss.str()<<endl;

    ss.seekg(8, ios::beg);
    string word;
    ss >> word;
    assert(word == "hook");

    ss.seekg(16, ios::beg);
    ss >> word;
    assert(word == "fish");
    ss << "ship";
}
