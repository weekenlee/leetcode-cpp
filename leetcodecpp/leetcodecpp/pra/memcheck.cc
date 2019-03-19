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
        }
        --nptrs;
    }


    struct Sentinel {
        ~Sentinel() {
            if(nptrs > 0) {
                printf("Leaked memory at:\n");
                for(size_t i = 0; i < nptrs; ++i) {
                    printf("\t%p (file: %s, line %ld)\n", 
                            memMap[i].ptr, memMap[i].file, memMap[i].line);
                } 
            } else{
               printf("no user memory leak!\n");
            }

        }
    };

    Sentinel s;
}

void*
operator new(size_t siz, const char* file, long line) {
    void *p = malloc(siz);
    if(activeFlag) {
        if(nptrs == MAXPTRS) {
            printf("memory map too smalll(increas MAXPTRS)\n");
            exit(1);
        }
        memMap[nptrs].ptr = p;
        memMap[nptrs].file = file;
        memMap[nptrs].line = line;
        ++nptrs;
    }
    if(traceFlag) {
        printf("Allocated %u bytes at address %p ", siz, p);
        printf("file : %s ,line: %ld \n", file ,line);
    }
    return p;
}

void *
operator new[](size_t siz, const char* file, long line) {
    return operator new(siz, file, line);
}

void operator delete(void *p) {
    if(findPtr(p) >= 0) {
        free(p);
        assert(nptrs > 0);
        delPtr(p);
        if(traceFlag) {
            printf("Deleted memory at address %p \n", p);
        }
    }else if(!p && activeFlag) {
        printf("Attempt to delete unknown pointer: %p \n", p);
    }
}

void operator delete[](void *p) {
    operator delete(p);
}
