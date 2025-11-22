#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


int main() {

	printf("Uruchamiam ls -l za pomoca exec\n");
	//execlp("ls","ls","-l", (char *)0);
  system("ls -l");
	printf("Wazny komunikat na koniec\n");
	return 0;

}
