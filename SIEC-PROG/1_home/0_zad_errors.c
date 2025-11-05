#include <errno.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>

void mysyserr(char *my_message){
  fprintf(stderr,"ERROR: %s (errno: %d, %s) \n",my_message,errno,strerror(errno));
  exit(EXIT_FAILURE);
}

int main(){
  char buffer[1024];
  int byte_count;
  if((byte_count = read(77,buffer,1024)) == -1){
    mysyserr("Blad funkcji read");
  }


  return 0;
}
