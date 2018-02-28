#include"stdafx.h"
#include <cassert>
#include <iostream>
#include <typeinfo>

/* Objects of a class type that declares or inherits at least one virtual function are polymorphic objects.Within each polymorphic object, the implementation stores additional information(in every existing implementation, it is one pointer unless optimized out), which is used by virtual function calls and by the RTTI features(dynamic_cast and typeid) to determine, at run time, the type with which the object was created, regardless of the expression it is used in.
For non - polymorphic objects, the interpretation of the value is determined from the expression in which the object is used, and is decided at compile time.*/

struct Base1 {
	// polymorphic type: declares a virtual member
	virtual ~Base1() {}
};
struct Derived1 : Base1 {
	// polymorphic type: inherits a virtual member
};

struct Base2 {
	// non-polymorphic type
};
struct Derived2 : Base2 {
	// non-polymorphic type
};

struct S {
	char c;  // 1 byte value
			 // 3 bytes padding
	float f; // 4 bytes value
	bool operator==(const S& arg) const { // value-based equality
		return c == arg.c && f == arg.f;
	}
};


// objects of type S1 can be allocated at any address
// because both S1.a and S1.b can be allocated at any address
struct S1 {
	char a; // size: 1, alignment: 1
	char b; // size: 1, alignment: 1
}; // size: 2, alignment: 1

   // objects of type X1 must be allocated at 4-byte boundaries
   // because X1.n must be allocated at 4-byte boundaries
   // because int's alignment requirement is (usually) 4
struct X1 {
	int n;  // size: 4, alignment: 4
	char c; // size: 1, alignment: 1
			// three bytes padding
}; // size: 8, alignment: 4 


int amain() {
	assert(sizeof(S) == 8);
	S s1 = { 'a', 3.14 };
	S s2 = s1;
	reinterpret_cast<char*>(&s1)[2] = 'b'; // change 2nd byte
	assert(s1 == s2); // value did not change


	static const char c1 = 'x';
	static const char c2 = 'x';
	assert(&c1 != &c2); // same values, different addresses


	Derived1 obj1; // object1 created with type Derived1
	Derived2 obj2; // object2 created with type Derived2

	Base1& b1 = obj1; // b1 refers to the object obj1
	Base2& b2 = obj2; // b2 refers to the object obj2

	std::cout << "Expression type of b1: " << typeid(decltype(b1)).name() << ' '
		<< "Expression type of b2: " << typeid(decltype(b2)).name() << '\n'
		<< "Object type of b1: " << typeid(b1).name() << ' '
		<< "Object type of b2: " << typeid(b2).name() << '\n'
		<< "size of b1: " << sizeof b1 << ' '
		<< "size of b2: " << sizeof b2 << '\n';
	

	std::cout << "sizeof(S1) = " << sizeof(S1)
		<< " alignof(S1) = " << alignof(S1) << '\n';
	std::cout << "sizeof(X1) = " << sizeof(X1)
		<< " alignof(X1) = " << alignof(X1) << '\n';


	getchar();
	return 0;
}
