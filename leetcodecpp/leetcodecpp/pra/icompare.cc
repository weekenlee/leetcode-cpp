#include<cassert>
#include<iostream>
#include"ichar_traits.h"

using namespace std;

int main() {
    istring first = "tHis";
    istring second = "THIS";

    cout << first << endl;
    cout << second << endl;

    assert(first.compare(second) == 0);
    assert(first.find("h") == 1);
    assert(first.find("I") == 2);
}
