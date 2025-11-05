#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define BUFF_SIZE = 1024

int main(){
  char *text = "Zwykly komunikat\n";
  write(1, text, strlen(text));
  
  char *text_error = "Straszny blad! \n";
  write(2, text_error, strlen(text));
        
  return 0;
}
