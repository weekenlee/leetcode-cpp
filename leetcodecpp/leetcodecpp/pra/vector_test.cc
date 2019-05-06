#include <vector>
#include <iostream>

using namespace std;

void test() {
    vector<int> vec{1,2,3,4};
    int *p = &vec[2];
    cout << *p <<endl; //3
    cout << vec.size() <<endl; //4
    vec.insert(vec.begin(), 0);
    cout << *p <<endl; //3
    cout << vec.size() <<endl; //5
}

int main() {
    test();
}
