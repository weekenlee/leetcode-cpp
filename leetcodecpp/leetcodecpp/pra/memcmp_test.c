#include <stdio.h>
#include <string.h>

int main() {
    char str1[15];
    char str2[15];
    int ret;

    memcpy(str1, "abcdef", 6);
    memcpy(str2, "aBcdef", 6);

    ret = memcmp(str1, str2, 5);
    printf("%d\n", ret);
    return 0;
}
