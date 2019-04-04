#include <iostream>
#include <typeinfo>

using namespace std;

class One {
    class Nested {};
    Nested *n;
public:
    One() : n (new Nested) {}
    ~One() {delete n;}
    Nested* nested() {return n;}
};

int main() {
   One o;
   cout << typeid(o).name()<<endl;
   cout << typeid(*o.nested()).name()<<endl;

   void* v = new One;
  // One *p = dynamic_cast<One*>(v);
  //cout << typeid(*v).name()<<endl;
}
