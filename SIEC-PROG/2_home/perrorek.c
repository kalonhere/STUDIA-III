#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main() {
    //essa t
    extern int errno;
    char buf[128];
    int ile;
    if((ile = read(77, buf, 128)) == -1)
        perror("testowy blad - funkcja read");

    printf("Numer bledu: %d\n", errno);

    return 0;

}

