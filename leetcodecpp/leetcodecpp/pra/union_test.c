#include <stdio.h>

union MYTYPE {
    char c;
    int b[3];
} my_type;

int main() {
    my_type.b[0] = 1;
    my_type.b[1] = 2;
    my_type.b[2] = 3;
    printf("%d\n", my_type.c) ;
    return 0;
}
