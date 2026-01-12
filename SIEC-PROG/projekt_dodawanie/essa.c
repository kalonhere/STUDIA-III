#include <netinet/in.h>
#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<arpa/inet.h>
struct addrinfo *address_information;

//perror exit
void exitError(char * text){
  printf("\e[1;31m===ERROR===\e[m\n");
  perror(text);
  exit(EXIT_FAILURE);
}

void extractAddressInfo(char *address){
  if((getaddrinfo(address,NULL,NULL,&address_information)) != 0){
    exitError("extractAddressInfo");
  }
}

int main(int argc, char *argv[]){
  if((argc < 3)||(argc>4)){
    exitError("wrong argument count");
  }
  char nickname[64] = {0};
  if(argc == 4){
    strcat(nickname,argv[3]);  
  }
  u_short port = atoi(argv[2]);

  //printf("nickname: %s",nickname);


    
  extractAddressInfo(argv[1]);
  //get presentation address
  char presentation_address[address_information->ai_addrlen];
  struct sockaddr_in *socket_address = (struct sockaddr_in*)address_information->ai_addr;
  inet_ntop(address_information->ai_family,&socket_address->sin_addr,presentation_address,sizeof(presentation_address));
  printf("Presentation address: %s\n",presentation_address);
  //set port
  socket_address->sin_port = htons(port);
  printf("port: %u\n",socket_address->sin_port);
  
  //create socket
  int socket_fd;
  socket_fd = socket(socket_address->sin_family,SOCK_DGRAM,0);

  //create listening bind
  struct sockaddr_in local_host;
  bzero(&local_host,sizeof(local_host));
  local_host.sin_family = socket_address->sin_family;
  local_host.sin_port = htons(port);
  local_host.sin_addr.s_addr = INADDR_ANY;

  if((bind(socket_fd,(struct sockaddr *)&local_host,sizeof(local_host))) == -1){
    exitError("BIND | CREATING LISTENING SOCKET");
  }





  




  return 0;
}
