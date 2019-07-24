#include <typeinfo>
#include <iostream>

using namespace std;

class Security {
    public:
        virtual ~Security() {}
};

class Stock : public Security {};
class Bond : public Security {};

class Investment : public Security {
    public:
        void special() {
            cout << "special investment function" <<endl;
        }
};

class Metal : public Investment {};

int main() {
    Metal m;
    Security &s = m;
    try {
        Investment& c = dynamic_cast<Investment&>(s);
        cout << "It's an Investment" <<endl;
    }catch(bad_cast&) {
        cout << "s is not an investment type" << endl;
    }
    try {
        Bond& b = dynamic_cast<Bond&>(s);
        cout << "It's an Bond" <<endl;
    }catch(bad_cast&) {
        cout << "s is not an Bond type" << endl;
    }
}
