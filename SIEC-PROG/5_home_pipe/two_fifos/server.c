#include <asm-generic/errno-base.h>
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
  int size;

  if (mkfifo("server_fifo", 0777) < 0 && (errno != EEXIST)){perror("mkfifo server"); exit(EXIT_FAILURE);}
  if((server_fd = open("server_fifo", O_RDONLY | O_NONBLOCK)) == -1){perror("server_fifo");exit(EXIT_FAILURE);};
  debugMessage("server created and opened");

  if (mkfifo("client_fifo", 0777) < 0 && (errno != EEXIST)){perror("mkfifo server"); exit(EXIT_FAILURE);}
  debugMessage("client created");

  while((client_fd = open("client_fifo", O_WRONLY | O_NONBLOCK)) == -1){};
  debugMessage("client connected");


  int number;
  while(1){
    if((size = read(server_fd,&number,sizeof(number))) > 0){
      number = number *2;
      write(client_fd,&number,sizeof(number));
    }
  }


  close(server_fd);
  close(client_fd);

    


  return 0;
}


