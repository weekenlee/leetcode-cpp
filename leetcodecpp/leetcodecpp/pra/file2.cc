#include<fstream>
#include<iostream>
using namespace std;

int main() {
    const int SZ = 100;
    char buf[SZ];
    ifstream in("file.cc");
    while(in.getline(buf, SZ)) {
        cout << buf ;
    }
    cout << endl;
    char c;
    ifstream in2("file.cc");
    while(in2>>c) {
        cout <<c;
    }
    cout << endl;
    ifstream in3("file.cc");
    cout << in3.rdbuf();


    
    return 0;
}
