#include<stdio.h>
#include<stdlib.h>
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


int main(int argc, char *argv[]){
  system("clear");
  struct my_msg server_message;
  struct my_msg client_message;

  if(argc != 2){
    debugMessage("Wrong arguments count ($key_generation_file)");
    exit(EXIT_FAILURE);
  }
  msq_key_server = ftok(argv[1],SERVER);
  msq_key_client = ftok(argv[1],CLIENT);
  if((msq_key_server * msq_key_client) >= 0) {debugMessage("Keys created");}else{
    perror("message key creation");
    exit(EXIT_FAILURE);
  }
  
  if((msq_id_server = msgget(msq_key_server,0)) == -1){perror("server connection");exit(EXIT_FAILURE);}
  if((msq_id_client = msgget(msq_key_client,0)) == -1){perror("client connection");exit(EXIT_FAILURE);}
  infoMessage("Message queues connected.");

  char message_buffer[MESSAGE_SIZE];
  long type_buffer = 0;
  printf("Message:");
  fgets(server_message.text,MESSAGE_SIZE,stdin);
  printf("Type of message ( >0 ): ");
  while(1){
    scanf("%ld",&type_buffer);
    if(type_buffer > 0){
      server_message.type = type_buffer;
      break;
    }else{
      printf("Wrong message type. Try again.\n");
      continue;
    }
  }
  int message_size;
  if((message_size = msgsnd(msq_id_server,&server_message,MESSAGE_SIZE,0)) == -1){perror("msgsnd");exit(EXIT_FAILURE);}
  infoMessage("Message sent.");

  message_size = msgrcv(msq_id_client,&client_message,MESSAGE_SIZE,0,0);
  printf("Received message. Type = %ld, Size = %d \n",client_message.type,message_size);
  printf("%s\n",client_message.text);


  return 0;
}
