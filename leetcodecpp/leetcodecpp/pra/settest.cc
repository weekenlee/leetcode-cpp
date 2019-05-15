#include<cassert>
#include<set>
#include<iostream>

using namespace std;

int main() {
    set<int> intset;
    for(int i = 0 ; i < 10 ; i++ )
        for(int j = 0; j < 10; j ++) 
            intset.insert(j);
    cout << intset.size() <<endl;
    for(auto a : intset) 
        cout << a << " ";
    cout <<endl;
}
