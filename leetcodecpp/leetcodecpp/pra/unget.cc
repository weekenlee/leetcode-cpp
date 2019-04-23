#include <iostream>

using namespace std;

int main() {
    char c;
    string all;
    while (cin >> c) {
        if ( c == 'q') {
            break;
        }
        if (isdigit(c)) {
            cin.unget();
        }
        all += c;
    }
    cout << all <<endl;
}
