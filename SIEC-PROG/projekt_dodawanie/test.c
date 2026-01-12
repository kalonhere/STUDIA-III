#include<stdio.h>
#include <stdlib.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>



void exitError(char * text){
  printf("\e[1;31m===ERROR===\e[m\n");
  perror(text);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
  if(argc != 2){
    exitError("wrong argument count");
  }
  
  //checkAddressType(argv[1]);
  
  printf("string length: %lu",strlen(argv[1]));




  return 0;
}

