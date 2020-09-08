#include "fork.h"

void function_fork(void)
{
/**********************************************************************
	pid_t fpid;	//fpid表示fork函数的返回值
	int count = 0;

	fpid = fork();

	if(fpid < 0)
	{
		printf("error in fprk!\n");
	}
	else if(fpid == 0)
	{
		printf("the child process,process id is %d\n",getpid());
		count++;
	}
	else
	{
		printf("the parent process,process id is %d\n",getpid());
		count++;
	}
	printf("total is %d\n",count);
**********************************************************************/

    int i = 0;
    printf("i    ch/pa    ppid    pid    fpid\n");
     
    // ppid指当前进程的父进程pid
    // pid指当前进程的pid,
    // fpid指fork返回给当前进程的值
    for (i = 0; i < 2; i++)
    {
        pid_t fpid = fork();
        if (fpid == 0)
        {
            printf("%d child  %4d %4d %4d\n", i, getppid(), getpid(), fpid);
        }
        else
        {
            printf("%d parent %4d %4d %4d\n", i, getppid(), getpid(), fpid);
        }
    }
}
