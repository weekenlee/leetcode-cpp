#include <iostream>
using namespace std;

class Excep1{};

class Excep2{
    public:
        Excep2(const Excep1&) {}
};

void f() {throw Excep1();}

int main() {
    try {
        f();
    }catch(Excep2&) {
        cout << "catch 2" <<endl;
    }catch(Excep1&) {
        cout << "catch 1" <<endl;
    }
}
