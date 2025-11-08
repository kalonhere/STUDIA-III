#include <errno.h>
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>

#define FLAG 0

void debug(char *text){
  if(FLAG == 1){
  printf("****%s****\n",text);
  }
}

int main(int argc, char* argv[]){
  //check number of arguments
  if (argc != 2){
    fprintf(stderr,"Error: Wrong number of arguments\n");
    exit(EXIT_FAILURE);
  }
  //create global variable
  DIR *directory_pointer;
  //assign and check pointer
  if((directory_pointer = opendir(argv[1])) == NULL){
    perror("Couldn't open directory");
    exit(EXIT_FAILURE);
  }
  debug("directory opened");
  struct dirent *directory_content;
  errno = 0;
  for(;;){
    directory_content = readdir(directory_pointer);
    //end of file
    if(directory_content == NULL && errno == 0){break;}
    //error when reading
    if(directory_content == NULL && errno != 0){perror("Couldn't read directory content");exit(EXIT_FAILURE);}
    //skip . file
    if((strcmp(directory_content->d_name,".")) == 0){continue;}
    //skip .. file
    if((strcmp(directory_content->d_name,"..")) == 0){continue;}
    //print file
    printf("%s\n",directory_content->d_name);
  }

  if((closedir(directory_pointer)) == -1){
    perror("Error:");
    exit(EXIT_FAILURE);

  }else {debug("directory closed");}
  return 0;
}
