#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define BUFFER_SIZE 1024


int main(){
  int size;
  char buffer[BUFFER_SIZE];
  while((size = read(0,buffer,BUFFER_SIZE)) > 0){
    write(1,buffer,size);
  }


  return 0;
}
