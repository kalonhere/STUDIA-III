#include<stdio.h>
#include<unistd.h>




int main(){
    FILE *file_pointer;
    char buffer[255];
    file_pointer = popen("/usr/bin/ls","r");

    while(fgets(buffer,255,file_pointer)){
        printf("%s",buffer);
    }
    pclose(file_pointer);






    return 0;
}
