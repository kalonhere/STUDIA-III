#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main() {

	pid_t pid;
    int status;

    printf("Uruchamiam ls -l za pomoca exec\n");
	pid = fork();
    if(pid == 0){
        execlp("ls","ls","-l", (char *)0);
    }
    else {
	    wait(&status);
        printf("Wazny komunikat na koniec\n");
    }

	return 0;

}

