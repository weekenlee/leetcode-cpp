#include <iostream>
#include <string>

using namespace std;

class Fruit {
    public:
        Fruit(string &label_) : label(label_) {}
        Fruit(string &&label_) : label(move(label_)) {}

        Fruit(const Fruit &other) : label(other.label) {
            cout << "copy constructor" <<endl;
        }

        Fruit& operator=(Fruit& other) {
            cout << "copy assign" <<endl;
            label = other.label;
            return *this;
        }

        Fruit(Fruit &&other):label(move(other.label)) {
            cout <<"move constructor "<<endl;
        }

        Fruit& operator=(Fruit&& other) {
            cout <<"move assign" <<endl;
            label = move(other.label);
            return *this;
        }
        
        string getLabel() {return label;}

    private:
        string label;
};

int main() {
    Fruit firstFruit("extra juicy");
    Fruit secondFruit(firstFruit);
    Fruit thirdFruit(move(firstFruit));
    cout << firstFruit.getLabel() <<endl;
    cout << thirdFruit.getLabel() <<endl;

    secondFruit = thirdFruit;
    firstFruit = move(thirdFruit);
}
