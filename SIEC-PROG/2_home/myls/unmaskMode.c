#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<dirent.h>
#include<errno.h>
#include "unmaskMode.h"
#include<time.h>


//const char???? void ???? 
const char *unmaskMode(struct stat file_data,UNMASK_MODE_MODIFIER MASK_MODIFIER){
  struct tm *local_time = localtime(&file_data.st_mtime);
  char output_date[20];
  
  //printf("File modified: %s",(ctime_r(&file_data.st_mtime)));
  //char *input_date = ctime(&file_data.st_mtime);
  if(MASK_MODIFIER == PRIVELEGES){

    int st_mode = file_data.st_mode;
    //int octal_mode = (st_mode & 0777);
    //printf("\noctal: %o\n",octal_mode);
    //POINTER ???? STATIC ???? CHUJ WIE CO ?????
    char *permission_text[11]; *permission_text[10] = '\0';
    //UNMASK FILE TYPE
    if(S_ISREG(st_mode)){*permission_text[0] = '-';}
    if(S_ISDIR(st_mode)){*permission_text[0] = 'd';}
    if(S_ISCHR(st_mode)){*permission_text[0] = 'c';}
    if(S_ISBLK(st_mode)){*permission_text[0] = 'b';}
    if(S_ISFIFO(st_mode)){*permission_text[0] = 'f';}
    if(S_ISLNK(st_mode)){*permission_text[0] = 'l';}
    if(S_ISSOCK(st_mode)){*permission_text[0] = 's';}

    //UNMASK FILE PERMISSION 
    //if((st_mode & S_IRWXU))
    //USER PERMISSIONS
    if((st_mode & S_IRUSR)){*permission_text[1] = 'r';}else{*permission_text[1] = '-';}
    if((st_mode & S_IWUSR)){*permission_text[2] = 'w';}else{*permission_text[2] = '-';}
    if((st_mode & S_IXUSR)){*permission_text[3] = 'x';}else{*permission_text[3] = '-';}
    //if((st_mode & S_IRWXG))                                                     
    //GROUP PERMISSIONS
    if((st_mode & S_IRGRP)){*permission_text[4] = 'r';}else{*permission_text[4] = '-';}
    if((st_mode & S_IWGRP)){*permission_text[5] = 'w';}else{*permission_text[5] = '-';}
    if((st_mode & S_IXGRP)){*permission_text[6] = 'x';}else{*permission_text[6] = '-';}
    //if((st_mode & S_IRWXO))                                                     
    //OTHER PERMISSIONS
    if((st_mode & S_IROTH)){*permission_text[7] = 'r';}else{*permission_text[7] = '-';}
    if((st_mode & S_IWOTH)){*permission_text[8] = 'w';}else{*permission_text[8] = '-';}
    if((st_mode & S_IXOTH)){*permission_text[9] = 'x';}else{*permission_text[9] = '-';}
    
    //printf("%s\n", *permission_text);
    //NIE MAM POJECIA NA CZYM WYKONAC RETURN XDDD
    return *permission_text;
  }
  if(MASK_MODIFIER == MONTH){
    strftime(output_date,20,"%b",local_time);
    printf("%s\n",output_date);
  }
  if(MASK_MODIFIER == TIME){
    strftime(output_date,20,"%d %R",local_time);
    printf("%s\n",output_date);
  }





}
