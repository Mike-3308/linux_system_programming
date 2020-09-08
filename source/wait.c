#include "wait.h"

void function_wait()
{
/**********************************************************************
	pid_t pr, pc;
 
    do
    {
        pr = waitpid(pc, NULL, WNOHANG);
 
        if (pr == 0)
        {
            printf("No child exited\n");
            sleep(1);
        }
 
    }
    while (pr == 0);
 
    if (pr == pc)
    {
        printf("successfully get child %d\n", pr);
    }
    else
    {
        printf("some error occured\n");
    }
**********************************************************************/
/**********************************************************************
	pid_t child;
    int i;
 
    child = fork();
 
    if (child < 0)
    {
        printf("create failed!\n");
        exit(1);
    }
    else if (0 == child)
    {
        printf("this is the child process pid= %d\n", getpid());
 
        for (i = 0; i < 5; i++)
        {
            printf("this is the child process print %d !\n", i + 1);
        }
 
        printf("the child end\n");
    }
    else
    {
        printf("this is the parent process, ppid=%d\n", getppid());
        printf("parent wait the child end\n");
		
        wait(&child);
		
        printf("parent end\n");
    }
**********************************************************************/
    pid_t pid;
    char *msg;
    int i;
    int exit_code;
 
    printf("how to get exit code\n");
    pid = fork();
 
    if (pid == 0)       /* 子进程 */
    {
        msg = "child process is running";
        i = 5;
        exit_code = 37;
    }
    else if (pid > 0)    /* 父进程 */
    {
        exit_code = 0;
    }
    else
    {
        perror("process creation failed\n");
        exit(1);
    }
 
    if (pid > 0) /* 父进程 */
    {
        int status;
        pid_t child_pid;
        child_pid = wait(&status);
 
        printf("child process has exited, pid=%d\n", child_pid);
        if (WIFEXITED(status))
        {
            printf("child exited with code %d\n", WEXITSTATUS(status));
        }
        else
        {
            printf("child exited abnormally\n");
        }
    }
    else /* 子进程 */
    {
        while (i-- > 0)
        {
            puts(msg);
            sleep(1);
        }
    }
}
