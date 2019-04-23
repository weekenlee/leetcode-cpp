#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out1("txt1");
    ofstream out2("txt2");
    out1.tie(&out2);
    out1<<"hhhllo"<<endl;
    out1.close();
    out2.close();

    char i;
    //cin.tie(&cout);
    cout << "enter a number:"<<endl;
    while (cin >> i) {
        cout << i <<endl;
    }


    ofstream ofs;
    ofs.open("test.txt");
    cin.tie(&ofs);
    char c;
    while(cin >> c) {
        ofs << c;
    }
    ofs.close();
}
