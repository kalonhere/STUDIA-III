#include <endian.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<string.h>

/* Brak obslugi bledow! */

int main() {

	int    fifodesc;
	char   buf[1024];
	int    chars;
  pid_t pid;
	mkfifo("mojafifo", 0777);

	printf("Serwer: czekam na komunikaty klientow...\n");
  if((pid = fork()) == -1){exit(EXIT_FAILURE);}
  if(pid != 0){
    fifodesc = open("mojafifo", O_RDONLY | O_NDELAY);
    if(fifodesc != -1) {
      printf("otwarto fifodesc\n");
      while(1) {
        chars = read(fifodesc, &buf, sizeof(buf));
        if(chars > 0) {
          buf[chars] = '\0';
          printf("Klient przyslal %2d bajtow: %s", chars-1, buf);
        }
      }
      printf("zamykam fifo\n");
      close(fifodesc);
    }
    printf("koncze serwer\n");

  }else if(pid == 0){
    char buffer[255];
    while((fifodesc = open("mojafifo",O_WRONLY)) == -1){sleep(1);};
    printf("Podaj tekst: \n");
    scanf("%s",buffer);
    fflush(stdin);
    if(write(fifodesc,buffer,strlen(buffer)) == -1){
      perror("nuh uh write nie dziala");
    }else{
      printf("wpisano");
    }


    exit(EXIT_SUCCESS);
  }




	return 0;

}
