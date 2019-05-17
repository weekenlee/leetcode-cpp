#include <iostream>
#include <vector>
#include <iterator>

#include "find.hpp"

using namespace std;
using namespace lwj;

int main() {
    vector<int> vec{3,4,5,4,5,6,5,8};
    vector<vector<int>::iterator> matches;
    find_all(begin(vec), end(vec), back_inserter(matches), 
            [](int i) {return i == 5;});

    cout << "Found " << matches.size() << " matching elements:" <<endl;
    for(auto it : matches) {
        cout <<*it<<" at position "<<(it - cbegin(vec)) <<endl;
    }
    return 0;
}
