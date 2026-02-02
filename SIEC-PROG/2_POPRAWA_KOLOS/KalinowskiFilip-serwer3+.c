#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<netinet/in.h>
#include<string.h>
#include<signal.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MESSAGE_SIZE 256
#define PORT 8888
#define NI_MAXHOST 1025

struct sockaddr_storage peer;
socklen_t peer_len = sizeof(peer);
int sockfd;

void signalHandler(int signal){
    if (signal == SIGINT){
        printf("Konczymy...\n");
        close(sockfd);
        exit(-1);
    }
}

void receiveMessage(int sockfd){
    char message[MESSAGE_SIZE];
    char buffer[MESSAGE_SIZE];
    int message_count = 0;
    char host[NI_MAXHOST];
    int port;
    int bits = 0;
    printf("Czekam...\n");
    for(;;){
        bits = recvfrom(sockfd,&message,sizeof(message),0,(struct sockaddr*)&peer,&peer_len);
        if(bits == -1){
            continue;
        }
        message_count++;
        struct sockaddr_in *s = (struct sockaddr_in*)&peer;
        inet_ntop(AF_INET,&s->sin_addr,host,NI_MAXHOST);
        port = ntohs(s->sin_port);
        printf("Wiadomosc nr %d (IP: %s, port: %d): %s",message_count,host,port,message);
        strcpy(buffer,message); //
        int i = 0;
        for(i = 0; i < MESSAGE_SIZE; i++){
            if(buffer[i] == '\n'){
                buffer[i] = '\0';
                break;
            }
        }
        strcat(buffer,message);
        if((sendto(sockfd,buffer,MESSAGE_SIZE,0,(struct sockaddr*)&peer,peer_len)) == -1){
            perror("sendto");
            exit(-1);
        }
        printf("Odsylam: %s\n",buffer);

    }
}

int main(){

    signal(SIGINT,signalHandler);

    struct sockaddr_in server_addr;

    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if((sockfd = socket(AF_INET,SOCK_DGRAM,0)) == -1){
        perror("socket");
        exit(-1);
    }
    if((bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr))) == -1){
        perror("bind");
        exit(-1);
    }
    receiveMessage(sockfd);
    return 0;
}
