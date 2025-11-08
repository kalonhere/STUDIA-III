#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<dirent.h>
#include<errno.h>
#include<sys/stat.h>

// MODE, HARD LINKS, USERNAME, GROUP NAME. 
      //print scheme -> printf(": %lu \n ",file_data.);
#include"unmaskMode.h"
#include"userGroupFetchInfo.h"

//alboconstcharconstmozeconstchar*wsumietovoidtezmozebyc
void printFileData(char* file_pathname,struct stat file_data){
  printf("======%s======\n",file_pathname);

  printf("%s",unmaskMode(file_data, PRIVELEGES));
  unmaskMode(file_data, MONTH);
  unmaskMode(file_data, TIME);
  printf("%lu \n",file_data.st_nlink);
  userGroupFetchInfo(file_data);

  //printf("user id : %u \n",file_data.st_uid);
  //printf("group id: %u \n",file_data.st_gid);
  printf("%lu \n",file_data.st_size);
}



#define FLAG 0
#define BUFS 1024

void debug(char *text){
  if(FLAG == 1){
  printf("****%s****\n",text);
  }
}


int main(int argc, char* argv[]){
  if(argc == 1){
    DIR *directory_pointer;
    if((directory_pointer = opendir(".")) == NULL){
      perror("Couldn't open directory");
      exit(EXIT_FAILURE);
    }//open dir
    debug("directory opened");
    
    //setting variables
    struct dirent *directory_content;
    errno = 0;
    struct stat file_data;

    //for(;;){
      directory_content = readdir(directory_pointer);
      //break on end of file
      if(directory_content == NULL && errno == 0){exit(EXIT_SUCCESS);}
      //error happened
      if(directory_content == NULL && errno != 0){perror("couldn't read directory content"); exit(EXIT_FAILURE);}
      
      char *file_pathname = (directory_content->d_name);
      if((stat(file_pathname,&file_data)) == -1){
        perror("Couldn't read file data");
        exit(EXIT_FAILURE);
      }

      printFileData(file_pathname,file_data);

    //}// or
  }//argc = 1


  return 0;
}
