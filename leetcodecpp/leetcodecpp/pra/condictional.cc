#include <iostream>
using namespace std;

template<bool cond> struct Select{};

template<>
class Select<true> { 
    static void statement1() {
        cout << "This is statement1 executing\n";
    }
    public:
    static void f() {statement1();}
};


template<>
class Select<false> { 
    static void statement2() {
        cout << "This is statement2 executing\n";
    }
    public:
    static void f() {statement2();}
};

template<bool cond>
void execute() {
    Select<cond>::f();
}

int main() {
    execute<sizeof(int) == 4>();
}


