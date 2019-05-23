#include <wchar.h>
#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");
    wchar_t input[] = L"你好啊哈a哈啊诶呀啊ab";
    printf("before: %ls\n", input);

    wchar_t *buffer;
    wchar_t *token = wcstok(input, L"啊", &buffer);
    while(token) {
        printf("%ls\n", token);
        token = wcstok(NULL, L"啊", &buffer);
    }
    return 0;
}
