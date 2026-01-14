#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<arpa/inet.h>

struct addrinfo *address_information;
struct sockaddr_in *socket_address;
struct sockaddr_in local_address;




void errorExit(char * text){
  printf("\e[1;31m=====ERROR=====\e[m\n");
  perror(text);
  exit(EXIT_FAILURE);
}


void extractAdressInfo(char *address, char* port){
  if((getaddrinfo(address,port,NULL,&address_information)) != 0){
    errorExit("getaddrinfo");
  }
  socket_address = (struct sockaddr_in*)address_information->ai_addr;
  char presentation_address[address_information->ai_addrlen];

  inet_ntop(address_information->ai_family,&socket_address->sin_addr,presentation_address,sizeof(presentation_address));
  printf("Presentation address: %s\n",presentation_address);
  printf("Port: %d\n",ntohs(socket_address->sin_port));
}

void bindLocalAddress(int socket_fd){
  memset(&local_address,0,sizeof(struct sockaddr_in));
  local_address.sin_family = socket_address->sin_family;
  local_address.sin_port = socket_address->sin_port;
  local_address.sin_addr.s_addr = INADDR_ANY;

  if((bind(socket_fd,(struct sockaddr*)&local_address,sizeof(local_address))) == -1){
    errorExit("bind");
  }
}

struct my_message {
  char nickname[64];
  int number;
};


//void sendMessage(int socket_fd){
//  struct my_message message;
//  strcat(message.nickname,nick);
//  message.number = 1;
//
//  int bytes;
//  if((bytes = sendto(socket_fd,&message,sizeof(struct my_message),0,(struct sockaddr*)socket_address,sizeof(*socket_address))) == -1){
//    errorExit("sendto");
//  }
//}

int main(int argc, char *argv[]){
  //check argument count
  if((argc < 3) || (argc > 4)){
    printf("\e[1;31mWrong argument count \e[m\n");
    return 0;
  }
  //assign nickname
  //create variables 
  
  //extract address information
  extractAdressInfo(argv[1],argv[2]);
  //create socket
  printf("test");
  int socket_fd;
  if((socket_fd = socket(socket_address->sin_family,SOCK_DGRAM,0)) == -1){
    errorExit("socket");
  } 
  bindLocalAddress(socket_fd);
  //sendMessage(socket_fd);

  //send connection message
  struct my_message message_out;
  if(argc == 4){
    strcat(message_out.nickname,argv[3]);
  }
  message_out.number = 1;
  int bytes = 0;
  if((bytes = sendto(socket_fd,&message_out,sizeof(struct my_message),0,(struct sockaddr*)socket_address,sizeof(*socket_address))) == -1){
    errorExit("initializing sendto");
  }


  struct my_message message_in = {0};
  while(1){
    recvfrom(socket_fd,&message_in,sizeof(struct my_message),0,NULL,NULL);
  }

  

  return 0;
}
