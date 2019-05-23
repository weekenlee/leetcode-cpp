#include <wchar.h>
#include <stdio.h>

int main(void)
{
    wchar_t input[] = L"你好啊哈哈啊诶呀啊";
    wprintf(L"before: %ls", input);
    return 0;
}
