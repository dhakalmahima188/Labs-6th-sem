// wait command
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int pid = fork();
    if (pid < 0)
    {
        printf("No  process created");
    }
    else if (pid == 0)
    {
        printf("Child process\n");
    }
    else
    {
        wait(NULL);
        printf("Parent process");
    }
}
