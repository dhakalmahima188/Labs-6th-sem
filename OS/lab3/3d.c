// SLEEP COMMAND USING GETPID
#include <stdio.h>
#include <unistd.h>
int main()
{
    int ppid, pid = fork();

    if (pid == 0)
    {
        pid = getpid();
        printf("Child process: %d\n", pid);
    }
    else if (pid < 0)
    {
        printf("No process created");
    }
    else
    {
        sleep(1);
        ppid = getppid();
        printf("Parent process: %d\n", ppid);
    }
}