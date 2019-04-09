#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<regex.h>

#define MAX_LINE 1024

char* get_node_name(char* line) {
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
        return "no match";
    }else if(err){
        regerror(err,&reg,errbuf,sizeof(errbuf));
        return "no match";
    }

    for(int i=1;i<2 && pmatch[i].rm_so!=-1;i++){
        int len = pmatch[i].rm_eo-pmatch[i].rm_so;
        if(len){
            memset(match,'\0',sizeof(match));
            memcpy(match,line+pmatch[i].rm_so,len);
        }
    }

    char *result = malloc(sizeof(match));
    memcpy(result,match,sizeof(match));
    return result;
}

void process(int linenum, char* lines[]) {
    char* name = get_node_name(lines[linenum + 1]);
    if(strcmp(name, "no match") != 0) {
        printf("%s %lu\n", name, strlen(name));
    }
}

void process_file(const char* filename) {
    char *lines[65535];  /*所有行数*/
    int linenums[1024];  /*所有检查行数*/
    int count = 0;       /*linenums下标*/
    FILE *fp;            /*文件指针*/
    int len;             /*行字符个数*/
    int linenum=0;
    if((fp = fopen(filename,"r")) == NULL) {
        perror("fail to read");
        exit (1) ;
    }

    char buf[MAX_LINE];  /*一行*/
    while(fgets(buf,MAX_LINE,fp) != NULL) {
        len = strlen(buf);
        buf[len-1] = '\0';  /*去掉换行符*/
        lines[linenum] = (char*) malloc(sizeof(char) * len);
        memcpy(lines[linenum],buf,sizeof(char)*len);
        char *c2=strstr(buf, " ) ------------------------------------------------------------------------------------------------------------------------------");
        if(c2 != NULL) {
            //printf("%d \t %s\n",linenum, buf);
            linenums[count++] = linenum;
        }
        linenum++;
    }

    for(int i = 0; i < count; i++) {
        process(linenums[i], lines);
    }
    
    fclose(fp);
}


int main() {
    process_file("电厂侧合甲线a相重合闸.lis");
    return 0;
}