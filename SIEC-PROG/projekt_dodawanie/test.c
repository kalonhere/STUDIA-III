#include <netinet/in.h>
#include<stdio.h>
#include <stdlib.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<arpa/inet.h>



void exitError(char * text){
  printf("\e[1;31m===ERROR===\e[m\n");
  perror(text);
  exit(EXIT_FAILURE);
};

int main(int argc, char *argv[]){
  struct sockaddr_in socket_address;
  memset(&socket_address,0,sizeof(socket_address));
  const char *ip = "127.0.0.1";
  struct in_addr netip = {0};
  inet_pton(AF_INET,ip,&netip);
  
  socket_address.sin_addr = netip;
  socket_address.sin_port = htons((uint16_t)atoi(argv[2]));
  socket_address.sin_family = AF_INET;
  
  int sock_fd = socket(AF_INET,SOCK_DGRAM,0);
  if((bind(sock_fd,(struct sockaddr*)&socket_address,sizeof(socket_address))) == -1){
    perror("bind");
    exit(EXIT_FAILURE);
  };
  
  char message[255] = {0};
  recvfrom(sock_fd,message,255,0,NULL,NULL);
  printf("received %s",message);
  

  return 0;
}

