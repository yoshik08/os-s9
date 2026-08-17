#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t first_child, second_child;

    first_child = fork();

    if (first_child < 0)
    {
        perror("First fork failed");
        return 1;
    }

    if (first_child == 0)
    {
        printf("First child: PID = %d\n", getpid());
        sleep(2);
        return 0;
    }

    second_child = fork();

    if (second_child < 0)
    {
        perror("Second fork failed");
        return 1;
    }

    if (second_child == 0)
    {
        printf("Second child: PID = %d\n", getpid());
        sleep(1);
        return 0;
    }

    printf("Parent PID: %d\n", getpid());

    pid_t completed = wait(NULL);
    printf("wait() detected child termination: PID = %d\n", completed);

    waitpid(first_child, NULL, 0);
    printf("waitpid() detected termination of child: PID = %d\n",
           first_child);

    printf("All required child processes have completed.\n");

    return 0;
}
