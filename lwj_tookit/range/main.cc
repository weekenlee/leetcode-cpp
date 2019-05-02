#include <iostream>
#include "range.hpp" 

using namespace std;

int main() {
    std::cout << "range(15) ";
    for (int i : range(15)) {
        std::cout << i << " ";
    }
    std::cout << endl;

    std::cout << "range(2,9) ";
    for (int i : range(2, 9)) {
        std::cout << i << " ";
    }
    std::cout << endl;

    std::cout << "range(3,20, 2) ";
    for (int i : range(3, 20, 2)) {
        std::cout << i << " ";
    }
    std::cout << endl;
}
