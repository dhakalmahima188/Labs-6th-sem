#include <stdio.h>
#include <unistd.h>
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
        sleep(2);
        printf("Parent process");
    }
}
