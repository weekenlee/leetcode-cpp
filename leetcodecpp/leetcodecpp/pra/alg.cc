#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<int> v({1,3,4,7});
    
    if(any_of(v.cbegin(), v.cend(), [](int i){return i % 2 == 1;})) {
        cout << "at least one int in v is odd" <<endl;
    }

    cout << "vector v sroted " << is_sorted(v.cbegin(), v.cend()) <<endl;
    return 0;
}
