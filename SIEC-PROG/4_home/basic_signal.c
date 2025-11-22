#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void signalHandler(int signal_number){
  printf("Received signal number: %d",signal_number);
}//signalHandler

int main(){
  signal(SIGINT,signalHandler);
  signal(SIGQUIT,signalHandler);
  signal(SIGTSTP,signalHandler);
  signal(SIGKILL,signalHandler);
  signal(SIGUSR1,signalHandler);
  
  for(int i = 1;i>0;i++){
    printf("Im working for %d seconds. \n",i);
    sleep(1);
  }


  return 0;
}
