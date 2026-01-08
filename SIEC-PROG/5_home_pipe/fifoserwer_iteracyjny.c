#include <endian.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<string.h>
#include<errno.h>
/* Brak obslugi bledow! */

int main() {

	int    fifodesc;
	char   buf[1024];
	int    chars;
  pid_t pid;
	//mkfifo("mojafifo", 0777);

  if( (mkfifo("fifkoPifko", 0666) < 0) && (errno != EEXIST) ){
      perror("pipe error");
  }


	printf("Serwer: czekam na komunikaty klientow...\n");
  if((pid = fork()) == -1){exit(EXIT_FAILURE);}
  if(pid != 0){
    fifodesc = open("fifkoPifko", O_RDONLY);
    if(fifodesc < 0){
      perror("blad");
      exit(0);
    }else {
      int i =0;
      printf("otwarto fifodesc\n");
      while(1) {
        //i++;
        //if(i == 5){exit(0);}
        chars = read(fifodesc, buf, 1024);
        //printf("%d",chars);
        if(chars > 0){
          buf[chars] = '\0';
          printf("Klient przyslal %2d bajtow: %s\n" , chars-1, buf);
        }

      }
      printf("zamykam fifo\n");
      close(fifodesc);
    }
    printf("koncze serwer\n");

  }else if(pid == 0){


    if( (fifodesc = open("fifkoPifko", O_WRONLY)) < 0 ){
        perror("blad");
        exit(0);
    }
    char text[255];
    printf("Podaj tekst: ");
    scanf("%s",text);
    write(fifodesc, text, strlen(text)); 



    //char buffer[255];
    //fifodesc = open("fifkoPifko",O_WRONLY);
    //if(fifodesc < 0){printf("blond"); exit(0);}
    //printf("Podaj tekst: \n");
    //scanf("%s",buffer);
    //fflush(stdin);
    //write(fifodesc,buffer,strlen(buffer));

    //wersja inna
    

    //if(write(fifodesc,buffer,strlen(buffer)) == -1){
    //  perror("nuh uh write nie dziala");
    //  exit(EXIT_FAILURE);
    //}else{
    //  printf("wpisano\n");
    //  exit(EXIT_SUCCESS);
    //}
    exit(EXIT_SUCCESS);

  }




	return 0;

}
