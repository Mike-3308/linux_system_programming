#include "fork.h"

void function_fork(void)
{
/**********************************************************************
	pid_t fpid;	//fpid��ʾfork�����ķ���ֵ
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
     
    // ppidָ��ǰ���̵ĸ�����pid
    // pidָ��ǰ���̵�pid,
    // fpidָfork���ظ���ǰ���̵�ֵ
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
