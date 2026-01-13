#include <netinet/in.h>
#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<arpa/inet.h>
struct addrinfo address_information;
struct addrinfo *address_information_ptr = &address_information;
void printSockaddrinData(struct sockaddr_in *socket){
  struct in_addr address = (struct in_addr)socket->sin_addr;
  
  char presentation_address[sizeof(*socket)];
  inet_ntop(AF_INET,&socket->sin_addr,presentation_address,sizeof(presentation_address));
  printf("Presentation address: %s\n",presentation_address);
  
  printf("port: %d",socket->sin_port);
  //printf("address: ",socket->sin_addr);
  //printf("",socket->sin_zero);
  printf("sin_family: %d",socket->sin_family);
}



typedef struct custom_message{
  char nickname[64];
  int number;
} message;


//perror exit
void exitError(char * text){
  printf("\e[1;31m===ERROR===\e[m\n");
  perror(text);
  exit(EXIT_FAILURE);
}

void extractAddressInfo(char *address, char *port){
  if((getaddrinfo(address,port,NULL,&address_information_ptr)) != 0){
    exitError("extractAddressInfo");
  }
}

int main(int argc, char *argv[]){
  if((argc < 3)||(argc>4)){
    printf("\e[1;31m Wrong argument count \e[m\n");
    return 0;
  }
  char nickname[64] = {0};
  if(argc == 4){
    strcat(nickname,argv[3]);  
  }
  u_short port = atoi(argv[2]);
  memset(&address_information,0,sizeof(address_information));
  extractAddressInfo(argv[1],argv[2]);
  //get presentation address
  char presentation_address[address_information.ai_addrlen];
  struct sockaddr_in *socket_address;
  //memset(socket_address,0,sizeof(*socket_address));
  socket_address = (struct sockaddr_in*)&address_information.ai_addr;
  inet_ntop(address_information.ai_family,&socket_address->sin_addr,presentation_address,sizeof(presentation_address));
  printf("Presentation address: %s\n",presentation_address);
  //show port
  printf("port: %u\n",socket_address->sin_port);
  
  //create socket
  int socket_fd;
  socket_fd = socket(socket_address->sin_family,SOCK_DGRAM,0);
  printf("RECEIVER ADDRES DATA: ");
  printSockaddrinData(socket_address);
  printf("\n\n\n");
  //create listening bind
  struct sockaddr_in local_host;
  //memset(&local_host,0,sizeof(local_host));
  local_host.sin_family = socket_address->sin_family;
  local_host.sin_port = socket_address->sin_port;
  local_host.sin_addr.s_addr = INADDR_ANY;
  
  if((bind(socket_fd,(struct sockaddr *)&local_host,sizeof(local_host))) == -1){
    exitError("BIND | CREATING LISTENING SOCKET");
  }
  struct sockaddr_in* local_host_ptr = &local_host;
  struct custom_message message_out;
  if(argc == 4){
    strcat(message_out.nickname,argv[3]);  
  }
  int bytes;
  printf("SENDER ADDRES DATA: ");
  printSockaddrinData(local_host_ptr);
  printf("\n\n\n");
  
  if((bytes = sendto(socket_fd,&message_out,sizeof(message_out),0,(struct sockaddr*)socket_address,sizeof(*socket_address))) == -1){
    exitError("sendto first attempt");
  }

  struct sockaddr_in *sender_host;
  //memset(sender_host,0,sizeof(*sender_host));
  socklen_t sender_address_length = sizeof(&sender_host);
  struct custom_message message_in;
  while(1){
    recvfrom(socket_fd,&message_in,sizeof(message_in),0,(struct sockaddr*)sender_host,&sender_address_length);

    printf("Message received: Nickname = %s , number = %d",message_in.nickname,message_in.number);

    
  }




  freeaddrinfo(&address_information);

  return 0;
}
