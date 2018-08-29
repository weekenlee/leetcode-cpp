#define _GLIBCCC_USE_NANOSLEEP

#include<iostream>
#include<chrono>
#include<thread>

using namespace std;

int main() {
    const chrono::seconds sec(chrono::hours(1) + chrono::minutes(9) + chrono::seconds(8));
    cout << "1 h 9m 8s = " << sec.count() <<" s " <<endl;

    const auto start(chrono::steady_clock::now());
    this_thread::sleep_for(chrono::seconds(3));
    const auto end(chrono::steady_clock::now());

    chrono::nanoseconds durations(end - start);
    cout<<"duration of section:" << durations.count() << "ns" <<endl;
    cout<<"duration of section:" << chrono::duration_cast<chrono::microseconds>(durations).count() << "ms"<<endl;
    return 0;
}
