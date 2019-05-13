#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <cstdlib>

using namespace std;

int boundedRand() {return rand() % 100;}

int main() {
    const int SZ = 20;
    int a[SZ], b[SZ]={0};
    generate(a, a + SZ, boundedRand);
    int val = boundedRand();
    int *end = remove_copy_if(a, a + SZ, b, bind2nd(greater<int>(), val));
    sort(a, a + SZ);
    sort(b, end);
    ostream_iterator<int> out(cout, " ");
    copy(a, a + SZ, out);cout <<endl;

}
