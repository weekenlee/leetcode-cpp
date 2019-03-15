#include <iostream>
#include <memory>
#include <cstddef>
using namespace std;

class Cat {
    public:
        Cat() {cout <<"Cat()"<< endl;}
        ~Cat() {cout <<"~Cat()"<< endl;}
};
/*
class Dog{
    public:
        void* operator new(size_t sz) {
           cout << "allocating a dog" <<endl; 
           throw 47; //不要在构造函数中使用，否则异常
        }

        void operator delete(void *p) {
            cout <<"deallocating a dog" <<endl;
            ::operator delete(p);
        }
};
*/

class Dog{
    public:
        Dog() {
           cout << "allocating a dog" <<endl; 
           throw 47; //不要在构造函数中使用，否则异常
        }

        void d() {
            throw 47;
        }

        ~Dog() {
            cout <<"deallocating a dog" <<endl;
        }
};

class UseResources {
    Cat *bp;
    Dog *op;
    public:
    UseResources(int count = 1) {
        cout << "use resource() "<<endl;
        bp = new Cat[count];
        op = new Dog;
    }

    ~UseResources() {
        cout <<"~UseResource()" <<endl;
        delete []bp;
        delete op;
    }
};

class UseResources_smart {
    shared_ptr<Cat> bp ;
    shared_ptr<Dog> op ;
    public:
    UseResources_smart() {
        cout << "use resource_smart() "<<endl;
        bp  = make_shared<Cat>();
        op = make_shared<Dog>();
        op->d();
    }

    ~UseResources_smart() {
        cout <<"~UseResource_smart()" <<endl;
    }
};

int main() {
    try {
        UseResources_smart ur;//可以调用
        UseResources urr(3); //析构无法调用
    }catch(int) {
        cout <<"inside handler"<<endl;
    }
}
