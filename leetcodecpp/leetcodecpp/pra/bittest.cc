#include <iostream>
#include <limits>
#include <bitset>
using namespace std;

typedef unsigned int ulong;

int main() {
    int b = 12;
    const ulong ulmax = numeric_limits<ulong>::max();
    ulong bit = ~(ulmax >> 1);
    while(bit) {
        cout << (b & bit ? '1':'0');
        bit >>= 1;
    }
    cout <<endl;

    bitset<sizeof(ulong)*8> a(b);
    cout << a << endl;
}
