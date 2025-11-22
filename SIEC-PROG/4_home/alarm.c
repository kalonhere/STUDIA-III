#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void signalHandler(int signal_number){
  if(signal_number == SIGALRM){
    printf("ALARM!!!\n");
    alarm(7);
  }
}

int main(int argc, char **argv) {

	int c;
  signal(SIGALRM,signalHandler);
	alarm(7); /* ustawiam budzik na 7 sek. */	

	for(c=0; ; ++c)  {
		
		printf("Dzialam: %2d sek.\n", c);	
		sleep(1);

	}

	return 0;
}

