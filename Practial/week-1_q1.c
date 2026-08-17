#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    char command[100];

    printf("Enter a Linux command: ");
    scanf("%99s", command);

    char *arguments[] = {command, NULL};

    pid_t child_pid = fork();

    if (child_pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (child_pid == 0)
    {
        printf("\nChild Process\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());

        execvp(command, arguments);

        perror("execvp failed");
        return 1;
    }

    printf("\nParent Process\n");
    printf("Parent PID : %d\n", getpid());
    printf("Child PID  : %d\n", child_pid);

    wait(NULL);

    printf("Child process completed successfully.\n");

    return 0;
}
