#include <iostream>
#include <csetjmp>

using namespace std;

class Rainbow {
    public:
        Rainbow() { cout << "Rain bow" << endl; }
        ~Rainbow() { cout << "~Rain bow" << endl; }
};

jmp_buf kansas;

void oz() {
    Rainbow rb;
    for(int i = 0 ; i < 3; i++) {
        cout << "there is no place like home" <<endl;
    }

    throw 47;
}

int main() {
    try {
        cout << "tornado , withc , mi" <<endl;
        oz();
    } catch(...){
        cout << "end" <<endl;
    }
}
