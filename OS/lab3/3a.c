#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid, mypid, myppid;
    pid = getpid();

    printf("Before fork:  %d\n", pid);
    // fork a child process
    pid = fork();
    printf("After fork:   %d\n", pid);

    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child Process\n");
        mypid = getpid();
        myppid = getppid();
        printf("PID : %d and PPID : %d\n", mypid, myppid);
    }
    else
    {
        sleep(2);
        printf("Parent Process\n");
        mypid = getpid();

        printf("PID :  %d  \n", mypid);
    }
    return 0;
}