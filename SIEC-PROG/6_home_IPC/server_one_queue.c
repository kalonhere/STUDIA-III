#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<signal.h>
#include<unistd.h>

key_t msq_key_server;
int msq_id_server;
key_t msq_key_client;
int msq_id_client;
#define MESSAGE_SIZE 128

struct my_msg{
  long type;
  char text[MESSAGE_SIZE];
};

typedef enum{
  SERVER = 1,
  CLIENT = 2
} MESSAGE_PROJECT;


void debugMessage(const char *text){
  printf("\e[1;33m ***** %s ***** \e[m \n",text);
}
void infoMessage(const char *text){
  printf("\e[1;32m ***** %s ***** \e[m \n",text);
}
void signalHandler(int signal){
  if(msgctl(msq_id_server,IPC_RMID,0) == -1){perror("server queue deletion");exit(EXIT_FAILURE);};
  debugMessage("Message queue destroyed :3");
  exit(EXIT_SUCCESS);
}


int main(int argc, char *argv[]){
  system("clear");
  struct my_msg server_message;
  signal(SIGINT,signalHandler);  
  if(argc != 2){
    debugMessage("Wrong arguments count ($key_generation_file)");
    exit(EXIT_FAILURE);
  }
  msq_key_server = ftok(argv[1],SERVER);
  if((msq_key_server) >= 0) {debugMessage("Keys created");}else{
    perror("message key creation");
    exit(EXIT_FAILURE);
  }
  
  if((msq_id_server = msgget(msq_key_server,0777 | IPC_CREAT)) == -1){perror("server creation");exit(EXIT_FAILURE);}
  
  infoMessage("Message queues created. Awaiting message...");
  while(1){
    int message_size;
    message_size = msgrcv(msq_id_server,&server_message,MESSAGE_SIZE,0,0);
    printf("Received message. Type = %ld, Size = %d \n",server_message.type,message_size);
    printf("%s",server_message.text);
    //sending confirmation
    strcpy(server_message.text,"Confirmation");
    if((message_size = msgsnd(msq_id_server,&server_message,MESSAGE_SIZE,0)) == -1){perror("msgsnd");exit(EXIT_FAILURE);}
    infoMessage("Confirmation sent");
  }

  return 0;
}
