#include <stdio.h>
#include <string.h>

int main() 
{
    const char str[] = "http://www.runoob.com";
    const char ch = '.';
    char *ret;
    ret = (char*) memchr(str, ch, strlen(str));
    printf("|%c| 之后的字符串是 |%s|\n", ch, ret);
    return 0;
}

