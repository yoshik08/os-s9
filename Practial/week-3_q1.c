#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child_pid = fork();

    if (child_pid < 0)
    {
        perror("Unable to create process");
        return 1;
    }

    if (child_pid == 0)
    {
        printf("\n--- Child Process ---\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
        printf("State      : Running\n");

        sleep(5);

        printf("State      : Terminated\n");
        exit(0);
    }

    printf("\n--- Parent Process ---\n");
    printf("Parent PID : %d\n", getpid());
    printf("Child PID  : %d\n", child_pid);
    printf("State      : Waiting\n");

    wait(NULL);

    printf("State      : Running\n");
    printf("Child process has terminated.\n");

    return 0;
}
