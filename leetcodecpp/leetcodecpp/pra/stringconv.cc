#include <sstream>
#include <string>
#include <iostream>

using namespace std;

template <typename T> 
T fromString(const string& s) {
    istringstream is(s);
    T t;
    is >> t;
    return t;
}

template <typename T>
string toString(const T& t) {
    ostringstream s;
    s << t;
    return s.str();
}

int main() {
    int i = 200;
    string s = "1212";
    cout << toString<int>(i) <<endl; 
    cout << fromString<int>(s) <<endl; 
}
