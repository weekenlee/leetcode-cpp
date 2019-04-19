#include <iostream>
#include <cstddef>
using namespace std;

int main() {
    struct Old {
        int x;
        char padding[16 - sizeof(int)];
    };
    cout << "sizeof(Old) : " << sizeof(Old)<<endl;

    struct alignas(16) New {
        int x;
    };
    cout << "sizeof(New) : " << sizeof(New)<<endl;

    alignas(16) int x{}, y{};
    alignas(16) int z{};

    ptrdiff_t delta1 = (uint8_t*)&y - (uint8_t*)&x;
    ptrdiff_t delta2 = (uint8_t*)&z - (uint8_t*)&y;

    cout << "Address of 'x' \t :"<<&x<<endl;
    cout << "Address of 'y' \t :"<<&y<<endl;
    cout << "Address of 'z' \t :"<<&z<<endl;

    cout <<"Distance 'x' to 'y' :" << delta1 <<endl;
    cout <<"Distance 'y' to 'z' :" << delta2 <<endl;


    struct Full {
        alignas(32) char c;
        alignas(16) int x, y;
    };
    cout << "sizeof(Full): "<<sizeof(Full)<<endl;
    cout << "outset c in (Full): "<<offsetof(Full, c)<<endl;
    cout << "outset x in (Full): "<<offsetof(Full, x)<<endl;
    cout << "sizeof x in (Full): "<<sizeof(Full.x)<<endl;
    cout << "outset y in (Full): "<<offsetof(Full, y)<<endl;
}
