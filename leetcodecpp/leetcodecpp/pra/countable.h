#ifndef COUNTABLE_H
#define COUNTABLE_H

#include<assert>

class countable {
    long count;
protected:
    countable() {count = 0;}
    virtual ~countable() { assert(count == 0);}
public:
    long attach() {return ++count;}
    long detach() {
        return (--count > 0) ? count : (delete this, 0);
    }

    long refcount() const {return count;}

};

#endif
