#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int i = 47;
    float f = 2300114.414159;
    char* s = "Is there any more?";

    cout << setiosflags(ios::unitbuf | ios::showbase | ios::uppercase | ios::showpos);
    cout << i << endl;
    cout << hex << i <<endl;
    cout << oct << i <<endl;

    cout << resetiosflags(ios::showbase) << dec << setfill('0') ;
    cout << "fill char: " << cout .fill() << endl;
    cout << setw(10) << i <<endl;

    cout.setf(ios::right, ios::adjustfield);
    cout << setw(10) << i <<endl;
    cout << i << endl;

    cout <<resetiosflags(ios::showpos) << setiosflags(ios::showpoint) << "prec = " << cout.precision() <<endl;
    cout.setf(ios::scientific, ios::floatfield);
    cout << f << resetiosflags(ios::uppercase) <<endl;
    cout.setf(ios::fixed, ios::floatfield);
    cout<<f<<endl;
    cout<<f<<endl;

    cout << setprecision(20);
    cout <<resetiosflags(ios::showpos) << setiosflags(ios::showpoint) << "prec = " << cout.precision() <<endl;
    cout.setf(ios::scientific, ios::floatfield);
    cout << f << resetiosflags(ios::uppercase) <<endl;
    cout.setf(ios::fixed, ios::floatfield);
    cout<<f<<endl;
    cout<<f<<endl;

}
