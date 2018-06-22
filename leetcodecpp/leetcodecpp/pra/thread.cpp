#include<iostream>
#include<thread>
#include<unistd.h>

using namespace std;

void thread1() {
    for(int i = 0; i < 5; i++) {
        cout<<"Thread 01 is working!"<<endl;
        sleep(1);
    }
}

int main() {
    thread task01(thread1);
    task01.join();
    return 0;
}
