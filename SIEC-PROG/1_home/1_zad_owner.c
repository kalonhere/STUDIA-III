#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pwd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<grp.h>
#include<sys/types.h>

void debug_message(char *message){
  printf("** %s **\n",message);
}


int main(int argc, char* argv[]){
  //allocate stat structure for file info
  struct passwd *user_info_id; 
  struct stat file_stat;
  struct group *group_info_id;
  //read file to file_stat struct
  if((stat(argv[1],&file_stat)) == -1 ){
    perror("STAT FUNCTION ERROR [LINE 12]");
    //exit(EXIT_FAILURE);
  }
  debug_message("File read");

  user_info_id = getpwuid(file_stat.st_uid);
  group_info_id = getgrgid(file_stat.st_gid);
  debug_message("Fetched info");
  printf("user name: %s \n",user_info_id->pw_name);
  printf("group name: %s \n",group_info_id->gr_name);
  return 0;
} 
