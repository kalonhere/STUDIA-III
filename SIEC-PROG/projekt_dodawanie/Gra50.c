#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<arpa/inet.h>
#include<time.h>

struct addrinfo *address_information;
struct sockaddr_in *socket_address;
struct sockaddr_in local_address;

#define CHATSIZE 100


void errorExit(char * text){
  printf("\e[1;31m=====ERROR=====\e[m\n");
  perror(text);
  exit(EXIT_FAILURE);
}


void extractAdressInfo(char *address, char* port){
  if((getaddrinfo(address,port,NULL,&address_information)) != 0){
    errorExit("getaddrinfo");
  }
  socket_address = (struct sockaddr_in*)address_information->ai_addr;
  char presentation_address[address_information->ai_addrlen];

  inet_ntop(address_information->ai_family,&socket_address->sin_addr,presentation_address,sizeof(presentation_address));
}

void bindLocalAddress(int socket_fd){
  memset(&local_address,0,sizeof(struct sockaddr_in));
  local_address.sin_family = socket_address->sin_family;
  local_address.sin_port = socket_address->sin_port;
  local_address.sin_addr.s_addr = INADDR_ANY;

  if((bind(socket_fd,(struct sockaddr*)&local_address,sizeof(local_address))) == -1){
    errorExit("bind");
  }
}

struct my_message {
  char nickname[64];
  int number;
  char chat[CHATSIZE];
};

void sendMessage(int socket_fd,struct my_message message_out, int *start ){
  int flag = 0;
  char buffer[CHATSIZE] = "";
  while(1){
    fgets(buffer,CHATSIZE,stdin);
    for(int i = 0; i < strlen(buffer)-1; i++){
      if(buffer[i] < 48 || buffer[i] > 57){
        if(strcmp(buffer,"koniec\n") == 0){
            message_out.number = -2;
            strcpy(message_out.chat,"");
          if((sendto(socket_fd,&message_out,sizeof(struct my_message), 0, (struct sockaddr*)socket_address,sizeof(*socket_address))) == -1){
            errorExit("sendto(sendMessage) | end of game");
          }
          freeaddrinfo(address_information);
          exit(EXIT_SUCCESS);

        }
        strcpy(message_out.chat,buffer);
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      int new_number = atoi(buffer);
      if(new_number <= *start){
        printf("Nie podano poprawnej wartosci liczby, musi byc wieksza od obecnej\n");
        continue;
      }else{
        strcpy(message_out.chat,"");
        message_out.number = new_number;
      }
    }
    if(flag == 1){
    	flag = 0;
	    if((sendto(socket_fd,&message_out,sizeof(struct my_message), 0, (struct sockaddr*)socket_address,sizeof(*socket_address))) == -1){
        continue;
      }
    }
    
    flag = 0;
    if((sendto(socket_fd,&message_out,sizeof(struct my_message), 0, (struct sockaddr*)socket_address,sizeof(*socket_address))) == -1){
      errorExit("sendto(sendMessage) | chat");
    }
    break;
  }
}


void receiveMessage(int socket_fd, struct my_message message_in,int *start){
  while(1){
    recvfrom(socket_fd,&message_in,sizeof(struct my_message),0,NULL,NULL);
    if(message_in.number == -1){//first in
      printf("%s dolaczyl sie do gry.\n",message_in.nickname);
      *start = rand() % 10 + 1;
      printf("Losowa wartosc poczatkowa: %d, podaj kolejna wartosc.\n",*start);
      message_in.number = 0;
      break;
    }else if (strlen(message_in.chat) != 0){
      printf("%s przesyla wiadomosc: %s",message_in.nickname,message_in.chat);
    }else if(message_in.number == -2){
      printf("%s zakonczyl gre.\n",message_in.nickname);
      freeaddrinfo(address_information);
      exit(EXIT_SUCCESS);
    }else if(message_in.number == 50){
      printf("%s podal wartosc 50!\nPrzegrana!",message_in.nickname);
      freeaddrinfo(address_information);
      exit(EXIT_SUCCESS);
    }else{
      printf("%s podal liczbe: %d, podaj kolejna wartosc",message_in.nickname,message_in.number);
      *start = message_in.number;
      break;
    }//chat
  }

  
}



int main(int argc, char *argv[]){
  //witamy
  printf("Witamy w grze '50' wersja B\n");


  srand(time(NULL));
  //check argument count
  if((argc < 3) || (argc > 4)){
    printf("\e[1;31mWrong argument count \e[m\n");
    return 0;
  }
  //assign nickname
  //create variables 
  
  //extract address information
  extractAdressInfo(argv[1],argv[2]);
  //create socket
  int socket_fd;
  if((socket_fd = socket(socket_address->sin_family,SOCK_DGRAM,0)) == -1){
    errorExit("socket");
  } 
  bindLocalAddress(socket_fd);
  //sendMessage(socket_fd);

  //send connection message
  struct my_message message_out = {0};
  if(argc == 4){
    strcat(message_out.nickname,argv[3]);
  }
  message_out.number = -1;
  int bytes = 0;
  if((bytes = sendto(socket_fd,&message_out,sizeof(struct my_message),0,(struct sockaddr*)socket_address,sizeof(*socket_address))) == -1){
    errorExit("initializing sendto");
  }else{
	  message_out.number = 0;
    char presentation_address[100] = "";
    inet_ntop(AF_INET,&socket_address->sin_addr,presentation_address,sizeof(presentation_address));
    printf("Rozpoczynam gre z %s. Napisz 'koniec' by zakonczyc\n",argv[1]);
  }
  
  int start;
  struct my_message message_in = {0};
  while(1){
    receiveMessage(socket_fd,message_in,&start);

    sendMessage(socket_fd,message_out,&start);
  } 
  

  return 0;
}
