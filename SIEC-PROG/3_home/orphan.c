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
    exit(EXIT_SUCCESS);
  }//parent
  if(process_id == 0){
    int second = 60;
    while(second>0){
      printf("essa\n");
      sleep(1);
      second--;
    }
    
    exit(EXIT_SUCCESS);
  }
  return 0;
}
