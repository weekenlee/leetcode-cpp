#include<iostream>
#include<future>
#include<unistd.h>

using namespace std;

int cfunc() {
    sleep(2);
    return 42;
}

int main() {
    future<int> result = async(launch::async, cfunc);
    sleep(5);
    cout << "we need the result now, and it is:" <<result.get() <<endl;
}
