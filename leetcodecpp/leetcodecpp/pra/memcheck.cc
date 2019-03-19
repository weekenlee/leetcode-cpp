#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>
using namespace std;

#undef new

bool traceFlag = true;
bool activeFlag = true;

namespace {
    
    //memory map entry type
    struct Info {
        void* ptr;
        const char *file;
        long line;
    };

    //memory map data
    const size_t MAXPTRS = 10000u;
    Info memMap[MAXPTRS];
    size_t nptrs = 0;

    int findPtr(void *p) {
        for(size_t i = 0; i < nptrs; ++i) {
            if(memMap[i].ptr == p) {
                return i;
            }
        }
        return -1;
    }

    void delPtr(void *p) {
        int pos = findPtr(p);
        assert(pos >= 0);
        for(size_t i = pos; i<nptrs-1; ++i) {
            memMap[i] = memMap[i+1];
            --nptrs;
        }
    }

};
