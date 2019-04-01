#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int d[]= {123, 94, 10, 314, 315};
const int DSZ = sizeof d / sizeof d[0];
bool isEven(int x) {return x % 2 == 0;}

int main() {
    vector<bool> vb;

    transform(d, d+DSZ, back_inserter(vb), not1(ptr_fun(isEven)));
    copy(vb.begin(), vb.end(), ostream_iterator<bool>(cout, " "));

    vb.clear();
    cout <<endl;
    transform(d, d+DSZ, back_inserter(vb), ptr_fun(isEven));
    copy(vb.begin(), vb.end(), ostream_iterator<bool>(cout, " "));
    cout <<endl;

    vector<double> vbf;
    transform(d, d+DSZ, back_inserter(vbf), bind2nd(ptr_fun<double, double, double>(pow), 2.0));
    copy(vbf.begin(), vbf.end(), ostream_iterator<double>(cout, " "));
    cout <<endl;
}

