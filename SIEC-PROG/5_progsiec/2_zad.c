#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

enum FILE_DESCRIPTOR{
    READ = 0,
    WRITE = 1
};

int main(int argc, char *argv[]){
    int pipe_fd_parent[2]; //writing to the child
    int pipe_fd_child[2]; //reading from the child
    pid_t pid;
    
    int number;
    scanf("%d",&number);

    if(pipe(pipe_fd_parent) == -1){
        perror("pipe1");
        exit(EXIT_FAILURE);
    }
    if(pipe(pipe_fd_child) == -1){
        perror("pipe2");
        exit(EXIT_FAILURE);
    }


    pid = fork();
    if(pid == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if(pid==0){//child process
        close(pipe_fd_parent[WRITE]); //close unused writing end
        read(pipe_fd_parent[READ], &number,sizeof(number)); //read from parent
        close(pipe_fd_parent[READ]);//close parent
    
        number = number*2;
        close(pipe_fd_child[READ]);//close unused reading end
        write(pipe_fd_child[WRITE],&number,sizeof(number)); //write to parent
        close(pipe_fd_child[WRITE]);//close writing end
        _exit(EXIT_SUCCESS); //exit
    }else{
        close(pipe_fd_parent[READ]); //close reading pipe 
        write(pipe_fd_parent[WRITE],&number,sizeof(number));//write to parent
        close(pipe_fd_parent[WRITE]);

        close(pipe_fd_child[WRITE]);
        read(pipe_fd_child[READ],&number,sizeof(number));
        printf("Solution: %d \n",number);
        close(pipe_fd_child[WRITE]);
        
        wait(NULL);
        exit(EXIT_SUCCESS);
        
    }





    return 0;
}
