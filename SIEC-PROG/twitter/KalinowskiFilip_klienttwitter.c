#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>

//stale
#define NICK_LENGTH 20
#define MESSAGE_SIZE 100
//#define LOG_SIZE 1
//struktura wiadomosci
typedef struct entry{
  int id;
  int likes;
  char nickname[NICK_LENGTH];
  char message[MESSAGE_SIZE];

} entry ;

key_t twitterkey;
int twitterid;
struct entry *twitterpointer;

int number_of_entries;


//wypisz posty
void listEntries(int number_of_entries){
  system("clear");
  //przywitanie
  printf("\e[1;30;104m====TWITTER WERSJA C====\e[m\n");

  printf("\e[1;33m====================================\e[m\n");
  for(int i = 0; i < number_of_entries; i++){
    if(twitterpointer[i].id != 0){
      printf("[ID Postu: %d]\n",twitterpointer[i].id);
      printf("nazwa uzytkownika: \e[1;32m%s\e[m\n",twitterpointer[i].nickname);
      printf("tresc: \e[1;34m%s\e[m\n",twitterpointer[i].message);
      printf("ilosc polubien: \e[1;31m%d\e[m\n\n",twitterpointer[i].likes);
    }
  }
  printf("\e[1;33m====================================\e[m\n");
}

int main(int argc, char* argv[]){
  system("clear");
  
  srand(time(NULL));
  
  //sprawdzenie ilosci argumentow
  if((argc < 3) || (argc>4)){
    printf("zla liczba argumentow\n");
    exit(EXIT_SUCCESS);
  }
  //generowanie klucza
  if((twitterkey = ftok(argv[1], 1)) == -1){
    perror("generating key error");
    exit(EXIT_FAILURE);
  }
  
  //asocjacja segmentu pamieci
  if((twitterid = shmget(twitterkey,0,0)) == -1){
    perror("couldn't read memory");
    exit(EXIT_FAILURE);
  }
  //dolaczenie pamieci 
  if((twitterpointer = (entry *) shmat(twitterid,(void*) 0,0)) == (entry *)-1){
    perror("shmat error");
    exit(EXIT_FAILURE);
  }

  
  struct shmid_ds buffor;
  shmctl(twitterid,IPC_STAT,&buffor);
  number_of_entries = (buffor.shm_segsz / sizeof(entry));
  

  //rozne kombinacje 
  if(argc == 3){
    if(strcmp(argv[2],"P")){
      printf("zla liczba parametrow, nie kombinuj\n");
      exit(EXIT_FAILURE);
    }else if (strcmp(argv[2],"N")){
      //polubienie posta, opcja P
      listEntries(number_of_entries);
      int numerek;
      printf("Podaj ID wpisu ktory chcesz polubic: ");
      scanf("%d",&numerek);
      fflush(stdin);
      fflush(stdout);
      for(int i = 0; i< number_of_entries;i++){
        if(twitterpointer[i].id == numerek){
          twitterpointer[i].likes++;
          printf("Polubiono! <3\n");
          exit(EXIT_SUCCESS);
        }else{
          continue;
        }
      }
      printf("nie ma postu o takim id\n");
      exit(EXIT_FAILURE);
    }else{
      printf("zle argumenty\n");
      exit(EXIT_FAILURE);
    }
  }
  //dalsze kombinacje
  if(argc == 4){
    if(strcmp(argv[2],"N")){
      printf("Zla liczba parametrow\n");
      exit(EXIT_FAILURE);
    }else if(strcmp(argv[2],"P")){
      //Dodanie nowego posta, opcja N
      for(int i = 0; i< number_of_entries;i++){
        if(twitterpointer[i].id == 0){
          //printf("pierwsze generowanie\n");
          generate_id:
          twitterpointer[i].id = rand() % 100 +1;
          //printf("wygenerowano id : %d\n",twitterpointer[i].id);
          for(int j = 0; j< number_of_entries;j++){
            if(i!=j && twitterpointer[i].id ==twitterpointer[j].id){
              goto generate_id;
            }

          }
          printf("\e[1;30;104m====TWITTER WERSJA C====\e[m\n");
          printf("TWORZENIE POSTU \n");
          strcpy(twitterpointer[i].nickname,argv[3]);
          printf("Dodano nazwe uzytkownika: %s\n",argv[3]);

          printf("Podaj tresc postu: ");
          char message_buffer[MESSAGE_SIZE];
          fgets(message_buffer,MESSAGE_SIZE,stdin);
          message_buffer[strlen(message_buffer)-1] = '\0';
          strcpy(twitterpointer[i].message,message_buffer);

          twitterpointer[i].likes = 0;
          printf("Dodano post!\n");
          exit(EXIT_SUCCESS);
        }else{
          continue;
        }
      }
      printf("niestety nie ma wolnych postow :(\n");
    }else {
      printf("Zle parametry\n");
    }
  }
  //shmdt(logpointer);
  shmdt(twitterpointer);
  
  return 0;
}

