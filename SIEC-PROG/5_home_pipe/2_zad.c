#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
typedef enum {
  READ = 0,
  WRITE = 1
} fork_flag;

int main(){

    int number;
    printf("Podaj liczbe calkowita: ");    
    scanf("%d",&number);


  int pipe_send_to_child[2];
  int pipe_read_from_child[2];
  pid_t pid;
  if(pipe(pipe_send_to_child) < 0){perror("pajp error"); exit(EXIT_FAILURE);}
  if(pipe(pipe_read_from_child) < 0){perror("pajp error"); exit(EXIT_FAILURE);}

  if((pid = fork()) == -1) {perror("fork error"); exit(EXIT_FAILURE);}

  if(pid == 0){
    close(pipe_send_to_child[WRITE]);
    read(pipe_send_to_child[READ],&number,sizeof(int));
    close(pipe_send_to_child[READ]);
    number = number * 2;

    close(pipe_read_from_child[READ]);
    write(pipe_read_from_child[WRITE],&number,sizeof(int));
    close(pipe_read_from_child[WRITE]);
    exit(EXIT_SUCCESS);
    

  }//child
  else if (pid != 0){
    close(pipe_send_to_child[READ]);
    write(pipe_send_to_child[WRITE],&number,sizeof(int));
    close(pipe_send_to_child[WRITE]);

    wait(NULL);

    close(pipe_read_from_child[WRITE]);
    read(pipe_read_from_child[READ],&number,sizeof(int));
    close(pipe_read_from_child[READ]);
    

    printf("\nWynik to: %d",number);
    exit(EXIT_SUCCESS);
  }//parent


  return 0;
}
