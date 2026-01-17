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
  freeaddrinfo(address_information);
  exit(EXIT_FAILURE);
}


void extractAdressInfo(char **address, char* port){
  if((getaddrinfo(address[1],port,NULL,&address_information)) != 0){
    errorExit("getaddrinfo");
  }
  //sprawdz poprawny adres ip 
  socket_address = (struct sockaddr_in*)address_information->ai_addr;
  address[1] = inet_ntoa(socket_address->sin_addr);

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
      //sprawdzenie czy znajduje sie cos poza liczba
      if(buffer[i] < 48 || buffer[i] > 57){
        if(strcmp(buffer,"koniec\n") == 0){
          //jezeli wiadomosc to koniec
            message_out.number = -2;
            strcpy(message_out.chat,"");
          if((sendto(socket_fd,&message_out,sizeof(struct my_message), 0, (struct sockaddr*)socket_address,sizeof(*socket_address))) == -1){
            errorExit("sendto(sendMessage) | end of game");
          }
          freeaddrinfo(address_information);
          exit(EXIT_SUCCESS);

        }
        //jezeli wiadomosc != 'koniec'. To skopiuj wiadomosc
        strcpy(message_out.chat,buffer);
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      //jezeli podano niepoprawna liczbe
      int new_number = atoi(buffer);
      if((new_number <= *start) || (new_number > 50) || ((new_number - *start )) > 10){
        printf("Nie podano poprawnej wartosci liczby, musi byc wieksza od obecnej wartosci oraz mniejsza lub rowna roznicy 10\n");
        continue;
      }else{
        //jezeli podano poprawna liczbe, skopiuj do wiadomosci
        strcpy(message_out.chat,"");
        message_out.number = new_number;
      }
    }
    if(flag == 1){
      //wyslanie wiadomosci chatu oraz przejscie na poczatek petli while
    	flag = 0;
	    if((sendto(socket_fd,&message_out,sizeof(struct my_message), 0, (struct sockaddr*)socket_address,sizeof(*socket_address))) == -1){
        errorExit("sendto(sendMessage) | chat");
      }
      continue;
    }
    //wyslanie nowej liczby
    flag = 0;
    if((sendto(socket_fd,&message_out,sizeof(struct my_message), 0, (struct sockaddr*)socket_address,sizeof(*socket_address))) == -1){
      errorExit("sendto(sendMessage) | chat");
    }
    //jezeli liczba == 50. Wygrana
    if(message_out.number == 50){
      printf("Brawo! Wygrales!\n");
      freeaddrinfo(address_information);
      exit(EXIT_SUCCESS);
    }
    break;
  }
}


void receiveMessage(int socket_fd, struct my_message message_in,int *start){
  while(1){
    recvfrom(socket_fd,&message_in,sizeof(struct my_message),0,NULL,NULL);
    //odebranie wiadomosci potwierdzajacej dolaczenie
    if(message_in.number == -1){//first in
      printf("\e[1;32m%s\e[m dolaczyl sie do gry.\n",message_in.nickname);
      *start = rand() % 10 + 1;
      printf("Losowa wartosc poczatkowa: \e[1;34m%d\e[m, podaj kolejna wartosc.\n",*start);
      message_in.number = 0;
      break;
    }else if (strlen(message_in.chat) != 0){
      //odebranie wiadomosci chatu
      printf("\e[1;32m%s\e[m przesyla wiadomosc: \e[1;34m%s\e[m",message_in.nickname,message_in.chat);
    }else if(message_in.number == -2){
      //odebranie wiadomosci konczacej gre
      printf("\e[1;32m%s\e[m zakonczyl gre.\n",message_in.nickname);
      freeaddrinfo(address_information);
      exit(EXIT_SUCCESS);
    }else if(message_in.number == 50){
      //odebranie liczby 50
      printf("\e[1;32m%s\e[m podal wartosc \e[1;34m50\e[m! Przegrana!\n",message_in.nickname);
      freeaddrinfo(address_information);
      exit(EXIT_SUCCESS);
    }else{
      //odebranie liczby != 50
      printf("\e[1;32m%s\e[m podal liczbe: \e[1;34m%d\e[m, podaj kolejna wartosc.\n",message_in.nickname,message_in.number);
      *start = message_in.number;
      break;
    }//chat
  }

  
}



int main(int argc, char *argv[]){
  //witamy
  printf("\e[1;30;104m====Witamy w grze '50' wersja B====\e[m\n");


  srand(time(NULL));
  //sprawdz ilosc argumentow
  if((argc < 3) || (argc > 4)){
    printf("\e[1;31mZla ilosc argumentow\e[m\nUzycie: adres port [nick]\n");
    return 0;
  }
  
  //sprawdz poprawny numer portu
  if((atoi(argv[2])) > 65535){
    printf("\e[1;31m=====ERROR=====\e[m\n");
    printf("Niepoprawny numer portu\n");
    freeaddrinfo(address_information);
    exit(EXIT_FAILURE);

  }

  //wyluskaj informacje na temat adresu adresata 
  extractAdressInfo(argv,argv[2]);
  //stworzenie socketu
  int socket_fd;
  if((socket_fd = socket(socket_address->sin_family,SOCK_DGRAM,0)) == -1){
    errorExit("socket");
  } 
  bindLocalAddress(socket_fd);


  //interpretacja nick/adres
  struct my_message message_out = {0};
  if(argc == 4){
    strcat(message_out.nickname,argv[3]);
  }else {
    strcat(message_out.nickname,argv[1]);
  }
  //wysylanie wiadomosci o dolaczeniu do gry
  message_out.number = -1;
  int bytes = 0;
  if((bytes = sendto(socket_fd,&message_out,sizeof(struct my_message),0,(struct sockaddr*)socket_address,sizeof(*socket_address))) == -1){
    errorExit("initializing sendto");
  }else{
    //reset wartosci liczby w strukturze wiadomosci
	  message_out.number = 0;
    printf("Rozpoczynam gre z \e[1;32m%s\e[m. Napisz '\e[1;31mkoniec\e[m' by zakonczyc\n",argv[1]);
  }
  
  //zmienna przechowujaca aktualna liczbe
  int start;
  struct my_message message_in = {0};
  while(1){
    //petla gry
    receiveMessage(socket_fd,message_in,&start);

    sendMessage(socket_fd,message_out,&start);
  } 
  

  return 0;
}
