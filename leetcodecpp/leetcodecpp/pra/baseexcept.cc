#include <iostream>
using namespace std;

class X {
    public:
        class Trouble {};
        class Small : public Trouble {};
        class Big: public Trouble {};
        void f() {throw Big();}
};

int main() {
    X x;
    try {
        x.f();
    }catch(X::Trouble&) {
        cout <<"Trouble"<<endl;
    }catch(X::Small&) {
        cout <<"Small"<<endl;
    }catch(X::Big&) {
        cout <<"Big"<<endl;
    }
}
