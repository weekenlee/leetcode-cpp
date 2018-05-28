#include<iostream>
#include<stdexcept>
#include<memory>
#include<vector>
#include<fstream>


struct intArray{
    intArray() : p(nullptr) {

    }

    explicit intArray(std::size_t s):
        p(new int[s]) {

        }

    ~intArray(){
        std::cout<<"delete in des"<<std::endl;
        delete[] p;
    }

    int *p;
};


void exercise(int *b, int *e) {
    std::vector<int> v(b, e);

    intArray p(v.size());

    std::ifstream in("ints");
}

int main() {

    int a[6] = {
        1, 2, 3,4,5,6
    };

    int *aa = &a[2];
    int *bb = &a[5];
    exercise(aa, bb);

    std::range_error r("error");
    throw r;

    return 0;
}
