#include <cassert>
#include <limits>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Fixw {
    string str;
    public:
        Fixw(const string& s, int width) :str(s, 0, width) {
        }

        friend ostream& operator <<(ostream& os , const Fixw& fw) {
            return os << fw.str;
        }
};


typedef unsigned long ulong;
class Bin {
    ulong n;
    public:
        Bin(ulong nn) {n = nn;}

        friend ostream& operator <<(ostream& os, const Bin& b) {
            const ulong ULMAX = numeric_limits<ulong>::max();
            ulong bit = ~(ULMAX >> 1);
            while(bit) {
                os << (b.n & bit ? '1':'0');
                bit >>= 1;
            }
            return os;
        }

};

int main() {
    string words = "hello world";
    ostringstream s;
    s << Fixw(words, 1);
    assert(s.str() == words.substr(0,1));

    ostringstream xs, ys;
    xs << Bin(0xCAFFEBABEUL);
    cout << xs.str() << endl;
}
