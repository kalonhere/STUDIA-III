#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
enum PIPE_ENUM{
    READ = 0,
    WRITE = 1
};

void signalHandler(int signal){
    printf("Proces potomny zakonczyl dzialanie\n");
}

int main(){
    pid_t pid;
    int pipe_fd[2];

    if(pipe(pipe_fd) == -1){perror("pipe creation error");exit(EXIT_FAILURE);};

    if((pid = fork()) == -1){perror("fork error"); exit(EXIT_FAILURE);}

    if(pid == 0){
        char buffer[255];
        printf("Potomek: podaj napis: \n");
        fgets(buffer,255,stdin);
        for(int i = 0; i <255; i++){
            if(buffer[i] == 'a'){
                buffer[i] = 'A';
            }
        }
        buffer[strlen(buffer)-1] = '\0';
        close(pipe_fd[READ]);
        write(pipe_fd[WRITE],buffer,255);
        close(pipe_fd[WRITE]);
        exit(0);
        
        
            
    }else if(pid != 0){//child
        signal(SIGCHLD,signalHandler);
        char buffer[255];
        close(pipe_fd[WRITE]);
        read(pipe_fd[READ],buffer,255);
        close(pipe_fd[READ]);   
        int character_count = strlen(buffer);
        printf("Przodek: potomek przeslal %d znakow: %s\n",character_count,buffer);
        wait(NULL);
        
    }//parent

    return 0;
}
