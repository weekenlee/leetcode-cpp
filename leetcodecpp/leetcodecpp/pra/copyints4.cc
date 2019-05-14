#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

int main() {
    int a[] = {10, 20, 30};
    const size_t SIZE = sizeof a / sizeof a[0];
    remove_copy_if(a, a + SIZE,
            ostream_iterator<int>(cout , "\n"), 
            bind2nd(greater<int>(), 15));
}

