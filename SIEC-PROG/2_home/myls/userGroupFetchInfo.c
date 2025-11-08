#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<dirent.h>
#include<errno.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include"userGroupFetchInfo.h"

void userGroupFetchInfo(struct stat file_data){
  errno = 0;
  unsigned int user_id = file_data.st_uid;
  unsigned int group_id = file_data.st_gid;

  //fetch user info
  struct passwd *user_data = getpwuid(user_id);
  if(user_data == NULL && errno == 0){perror("User not found"); exit(EXIT_FAILURE);}
  if(user_data == NULL && errno != 0){perror("Couldn't fetch user data"); exit(EXIT_FAILURE);}
  printf("%s\n",user_data->pw_name);
  
  //fetch group info
  struct group *group_data = getgrgid(group_id);
  if(group_data == NULL && errno == 0){perror("group not found"); exit(EXIT_FAILURE);}
  if(group_data == NULL && errno != 0){perror("Couldn't fetch group data"); exit(EXIT_FAILURE);}
  printf("%s\n",group_data->gr_name);


  


}
