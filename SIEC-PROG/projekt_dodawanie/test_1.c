#include <netinet/in.h>
#include<stdio.h>
#include <stdlib.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>


void exitError(char * text){
  printf("\e[1;31m===ERROR===\e[m\n");
  perror(text);
  exit(EXIT_FAILURE);
}
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in socket_address;
    memset(&socket_address, 0, sizeof(socket_address));

    char *end;
    long port = strtol(argv[2], &end, 10);
    if (*end || port <= 0 || port > 65535)
        exitError("invalid port");

    socket_address.sin_family = AF_INET;
    socket_address.sin_addr.s_addr = INADDR_ANY;
    socket_address.sin_port = htons((uint16_t)port);

    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd == -1)
        exitError("socket");

    if (bind(sock_fd, (struct sockaddr*)&socket_address, sizeof(socket_address)) == -1)
        exitError("bind");

    struct sockaddr_in check;
	socklen_t len = sizeof(check);
	getsockname(sock_fd, (struct sockaddr*)&check, &len);
	printf("Bound to %s:%d\n",
       inet_ntoa(check.sin_addr),
       ntohs(check.sin_port));


    char message[255];
    printf("recvfrom starting\n");
    ssize_t n = recvfrom(sock_fd, message, sizeof(message) - 1, 0, NULL, NULL);
    if (n == -1)
        exitError("recvfrom");

    message[n] = '\0';
    printf("received: %s\n", message);

    close(sock_fd);
}
