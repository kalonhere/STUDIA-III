#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>



//stale
#define NICK_LENGTH 20
#define MESSAGE_SIZE 100

//struktura wiadomosci
typedef struct entry{
  int id;
  int likes;
  char nickname[NICK_LENGTH];
  char message[MESSAGE_SIZE];

} entry ;

struct shmid_ds buffer;

key_t twitterkey;
int twitterid;
struct entry *twitterpointer;


int number_of_entries;

int currentEntries(int number_of_entries){
  int out =0;
  for(int i = 0; i< number_of_entries;i ++){
    if(twitterpointer[i].id != 0){out++;}
  }
  return out;
}

//wypisz posty
void listEntries(int number_of_entries){
  system("clear");
  //przywitanie
  printf("\e[1;30;104m====TWITTER WERSJA C====\e[m\n");

  shmctl(twitterid,IPC_STAT,&buffer);
  printf("Limit wpisow: [%d/%lu]\n",currentEntries(number_of_entries),(buffer.shm_segsz/sizeof(entry)));
  printf("\e[1;33m====================================\e[m\n");
  for(int i = 0; i < number_of_entries; i++){
    if(twitterpointer[i].id != 0){
      printf("[ID Postu: %d]\n",twitterpointer[i].id);
      printf("nazwa uzytkownika: \e[1;32m%s\e[m\n",twitterpointer[i].nickname);
      printf("tresc: \e[1;34m%s\e[m\n",twitterpointer[i].message);
      printf("ilosc polubien: \e[1;31m%d\e[m\n\n",twitterpointer[i].likes);
    }
  }
  printf("\e[1;33m====================================\e[m");

  printf("\n\nPID ostatniego klienta: %d\n",buffer.shm_lpid);
}

void signalHandler(int sig){
  //SIGNAL STOP
  if(sig == SIGTSTP){
    listEntries(number_of_entries);
  }
  //SIGNAL INTERRUPT
  if(sig == SIGINT){
    printf("closing\n");
    if(shmdt(twitterpointer) == 0){printf("odlaczono twitter\n");}else{printf("nie mozna odlaczyc twitter\n");}
    if(shmctl(twitterid,IPC_RMID,0) == 0){printf("usunieto twitter\n");}else{printf("nie mozna usunac twitter\n");}
    exit(EXIT_SUCCESS);
  }
}

int main(int argc, char* argv[]){
  system("clear");
  //sprawdzenie ilosci argumentow
  if(argc != 3){
    printf("zla liczba argumentow");
    exit(EXIT_FAILURE);
  }


  //signal handler
  number_of_entries = atoi(argv[2]);
  signal(SIGINT,signalHandler);
  signal(SIGTSTP,signalHandler);
  //generacja klucza
  if((twitterkey = ftok(argv[1], 1)) == -1){
    perror("generating key error");
    exit(EXIT_FAILURE);
  }

  
  
  //printf("creating shared memory segment\n");
  //generowanie wspolnej pamieci twittera
  if((twitterid = shmget(twitterkey,((atoi(argv[2]) * sizeof(entry))),0666|IPC_CREAT|IPC_EXCL)) == -1){
    perror("couldn't allocate memory");
    exit(EXIT_FAILURE);
  }

  
  //przylaczanie pamieci
  if((twitterpointer = (entry *) shmat(twitterid,(void*) 0,0)) == (entry *)-1){
    perror("shmat error");
    exit(EXIT_FAILURE);
  }
  
  //zerowanie indeksow/wpisow
  for(int i = 0; i < (atoi(argv[2])); i++){
    twitterpointer[i].id = 0;
  }
  
  //wpisanie przykladowego wpisu
  twitterpointer[3].id =3;
  strcpy(twitterpointer[3].nickname,"essonator");
  strcpy(twitterpointer[3].message,"pozdro od admina");
  twitterpointer[3].likes = 3;
  
  //wypisanie wpisow
  listEntries(number_of_entries);
  //petla
  while(1){
  };
  
  return 0;
}
