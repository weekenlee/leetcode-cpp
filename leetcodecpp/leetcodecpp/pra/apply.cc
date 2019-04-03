#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template<class cont, class ptrmemfun> 
void apply(cont &c, ptrmemfun f) {
    typename cont::iterator it = c.begin();
    while ( it != c.end()) {
        ((*it).*f)();
        ++it;
    }
}

class z {
    int i;
public:
    z(int ii) : i(ii) {}
    void g() {++i;}
    friend ostream& operator<<(ostream& os, const z& z) {
        return os << z.i;
    }
};


int main() {
    ostream_iterator<z> out(cout , " ");
    vector<z> vz;
    for(int i = 0; i <10; i++) {
        vz.push_back(z(i));
    }
    copy(vz.begin(), vz.end(), out);
    cout <<endl;
    apply(vz, &z::g);
    copy(vz.begin(), vz.end(), out);
    cout <<endl;
}
