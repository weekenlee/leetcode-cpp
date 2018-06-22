#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

struct arg {
    int id;
    char name[80];
};

void *thread1(void* args) {
    struct arg *a = (struct arg*)args;
    for(int i = 0; i < 10; i++) {
        printf("thread %d-%s %d\n",a->id, a->name, i);
        sleep(1);
    }
}

void *thread2(void *args) {
    struct arg *a = (struct arg*)args;
    for(int i = 0; i < 10; i++) {
        printf("thread %d-%s %d\n",a->id, a->name, i);
        sleep(2);
    }
}

int main(int argc, char **argv){
    pthread_t id1,id2;
    struct arg a1, a2;
    a1.id = 1;
    a1.name[0]='l';
    a1.name[1]='w';
    a1.name[2]='j';
    a1.name[3]='\0';
    a2.id = 2;
    a2.name[0]='h';
    a2.name[1]='h';
    a2.name[2]='h';
    a2.name[3]='\0';
    int ret = 0;
    ret = pthread_create(&id1, NULL, (void*)thread1, (void*)&a1);
    if(ret) {
        printf("create pthread error!\n");
        return -1;
    }
    ret = pthread_create(&id2, NULL, (void*)thread2, (void*)&a2);
    if(ret) {
        printf("create pthread error!\n");
        return -1;
    }
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    return 0;
}
