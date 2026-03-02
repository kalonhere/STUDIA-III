#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<netinet/in.h>
#include<string.h>
#include<signal.h>
#include<netdb.h>
#include<ctype.h>
#include<arpa/inet.h>

#define MESSAGE_SIZE 256
#define PORT 7777
#define NI_MAXHOST 1025
#define NI_MAXSERV 32
struct sockaddr_storage peer_addr;
socklen_t peer_addr_len = sizeof(peer_addr);

void receiveMessage(int socketfd){
    int message_count = 0;
    char message[MESSAGE_SIZE];
    char buffer[MESSAGE_SIZE];
    char host[NI_MAXHOST];
    int port;
    int bits = 0;
    for(;;){
        bits = recvfrom(socketfd,&message,sizeof(message),0,(struct sockaddr *)&peer_addr, &peer_addr_len);
        if(bits == -1){
            continue;
        }
        message_count++;
        struct sockaddr_in *s = (struct sockaddr_in* )&peer_addr;
        inet_ntop(AF_INET,&s->sin_addr,host,NI_MAXHOST);
        port = ntohs(s->sin_port);
        printf("Wiadomosc nr %d (IP: %s, port: %d): %s",message_count,host,port,message);
        for(int i = 0;i < MESSAGE_SIZE; i++){
            buffer[i] = toupper(message[i]);
        }
        if((sendto(socketfd,buffer,sizeof(buffer),0,(struct sockaddr*)&peer_addr,peer_addr_len)) == -1){
            perror("sendto");
            exit(-1);
        }else{
            printf("Odsylam: %s",buffer);
        }

        

    }
}


void signalHandler(int signal){
    if(signal == SIGINT){
        printf("Koncze...\n");
        exit(1);
    }
}


int main(){

    int sockfd;
    struct sockaddr_in server_addr;

    //signal handler
    signal(SIGINT,signalHandler);
    
    //socket stuff
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
    printf("Czekam...\n");
    
    receiveMessage(sockfd);


    


    return 0;
}
