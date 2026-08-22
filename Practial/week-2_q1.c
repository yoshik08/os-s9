#include <fcntl.h>
#include <unistd.h>

int main() {
    int in = open("source.txt", O_RDONLY);
    int out = open("dest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buf[1024];
    int n;

    while ((n = read(in, buf, sizeof(buf))) > 0)
        write(out, buf, n);

    close(in);
    close(out);
    return 0;
}
