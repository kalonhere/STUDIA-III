#include <stdio.h>
#include<string.h>

void debug_message(char * message){

  #ifdef debug
  printf("***** %s *****\n",message);
  #endif

}

int main(){


  printf("before debug message\n");
  debug_message("helo :3");
  printf("aftert debug message\n");
  return 0;
}


