#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<signal.h>
#include<unistd.h>

/* Brak pelnej obslugi bledow! */

#define MY_MSG_SIZE 64

key_t msqkey;
int   msqid;

struct my_msg {
	long mtype;
	char txt[MY_MSG_SIZE];
}	msg;

char buf[MY_MSG_SIZE];
int  result;


int main(int argc, char * argv[]) {

	printf("[Klient]: tworze klucz...");
	msqkey = ftok(argv[1], 1);
	if( msqkey != -1 )
		printf(" OK (klucz:  %d)\n", msqkey);
	else {
		printf("Problem z generowaniem klucza!\n");
		exit(1);
	}

	printf("[Klient]: otwieram kolejke...");
	if( (msqid = msgget(msqkey, 0)) == -1 ) {
		printf("Problem z otwarciem kolejki!\n");
		exit(1);
	}
	printf(" OK (id: %d)\n", msqid);


	printf("[Klient]: podaj komunikat ktory chcesz przeslac do serwera:\n");
	fgets(buf, MY_MSG_SIZE, stdin); /* '\n' idzie tez do buf! */
	
	printf("[Klient]: podaj typ komunikatu ( >0 ):\n");
  scanf("%ld",&msg.mtype);
	/* przygotowanie paczki do wyslania */
	//msg.mtype = 1;
	strcpy(msg.txt, buf);
	
	result =  msgsnd(msqid, (void *)&msg, MY_MSG_SIZE, 0);
	printf("[Klient]: wyslalem komunikat (%s), koncze.\n", 
			(result==-1)?"cos poszlo nie tak":"OK");

	return 0;

}
