#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void handler(int s /*number of signal for which the function was executed */){
    printf("    Signal number: %d was called \n",s);
}

int main(){
    signal(SIGINT,handler);
    signal(SIGTSTP,handler);
    
    int i;
    for(i = 0;;i++){
        printf("Working since %d seconds\n",i);
        sleep(1);
    }

    return 0;
}
