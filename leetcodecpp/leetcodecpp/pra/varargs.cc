#include<iostream>
#include<cstdio>

using namespace std;

void fun(...) {
    cout << __LINE__ <<endl;
    cout << __FILE__<<endl;
    cout << __VA_ARGS__ <<endl;
}

int main() {
    fun("a - b", 2);
}
