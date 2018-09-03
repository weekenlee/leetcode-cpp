#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float x = 1.3333;
    float y = 3.461;
    float z = 9.023;

    cout << "fma " << fma(x, y, z) <<endl;

    cout <<"hypot " << hypot(x, y) <<endl;

    cout << "NaN" << isnan(z) <<endl;
}
