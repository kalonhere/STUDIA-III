#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>
#include<stdlib.h>



int main(){
    pid_t pid;
    int status;

    pid = fork();
    if(pid == 0){
        int input;
        printf("Podaj dowolna liczbe: ");
        scanf("%d",&input);
        exit(input);
    }else if (pid > 0){
        wait(&status);
        printf("PID potomka: %d, STATUS:%d \n",pid,WEXITSTATUS(status));
        
    }
    




    return 0;
}
