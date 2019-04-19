#include "myassert.h"
#include <stdio.h>
#include <stdlib.h>

void _Assert(char* mesg) {
    fputs(mesg, stderr);
    fputs(" -- assertion fail\n", stderr);
    abort();
}
