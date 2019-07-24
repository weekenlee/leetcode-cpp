#include <iostream>
#include <vector>
#include "../purge.h"

using namespace std;

class Security {
    protected:
        enum { BASEID = 0 };
    public:
        virtual ~Security() {}
        virtual bool isA(int id) { return (id == BASEID); }
};

class Stock : public Security {
    typedef Security Super;
    protected:

}
