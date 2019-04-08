#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024

void process_file(const char* filename) {
    char buf[MAX_LINE];  /*缓冲区*/
    FILE *fp;            /*文件指针*/
    int len;             /*行字符个数*/
    if((fp = fopen(filename,"r")) == NULL) {
        perror("fail to read");
        exit (1) ;
    }

    while(fgets(buf,MAX_LINE,fp) != NULL) {
        len = strlen(buf);
        buf[len-1] = '\0';  /*去掉换行符*/
        char *c2=strstr(buf, " ) ------------------------------------------------------------------------------------------------------------------------------");
        if(c2 != NULL) {
            printf("%s\n", buf);
        }
    }

    fclose(fp);
}


int main() {
    process_file("电厂侧合甲线a相重合闸.lis");
    process_file("电厂侧合甲线a相重合闸.lis");
    process_file("电厂侧合甲线a相重合闸.lis");
    return 0;
}