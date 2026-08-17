#include <stdio.h>
#include <unistd.h>

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
    printf("Parent is sleeping. The child becomes a zombie.\n");

    sleep(20);

    printf("Parent process is terminating.\n");

    return 0;
}
