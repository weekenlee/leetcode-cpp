#include<cassert>
#include<cmath>
#include<iomanip>
#include<limits>
#include<sstream>
#include<string>
#include<iostream>

using namespace std;

int main() {
    istringstream is("one 2.34 first");
    string temp;
    /*
    float hi;
    string temp2;
    is >> temp >>hi >>temp2;
    cout <<temp << " " << hi <<" " <<temp2<<endl;
    */

    is >> setw(2)>>temp;
    cout << temp<<endl;
    is >> setw(2) >> temp;
    cout << temp<<endl;

    double f;
    is >> setw(1) >> f;
    cout << f << endl;
}
