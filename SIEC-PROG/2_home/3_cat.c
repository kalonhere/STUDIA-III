#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define FLAG 0
#define BUFS 1024
void debug(char *text){
  if(FLAG == 1){
  printf("****%s****\n",text);
  }
}

int main(int argc, char* argv[]){

  if(argc < 2){
    fprintf(stderr,"Error: Wrong number of arguments\n");
    exit(EXIT_FAILURE);
  }
  int file_descriptor;
  char buffer[BUFS];
  int data_number;

  for(int i = 1; i < argc; i++){
    if(i != 1){write(1,"\n=====Next file===== \n",23);}
    if((file_descriptor = open(argv[i], O_RDONLY)) == -1){
      perror("Couldn't open file");
      exit(EXIT_FAILURE);
    }
    debug("file opened");


    while((data_number = read(file_descriptor,buffer,BUFS)) !=0){
      if(data_number == -1){
        perror("couldn't read file");
        exit(EXIT_FAILURE);
      }
      write(1,buffer,data_number);
    }//whil
    close(file_descriptor);
  }//for

  return 0;
}
