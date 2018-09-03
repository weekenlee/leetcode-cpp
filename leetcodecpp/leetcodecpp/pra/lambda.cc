#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    vector<int> v({6,1,8,2,7,6});
    for (auto x : v) 
        cout << x <<endl;

    sort(v.begin(), v.end(), [](int a, int b) {return a > b;});

    cout << "reverse sorted : " <<endl;

    for (auto x : v) 
        cout << x <<endl;
}
