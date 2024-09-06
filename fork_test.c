#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    //调用fork之前  代码都在父进程中运行
    printf("面朝大海,春暖花开,getpid=%d\n",getpid());
   // while(1);

    //使用fork创建子进程
    /**
     * __pid_t fork (void)
     * 不需要传参
     * return : int 进程号
     *        (1) : -1出错
     *        (2) : 父进程中表示子进程的PID 
     *        (3) : 子进程中显示为0
     * 
     */
    pid_t pid = fork();  //老学员推荐新学员

    //从fork之后,所有的代码都是在父子进程中各自执行一次的  
    //父进程表示的是子进程的号 >0 ;子进程显示0:表示子进程
   // printf("pid=%d\t\n",pid);
    if(pid < 0)
    {
        printf("新学员加入失败\n");
        return 1;
    }
    else if(pid == 0)   //子进程执行这段代码
    {
        //执行单独子进程代码
        //子进程的PID 就等于0
        printf("新学员%d执行成功,他是老学员%d推荐的\n",getpid(),getppid());
    }
    else{     //父进程执行这段代码
        //执行单独父进程代码
        //父进程的pid表示子进程的ID 号
        printf("老学员%d继续深造,他推荐了%d\n",getpid(),pid);

    }


    return 0;
}
