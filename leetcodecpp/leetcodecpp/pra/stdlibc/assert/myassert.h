#ifndef MY_ASSERTH
#define MY_ASSERTH

#undef myassert

#ifdef NDEBUG
    #define myassert(test) ((void)0)
#else
    void _Assert(char*);
    
    #define _STR(x) _VAL(x)
    #define _VAL(x) #x
    #define myassert(test) ((test) ? (void)0 \
            : _Assert (__FILE__ ":" _STR(__LINE__) _STR(-) "" #test))
#endif

#endif
