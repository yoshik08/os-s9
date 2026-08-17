#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child_pid = fork();

    if (child_pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (child_pid == 0)
    {
        printf("Child process is terminating.\n");
        return 0;
    }

    printf("Parent PID : %d\n", getpid());
    printf("Child PID  : %d\n", child_pid);

    waitpid(child_pid, NULL, 0);

    printf("Child process has been reaped.\n");
    printf("Zombie process eliminated.\n");

    return 0;
}
