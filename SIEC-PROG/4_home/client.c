#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>


int main(){
  system("clear");
  pid_t server_pid;
  printf("Type servers pid: ");
  scanf("%u",&server_pid);

  while(1){
    system("clear");
    int menu;
    printf("Select action:\n");
    printf("0 == End Action\n");
    printf("1 == Send SIGUSR1 to server\n");
    printf("2 == Send SIGUSR2 to server\n");
    scanf("%d",&menu);
    if(menu == 0){break;}
    if(menu == 1){
      if((kill(server_pid, SIGUSR1)) == -1){
        perror("Error when sending signal.");
        exit(EXIT_FAILURE);
      }
    }//USR1 case
    if(menu == 2){
      if((kill(server_pid, SIGUSR2)) == -1){
        perror("Error when sending signal.");
        exit(EXIT_FAILURE);
      }
    }//USR1 case
  }//while 


  return 0;
}
