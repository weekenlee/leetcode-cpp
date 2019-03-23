#include<iostream>
#include<string>
#include<regex>
using namespace std;

void search_byregex() {
    string str = "hello 2019, byte 2018";
    smatch result;
    regex pattern("\\d{4}");

    string::const_iterator iterstart = str.begin();
    string::const_iterator iterend = str.end();
    string temp;
    while(regex_search(iterstart, iterend, result, pattern)) {
        temp = result[0];
        cout << temp << endl; 
        iterstart = result[0].second;// 更新搜索开始位置，搜索剩下的字符串
    }
}

int main() {
     cout << regex_match("123", regex("\\d+")) << endl;
     cout << regex_match("你好123", regex("\\d+")) << endl;


     string str = "hello_2018";
     smatch result;
     regex pattern(".{5}_(\\d{4})");

     if(regex_match(str, result, pattern)) {
        cout << result[0] <<endl;
        cout << result[1] <<endl;
        cout << result[2] <<endl;
        
        cout << result.str() <<endl;
        cout << result.str(1) <<endl;
        cout << result.str(2) <<endl;
     }

     search_byregex();
}

