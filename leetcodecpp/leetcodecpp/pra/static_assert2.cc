#include <iostream>
using namespace std;

template<bool> struct StaticCheck {
    StaticCheck(...); 
};

template<> struct StaticCheck<false> {};

#define STATIC_CHECK(expr, msg) {\
    class Error_##msg {};       \
    sizeof((StaticCheck<expr>(Error_##msg()))); \
}

template<class To, class From>
To safe_cast(From from) {
    STATIC_CHECK(sizeof(From) <= sizeof(To), NarrowingConversion);
    return reinterpret_cast<To>(from);
}

int main() {
    void *p = 0;
    //int i = safe_cast<int>(p);
    char c = safe_cast<char>(p);
}
