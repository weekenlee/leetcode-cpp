#include <stdio.h>
#include <string.h>

int main()
{
    char dest[] = "oldstring";
    char src[] =  "srcstring";
    printf("before: %s %s\n", dest, src);
    memmove(dest, src, 2);
    printf("after: %s %s\n", dest, src);
    return 0;
}
