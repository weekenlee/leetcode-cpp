//#include"stdafx.h"

#include <iostream>
struct Base {
	virtual void f() {
		std::cout << "base\n";
	}

    virtual ~Base() {
        f();
        std::cout <<"Destru base"<<std::endl;
    }
};
struct Derived : Base {
	void f() override { // 'override' is optional
		std::cout << "derived\n";
	}
    ~Derived() {
        std::cout <<"Destru Deri"<<std::endl;
    }
};
int main()
{
	Base b;
	Derived d;

    return 0;

	// virtual function call through reference
	Base& br = b; // the type of br is Base&
	Base& dr = d; // the type of dr is Base& as  well
	br.f(); // prints "base"
	dr.f(); // prints "derived"

			// virtual function call through pointer
	Base* bp = &b; // the type of bp is Base*
	Base* dp = &d; // the type of dp is Base* as  well
	bp->f(); // prints "base"
	dp->f(); // prints "derived"

			 // non-virtual function call
	br.Base::f(); // prints "base"
	dr.Base::f(); // prints "base"

}
