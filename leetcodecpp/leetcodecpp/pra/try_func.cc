#include<iostream>
using namespace std;

int main() try {
    throw 4;
} catch (...) {
    cout <<"catch"<<endl;
}
