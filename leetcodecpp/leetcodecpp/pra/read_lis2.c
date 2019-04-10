#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "getmem.h" 

#define MAX_LINE 1024

int get_node_name(char* line, char* result) {
    char *pattern = "Statistical distribution of peak voltage at node  \"(.*)\".*";
    char errbuf[1024];
    char match[1024];
    regex_t reg;
    int err,nm = 10;
    regmatch_t pmatch[nm];

    if(regcomp(&reg,pattern,REG_EXTENDED) < 0){
        regerror(err,&reg,errbuf,sizeof(errbuf));
        printf("err:%s\n",errbuf);
    }

    err = regexec(&reg,line,nm,pmatch,0);

    if(err == REG_NOMATCH){
        return 0; 
    }else if(err){
        regerror(err,&reg,errbuf,sizeof(errbuf));
        return 0; 
    }

    for(int i=1;i<2 && pmatch[i].rm_so!=-1;i++){
        int len = pmatch[i].rm_eo-pmatch[i].rm_so;
        if(len){
            memset(match,'\0',sizeof(match));
            memcpy(match,line+pmatch[i].rm_so,len);
        }
    }

    result = malloc(sizeof(match));
    memcpy(result,match,sizeof(match));
    return 1;
}


void process_file(const char* filename) {
    FILE *fp;            /*文件指针*/
    char buf[MAX_LINE];  /*一行*/

    if((fp = fopen(filename,"r")) == NULL) {
        perror("fail to read");
        exit (1) ;
    }

    int len;
    while(fgets(buf,MAX_LINE,fp) != NULL) {
        len = strlen(buf);
        buf[len-1] = '\0';  /*去掉换行符*/
        char *c2=strstr(buf, " ) ------------------------------------------------------------------------------------------------------------------------------");
        if(c2 != NULL) {
            /*处理接下来一行，获取名称*/
            fgets(buf,MAX_LINE,fp);
            buf[len-1] = '\0';  /*去掉换行符*/
            char *result;
            char *name = NULL;
            int res = get_node_name(buf,name);
            int mem = get_rmem(getpid());
            if(name != NULL) {
                printf("%s \n",name);
                free(name);
            }
        }
    }
    
    fclose(fp);
}


int main() {
    process_file("电厂侧合甲线a相重合闸.lis");
    return 0;
}
