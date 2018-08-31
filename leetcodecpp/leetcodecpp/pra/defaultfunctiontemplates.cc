#include<iostream>
#include<tuple>

using namespace std;

template<class Key = int, class ... Types>
tuple<Key, Types ...> makeCompositions(Key key, Types ... types) {
    return make_tuple(key, types ...);
}

int main() {
    //auto composition = makeCompositions(1, 2.3f, "name");
    auto composition = makeCompositions(1.0, 2.3f, "name");
    cout<<get<0>(composition)<<endl;
    cout<<get<1>(composition)<<endl;
    cout<<get<2>(composition)<<endl;
    return 0;
}
