#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFS 1024

int main(int argc, char *argv[]) {
    int fd, n;
    char buf[BUFS];

    for (int i = 1; i < argc; ++i) {
        if ((fd = open(argv[i], O_RDONLY)) == -1)
            perror("Blad");

        while ((n = read(fd, buf, BUFS)) > 0) {
            write(fileno(stdout), buf, n);
            /* write(1, buf, n); */
        }
        close(fd);
    }

    return 0;
}
