#include <stdio.h>
#include "log.h" 

int main(void) {
    log_trace("hello %s", "world");
    log_debug("hello %s", "world");
    log_error("hello %s", "world");
    return 0;
}
