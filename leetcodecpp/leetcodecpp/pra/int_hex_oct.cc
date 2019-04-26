#include<iostream>
#include<sstream>
#include<cstdio>
#include<bitset>

using namespace std;

int main() {
    char s[100];
    sprintf(s, "%d", 10);
    cout << s <<endl;
    sprintf(s, "%x", 10); //16进制
    cout << s <<endl;
    sprintf(s, "%o", 10); //8进制
    cout << s <<endl;

    stringstream ss;
    ss<<hex<<10;
    cout << ss.str() <<endl;
    stringstream sss;
    sss<<oct<<10;
    cout << sss.str() <<endl;

    string str;
    str = bitset<8>(10).to_string();
    cout << str <<endl; // 二进制
}
