#include <unistd.h>
#include <stdio.h>
#include <signal.h>

//made it below with simple signal -> signal_handler asynchronous function 
void alarm_handler(int sig_int){
    printf("SIGALRM was received \n");
    printf("Setting up SIGALRM for 7 seconds \n");
    alarm(7);
}

//here it's made with more complex sigaction function/structure




int main(int argc, char **argv) {
    //signal receiver for alarm_handler function
	//signal(SIGALRM,alarm_handler);

    //sigaction usage (easiest form)
    struct sigaction sa;
    //link the handler
    sa.sa_handler = alarm_handler;
    sigaction(SIGALRM, &sa, NULL);


    int c;
	alarm(7); /* ustawiam budzik na 7 sek. */	
	for(c=0; ; ++c)  {
		printf("Dzialam: %2d sek.\n", c);	
		sleep(1);
	}
	return 0;
}
