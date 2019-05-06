#include <iostream>
#include <memory>
#include "defer.hpp"

using namespace std;
using namespace lwj;

void test() {

    defer defer_exit, defer_fail(defer::execution::exception);

    defer_exit += [](){ cout << "defer end"<<endl;};
    defer_fail += [](){ cout << "defer fail"<<endl; throw 1;};

    defer_exit += [](){ cout << "defer end2"<<endl;};
    defer_fail += [](){ cout << "defer fail2"<<endl;};
    
    cout << "do thing..."<<endl;


}


int main() {

    shared_ptr<int> x(NULL, [&](int *) { cout << "defer by smart pointer"<<endl; });

    test();
}
