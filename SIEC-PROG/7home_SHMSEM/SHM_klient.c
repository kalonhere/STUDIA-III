#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>

/* A. Mroz - zadanie na SK, do modyfikacji */
/* Brak pelnej obslugi bledow! */

#define MY_MSG_SIZE 64
#define LOG_SIZE 1
key_t shmkey;
int   shmid;
char  *shared_data;
char  buf[MY_MSG_SIZE];
int shm_log_id;
int *log_pointer;
int logkey;

int main(int argc, char * argv[]) {
	printf("[Klient]: tworze klucz...");
    if( (shmkey = ftok(argv[1], 1)) * (logkey = ftok(argv[1],2)) < 0) {
		printf("Blad tworzenia klucza!\n");
		exit(1);
	} 
	printf(" OK (klucz:  %d)\n", shmkey);
	printf(" OK (klucz log: %d)\n", logkey);

	printf("[Klient]: otwieram segment pamieci wspolnej...");
	if( (shmid = shmget(shmkey, 0, 0)) == -1 ) {
		printf(" blad shmget\n");
		exit(1);
	}
	printf(" OK (id: %d)\n", shmid);
	
	printf("[Klient]: dolaczam pamiec wspolna...");
	shared_data = (char *) shmat(shmid, (void *)0, 0);
	if(shared_data == (char *)-1) {
		printf(" blad shmat!\n");
		exit(1);
	}
	printf(" OK (adres: %lX)\n", (long int)shared_data);
////////////////////////////
  printf("Tworze segment licznika");
  if((shm_log_id = shmget(logkey,0,0)) == -1){
    printf("blad tworzenia loggera\n");
    exit(EXIT_FAILURE);
  }

  if((log_pointer = (int*) shmat(shm_log_id,(void *)0,0)) == (void *)-1){
    printf("blad przy dolaczaniu loggera\n");
    exit(EXIT_FAILURE);
  }
//////////////////////////////////////
	printf("[Klient]: biezaca zawartosc pamieci wspolnej: ");
	if(shared_data[0] == '\0') printf("PUSTO\n");
	else printf("\n%s\n", shared_data);

	printf("[Klient]: podaj komunikat ktory chcesz wpisac do pamieci wspolnej:\n");
	fgets(buf, MY_MSG_SIZE, stdin);
  //read(STDIN_FILENO,shared_data,MY_MSG_SIZE);
  printf("log: %d",log_pointer[0]);
	log_pointer[0] = 10;
	/* wpisywanie do pamieci dzielonej */
	buf[strlen(buf)-1] = '\0'; /* techniczne: usuwam koniec linii */
	strcpy(shared_data, buf);
	
	printf("[Klient]: wpisalem komunikat do pamieci wspolnej\n");

	shmdt(shared_data);
  shmdt(log_pointer);

	return 0;

}
