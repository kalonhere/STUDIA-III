#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

int main(){
  pid_t process_id, child_process_returned;
  int wait_status;
  if((process_id = fork()) == -1){
    perror("Couldn't fork");
    exit(EXIT_FAILURE);
  }
  if(process_id != 0){//parent
    if((child_process_returned = wait(&wait_status)) == -1){
      perror("couldn't execute wait function");
      exit(EXIT_FAILURE);
    }//perror
    
    if(WIFEXITED(wait_status)){
      pid_t parent_id = getpid();
      //printf("test: process_id = %u, parent_id = %u",process_id,parent_id);
      printf("(Parent PID: %u): Child (PID: %u) sent message: %d\n",parent_id,child_process_returned,WEXITSTATUS(wait_status));
      exit(EXIT_SUCCESS);
    }else{
      perror("Error when child exiting");
      exit(EXIT_FAILURE);
    }

  }//parent
  if(process_id == 0){
    pid_t current_id = getpid();
    int number;
    printf("(Child PID: %u): Input number: ",current_id);
    scanf("%d",&number);
    exit(number);
  }
  



  return 0;
}
