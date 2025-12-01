#include<stdio.h>
#include<strings.h>


int main(){
    char buffer[256];
    int size = 256;
    getline(buffer,size,stdin);

    printf("tekst: %s",buffer);


    return 0;
}
