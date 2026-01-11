#include<stdio.h>
#include <stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


int main(int argc, char*argv[]){

  if(argc != 2){
    printf("wrong argument count\n");
    exit(EXIT_FAILURE);
  }
  struct in_addr network_address;

  inet_pton(AF_INET,argv[1],&network_address);

  printf("source: %s\n",argv[1]);
  printf("sizeof: %lu || output: %d\n",sizeof(network_address.s_addr),network_address.s_addr);

  printf("network->host long: %u\n",ntohl(network_address.s_addr));
  printf("network->host short: %d\n",ntohs(network_address.s_addr));

  return 0;
}
