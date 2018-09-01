#include<iostream>

using namespace std;

enum class Direction : unsigned int {
    North,
    East,
    South,
    West
};

int main() {
    Direction driving = Direction::North;

    if (driving == Direction::North) {
        cout << "dragons ahead" <<endl;
    }
}
