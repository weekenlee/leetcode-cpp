#include<sstream>
#include<iostream>

using namespace std;

int main() {
    istringstream ss("4 4.1 hello world");
    int i;
    float f;
    string s;
    ss >> i;
    ss >> f;
    ss >> s;
    cout << i << f << s<< endl;
    cout << ss.rdbuf() <<endl;
}
