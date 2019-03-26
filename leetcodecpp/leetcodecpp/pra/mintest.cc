#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

template<class T> const T& mymin(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template<>
const char*  const& mymin<const char*>(const char* const& a,const char* const& b) {
    return (strcmp(a , b) < 0) ? a : b;
}

int main() {
    const char *s22 = "hello";
    const char *s11 = "hello";
    std::string s1 = "hello";
    std::string s2 = "hello";
    cout <<mymin(s1, s2)<<endl;
    cout <<mymin<>(s11,s22)<<endl;
}
