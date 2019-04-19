#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
   string s = "helloworld";
   char ss[2] ;
   sprintf(ss, "%c%d", s[1], 1);
   cout << ss<<endl;
   string sss = s[1] + std::to_string(1);
   cout << sss <<endl;
   return 0;
}
