#include <iostream>
using namespace std;

ostream& snl(ostream& os) {
    return os << "\n";
}

template<class charT,  class traits>
basic_ostream<charT, traits>&
nl(basic_ostream<charT, traits>&os) {
    return os << charT(os.widen('\n'));
}

int main() {
    cout << "hi" << nl;
    cout << "你好" << snl;
}
