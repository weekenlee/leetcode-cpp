#include<iostream>
#include<string>
#include<regex>
using namespace std;

int main() {
     cout << regex_match("123", regex("\\d+")) << endl;
     cout << regex_match("你好123", regex("\\d+")) << endl;
}

