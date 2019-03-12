#include<iostream>

using namespace std;

struct Date {
    int month;
    int year;
};

istream& operator >> (istream &is , Date& d) {
    is >> d.month;
    char dash;
    is >> dash;
    while(dash != '-') {
        is.setstate(ios::failbit);
        is >> dash;
    }
    is >> d.year;
}

int main() {
   Date d;
   cin >> d;

   cout << d.month<< endl;
   cout << d.year<< endl;
}
