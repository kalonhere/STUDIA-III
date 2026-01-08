#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>

/* Brak pelnej obslugi bledow! */

int main() {
	int   msqid;
	key_t msqkey;
  //struct containing message queue data structure(curently empty)
	struct msqid_ds buf;
	struct my_msg {
	    long mtype;
		char txt[15];
	}  msg;
  //create key using this file and project id =1
	msqkey = ftok("MSQ_statystyki.c", 1);
	//msqid is a message queue identifier, with 0644 perms and creates file if non existent
	if( (msqid = msgget(msqkey, 0644 | IPC_CREAT)) == -1) {
		printf("Funkcja msgget zwrocila blad!\n");
		return -1;
	}
  //wiadomix
	printf("Utworzona/otwarta kolejka, klucz: %d, id: %d\n", msqkey, msqid);

  //typ wiadomosci = 9, czysto dowolne
	msg.mtype  = 9;
  //ustawienie wiadomosci na "Test"
	strcpy(msg.txt, "Test");

	printf("Wysylam testowy komunikat... (%s)\n", 
      //wyslij(id_kolejki, wskaznik na wiadomosc, rozmiar obszaru wiadomosci, dodatkowe flagi)
		 (msgsnd(msqid, &msg, sizeof(msg.txt), 0)==-1)?"Blad!":"OK");

  //copy message queue stats from kernel to buffer
	msgctl(msqid, IPC_STAT, &buf);
			

	printf("Pojemnosc kolejki: %lu bajtow\n", buf.msg_qbytes);
	printf("Biezaca liczba bajtow w kolejce:      %lu\n", buf.msg_cbytes);
	printf("Biezaca liczba komunikatow w kolejce: %lu\n", buf.msg_qnum);
	printf("PID ostatnio wywolujacego msgsnd:     %d\n",  buf.msg_lspid);
	printf("PID ostatnio wywolujacego msgrcv:     %d\n",  buf.msg_lrpid);
  //destroy message queue
  msgctl(msqid,IPC_RMID,0);

	return 0;
}
