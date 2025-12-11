#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<signal.h>
#include<unistd.h>

key_t msq_key;
int msq_id;
#define MESSAGE_SIZE 128

struct my_msg{
  int type;
  char text[MESSAGE_SIZE];
};



void debugMessage(const char *text){
  printf("\e[1;33m ***** %s ***** \e[m \n",text);
}
void signalHandler(int signal){
  if(msgctl(msq_id,IPC_RMID,0) == -1){perror("queue deletion");exit(1);};
  debugMessage("");
}





int main(int argc, char *argv[]){
  debugMessage("test message");

  signal(SIGINT,signalHandler);
  
  return 0;
}
