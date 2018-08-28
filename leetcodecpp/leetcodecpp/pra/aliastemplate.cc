#include<iostream>
#include<tuple>

using namespace std;

template<class ... Types>
using Composition = tuple<int, Types ...>;

int main() 
{
    Composition<float, string> com(1,2.3f,"name");
    cout<<get<0>(com)<<endl;
    cout<<get<1>(com)<<endl;
    cout<<get<2>(com)<<endl;
    return 0;
}
