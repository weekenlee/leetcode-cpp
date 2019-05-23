#include <stdio.h>
#include <string.h>

int main()
{
    char src[5], dest[5];
    strcpy(src, "abced");
    strcpy(dest, "abced");
    strcat(dest, src);//不够长，报错 

    printf("%s", dest);

    return 0;
}
