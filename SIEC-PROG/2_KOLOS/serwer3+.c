#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<netinet/in.h>
#include<string.h>
#include<signal.h>
#include<netdb.h>
#include<ctype.h>

#define MESSAGE_SIZE 256
#define NI_MAXHOST 1025
#define NI_MAXSERV 32
struct sockaddr_storage peer_addr;
socklen_t peer_addr_len;

void signalHandler(int signal){
    if(signal == SIGINT){
        printf("\nKonczymy\n");
        exit(0);
    }
}

void receiveMessage(int socket_fd){
    for(;;){
        char message[MESSAGE_SIZE];
        char buffer[MESSAGE_SIZE];
        int message_count = 0;
        char host[NI_MAXHOST], service[NI_MAXSERV];
        int bits;
        bits = recvfrom(socket_fd,&message,sizeof(message),0,(struct sockaddr*)&peer_addr,&peer_addr_len);
        message_count++;
        if(bits == -1){
            continue;
        }
        getnameinfo((struct sockaddr*)&peer_addr,peer_addr_len,host,NI_MAXHOST,service,NI_MAXSERV,0);
        printf("Wiadomosc nr %d (IP: %s, port: %s): %s",message_count,host,service,message);
        int i;
        for(i = 0; i < MESSAGE_SIZE; i++){
            buffer[i] = toupper(message[i]);
        }
        if((sendto(socket_fd,buffer,sizeof(message),0,(struct sockaddr*)&peer_addr,peer_addr_len)) == -1){
            perror("sendto");
            exit(-1);
        }else{
            printf("Odsylam: %s",buffer);
        }

    }
}


int main(){
    
    struct sockaddr_in localhost;
    int socket_fd;
    
    signal(SIGINT,signalHandler);
    memset(&localhost,0,sizeof(localhost));
    localhost.sin_family = AF_INET;
    localhost.sin_port = htons(7777);
    localhost.sin_addr.s_addr = INADDR_ANY;
    
    if((socket_fd = socket(AF_INET,SOCK_STREAM,0)) == -1){
        perror("socket");
        exit(-1);
    }  
    if((bind(socket_fd,(struct sockaddr*)&localhost,sizeof(localhost))) == -1){
        perror("bind");
        exit(-1);
    }  
    
    printf("Czekam...\n");

    receiveMessage(socket_fd);


    return 0;
}
