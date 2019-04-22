#include <iostream>
#include <limits>
using namespace std;

typedef unsigned short ulong;

int main() {
    int b = 12;
    const ulong ulmax = numeric_limits<ulong>::max();
    ulong bit = ~(ulmax >> 1);
    while(bit) {
        cout << (b & bit ? '1':'0');
        bit >>= 1;
    }
}
