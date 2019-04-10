//get_mem.h
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <assert.h>
#define VMRSS_LINE 15//VMRSS所在行, 注:根据不同的系统,位置可能有所区别.
#define pid_t int

int get_phy_mem(const pid_t p)
{
    char file[64] = {0};//文件名
    FILE *fd;   //定义文件指针fd
    char line_buff[256] = {0}; //读取行的缓冲区
    sprintf(file,"/proc/%d/status",p);
    fprintf (stderr, "current pid:%d\n", p);
    fd = fopen (file, "r"); //以R读的方式打开文件再赋给指针fd
    //获取vmrss:实际物理内存占用
    int i;
    char name[32];//存放项目名称
    int vmrss;//存放内存
    //读取VmRSS这一行的数据
    for (i=0;i<VMRSS_LINE-1;i++)
    {
     char* ret = fgets (line_buff, sizeof(line_buff), fd);
    }
    char* ret1 = fgets (line_buff, sizeof(line_buff), fd);
    sscanf (line_buff, "%s %d", name,&vmrss);
    fprintf (stderr, "====%s：%d====\n", name,vmrss);
    fclose(fd);  //关闭文件fd
    return vmrss;
}   


int get_rmem(pid_t p)
{   
    return get_phy_mem(p);
}   

int get_total_mem()
{   
    const char* file = "/proc/meminfo";//文件名
    FILE *fd;   //定义文件指针fd
    char line_buff[256] = {0}; //读取行的缓冲区
    fd = fopen (file, "r"); //以R读的方式打开文件再赋给指针fd
    //获取memtotal:总内存占用大小
    int i;
    char name[32];//存放项目名称
    int memtotal;//存放内存峰值大小
    char*ret = fgets (line_buff, sizeof(line_buff), fd);//读取memtotal这一行的数据,memtotal在第1行
    sscanf (line_buff, "%s %d", name,&memtotal);
    fprintf (stderr, "====%s：%d====\n", name,memtotal);
    fclose(fd);  //关闭文件fd
    return memtotal;
}
