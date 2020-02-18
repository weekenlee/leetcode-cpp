#include <stdio.h>
#include "log.h" 

int main(void) {
    log_trace("hello %s", "world");
    return 0;
}
