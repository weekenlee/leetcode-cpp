#include <iostream>
using namespace std;

template<class T> void f(T) {
    cout <<"T" <<endl;
}

template<class T> void f(T*) {
    cout <<"T*" <<endl;
}

template<class T> void f(const T*) {
    cout <<"const T*" <<endl;
}

int main() {
    f(0);
    int i = 0;
    f(&i);
    const int j = 0;
    f(&j);
    return 0;
}
