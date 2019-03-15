#include <memory>
#include <iostream>
#include <cstddef>
using namespace std;

class TraceHeap {
    int i;
    public:
        static void* operator new(size_t siz) {
            void *p = ::operator new(siz);
            cout << "Allocating TraceHeap object on the heap"
                << "at address " << p << endl;
            return p;
        }

        static void operator delete(void *p) {
            cout << "Deleting TraceHeap object on the heap"
                << "at address " << p << endl;
            ::operator delete(p);
        }

        TraceHeap(int i) : i(i) {}
        int getVal() const {return i;}
};

int main() {
    auto_ptr<TraceHeap> pMyObject(new TraceHeap(5));
    cout << pMyObject->getVal() << endl;
}
