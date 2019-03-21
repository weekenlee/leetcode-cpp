#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#if defined(__GNUC__) || defined(__MWERKS__)
#include<sys/stat.h>
#elif defined(_MSC_VER) || defined(__DMC__) || defined(__BORLANDC__)
#include<dirent.h>
#else
#error Compiler not support
#endif

bool exist(string fname) {
    size_t len = fname.length();
    if(fname[len - 1] != '/' && fname[len - 1] != '\\') {
        fname.append("/");
    }
    fname.append("000.tmp");
    ofstream outf(fname.c_str());
    bool existFlag = outf;
    if(outf) {
        outf.close(); 
        remove(fname.c_str());
    }
    return existFlag;
}

int main() {
    cout << exist("/home/lwj/code/github/leetcode-cpp/leetcodecpp/leetcodecpp/pra") <<endl;
}
