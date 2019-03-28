#include <iostream> 
using namespace std;

template<bool cond> struct Select{};

template<>
class Select<true> {
    static void statment1() {
        cout << "statement1" <<endl;
     }
    public:
    static void f() {statment1();}
} ;

template<>
class Select<false> {
    static void statement2() {
        cout <<"statement2" <<endl;
    }
    public:
    static void f() {statement2();}
};

template<bool cond> void execute() {
    Select<cond>::f();
}

int main() {
    execute<sizeof(int) == 4>();
}
