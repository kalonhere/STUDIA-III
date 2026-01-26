#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<netinet/in.h>
#include<string.h>
#include<signal.h>
#include<netdb.h>
#include<ctype.h>
#include<sys/types.h>

#define MESSAGE_SIZE 256


int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Zla liczba argumentow\n");
        exit(0);
    }
    struct sockaddr_in localhost;
    
    memset(&localhost,0,sizeof(localhost));
    localhost.sin_family = AF_INET;
    localhost.sin_port = htons(7777);
    localhost.sin_addr.s_addr = INADDR_ANY;
        

    struct sockaddr_in *socket_address;
    struct addrinfo *address_information;
    int socket_fd;
    if((getaddrinfo(argv[1],"7777",NULL,&address_information)) != 0){
        perror("getaddrinfo");
        exit(-1);
    }
    socket_address = (struct sockaddr_in*)address_information->ai_addr;
    
    //printf("port: %d",ntohs(socket_address->sin_port));
    if((socket_fd = socket(AF_INET,SOCK_STREAM,0)) == -1){
        perror("socket");
        exit(-1);
    }

    char message[MESSAGE_SIZE];
    printf("Podaj wiadomosc do serwera: \n>");
    fgets(message,MESSAGE_SIZE,stdin);
    printf("beka");
    fflush(stdout);

    if((sendto(socket_fd,&message,sizeof(message),0,(struct sockaddr*)&socket_address,sizeof(*socket_address))) == -1){
        perror("sendto");
        exit(-1);
    }else{
        printf("wyslano");
    }


    for(;;){
        if((recvfrom(socket_fd,&message,sizeof(message),0,NULL,NULL)) == -1){
            printf("pomijam");
            continue;
        }else{
            printf("Odpowiedz serwera: %s",message);
            freeaddrinfo(address_information);
            exit(0);
        }
    }
    
    freeaddrinfo(address_information);

    



    return 0;
}
