#include<stdio.h>
#include<stdlib.h>
#include <sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/msg.h>
#include<signal.h>
#include<unistd.h>

/* A. Mroz - zadanie na SK  do modyfikacji */
/* Brak pelnej obslugi bledow! */

#define MY_MSG_SIZE 64
#define LOG_SIZE 1
key_t shmkey;
int   shmid;
char  *shared_data;
int *log_pointer;

int shm_log_id;
int logkey;
void sgnhandle(int signal) {
	printf("\n[Serwer]: dostalem SIGINT => koncze i sprzatam...");
	printf(" (odlaczenie: %s, usuniecie: %s)\n", 
			(shmdt(shared_data) == 0)        ?"OK":"blad shmdt",
			(shmctl(shmid, IPC_RMID, 0) == 0)?"OK":"blad shmctl");


	printf(" ( odlaczenie: %s, usuniecie: %s)\n", 
			(shmdt(log_pointer) == 0)        ?"OK":"blad shmdt",
			(shmctl(shm_log_id, IPC_RMID, 0) == 0)?"OK":"blad shmctl");
	exit(0);
}


int main(int argc, char * argv[]) {

	struct shmid_ds buf;

	signal(SIGINT, sgnhandle);

	printf("[Serwer]: tworze klucz...");
    if( (shmkey = ftok(argv[1], 1)) * (logkey = ftok(argv[1],2)) < 0) {
	    printf("Blad tworzenia klucza!\n");
		exit(1);
	}
	printf(" OK (klucz: %d)\n", shmkey);
	printf(" OK (klucz log: %d)\n", logkey);
	

  
/////////////////////////////////////////////////////////////////////////
  printf("Tworze segment licznika\n");
  if((shm_log_id = shmget(logkey,LOG_SIZE*sizeof(int),0600|IPC_CREAT|IPC_EXCL)) == -1){
    printf("blad tworzenia loggera\n");
    perror("  ");
    exit(EXIT_FAILURE);
  }

  if((log_pointer = (int*)shmat(shm_log_id,(void *)0,0)) == (void *)-1){
    printf("blad przy dolaczaniu loggera\n");
    exit(EXIT_FAILURE);
  }
  
  log_pointer[0] = 0;
  

/////////////////////////////////////////////////////////////////////////
	printf("[Serwer]: tworze segment pamieci wspolnej...");
	if( (shmid = shmget(shmkey, MY_MSG_SIZE * sizeof(char), 
						0600 | IPC_CREAT | IPC_EXCL)) == -1) {
		printf(" blad shmget!\n");
    perror("  ");
		exit(1);
	}


	shmctl(shmid, IPC_STAT, &buf);
	printf(" OK (id: %d, rozmiar: %zub)\n", shmid, buf.shm_segsz);
	
	printf("[Serwer]: dolaczam pamiec wspolna...");
	shared_data = (char *) shmat(shmid, (void *)0, 0);
	if(shared_data == (char *)-1) {
		printf(" blad shmat!\n");
		exit(1);
	}
	printf(" OK (adres: %lX)\n", (long int)shared_data);

	shared_data[0] = '\0'; /* umowne "wyczyszczenie" */

	printf("[Serwer]: zawartosc pamieci wspolnej:\n");

    //printf("liczba wpisow: %d\n",log_pointer[0]);
	while(8) {
		printf("\33[2K\rliczba wpisow: %d |%s",log_pointer[0],shared_data);
		fflush(stdout); /* trik by nadpisywanie sie udalo */
		sleep(1);
	}
	
	return 0;

}
