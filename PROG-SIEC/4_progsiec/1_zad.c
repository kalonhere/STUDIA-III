#include<unistd.h>
#include<stdio.h>



int main(){
    
    int i;
    for(i = 0; i<10;i++){
        printf("Dzialam od %d sekund", i);
        sleep(1);
    }

    return 0;

}
