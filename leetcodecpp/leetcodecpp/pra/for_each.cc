#include <vector>
#include <iostream>
#include <algorithm>

class Counted {
    static int count;
    char * ident;

    public:
    Counted(char *id) : ident(id) {++count;}
    ~Counted() {
        std::cout << ident << " count = " << --count << std::endl;
    }
};

class CountedVector : public std::vector<Counted*> {
    public:
        CountedVector(char *id) {
            for(int i = 0; i < 5; i++)  {
                push_back(new Counted(id));
            }
        }
};

int Counted::count = 0;


template<class T> class DeleteT {
    public:
        void operator()(T *x) {delete x;}
};

template<class T> 
void wipe(T* x) {
    delete x;
}

int main() {
    CountedVector B("tow");
    std::for_each(B.begin(), B.end(), DeleteT<Counted>());
    CountedVector C("three");
    std::for_each(B.begin(), B.end(), wipe<Counted>);
}
