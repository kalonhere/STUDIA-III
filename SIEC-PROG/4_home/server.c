#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void signalHandler(int signal_number){
  if(signal_number == SIGUSR1){
    printf("SERVER: Received message number 1 from client.\n");
  }
  if(signal_number == SIGUSR2){
    printf("SERVER: Received message number 2 from client.\n");
  }
}

int main(){
  printf("Server PID: %u\n",getpid());
  printf("Signal handler initialized.\n");
  while(1){
    signal(SIGUSR1,signalHandler);
    signal(SIGUSR2,signalHandler);
  }
  return 0;
}
