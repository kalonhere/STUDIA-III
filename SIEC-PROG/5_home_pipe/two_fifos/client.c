#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

void debugMessage(char * text){
  printf("\e[1;33m ***** %s ***** \e[0m \n",text);
}
#define BUFF_LEN 1024

int main(){
  int server_fd, client_fd;
  char buffer[BUFF_LEN];
  pid_t pid;

  if((server_fd = open("server_fifo", O_WRONLY)) == -1){perror("server_fifo");exit(EXIT_FAILURE);};
  debugMessage("server opened");
  if((client_fd = open("client_fifo", O_RDONLY | O_NONBLOCK)) == -1){perror("client_fifo");exit(EXIT_FAILURE);};
  debugMessage("client opened");
  
  int number;
  printf("Podaj liczbe do przeslania: ");
  scanf("%d",&number);
  write(server_fd,&number,sizeof(number));
  
  int size;
  if((size = read(client_fd,&number,sizeof(number))) < 0){
    perror("read");
    exit(EXIT_FAILURE);
  }else{
    printf("Wartosc przekazana od serwera: %d\n",number);
  }

  close(server_fd);
  close(client_fd);

  



  return 0;
}
