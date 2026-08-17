#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("Process ID: %d\n", getpid());

    printf("Process State: Waiting\n");
    printf("Process will remain in this state for 30 seconds...\n");

    sleep(30);

    printf("Process State: Running\n");
    printf("Process is now terminating.\n");

    return 0;
}
