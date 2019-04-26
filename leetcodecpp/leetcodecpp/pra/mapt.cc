#include<map>
#include<iostream>

using namespace std;

int main() {
    map<string ,string> m;
    m.insert({"hello","hello"});
    map<wstring ,wstring> wm;
    wm.insert({L"你好",L"你好hellohai"});
    wcout.imbue(locale(locale(), "", LC_CTYPE));
    wcout << wm[L"你好"] <<endl;
}
