#include <bitset>
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

template<class charT, size_t N>
basic_string<charT> bitsetToString(const bitset<N>& bs) {
    return bs.template to_string<charT, char_traits<charT>,
           allocator<charT>>();
}

int main() {
    bitset<10> bs;
    bs.set(1);
    bs.set(5);
    cout <<bs <<endl;
    string s = bitsetToString<char>(bs);
    cout << s<<endl;
}
