#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>


int main() {

	struct passwd *uzyt;
	struct group  *grupa;
	uid_t uzytid;
	gid_t grpid;
  //dodane
  pid_t process_id = getpid();
  pid_t parent_process_id = getppid();
  pid_t process_group_id = getpgid(process_id);
	//essa
	uzytid = getuid();
	uzyt = getpwuid(uzytid);
	printf("Rzeczywisty uzytkownik (id, nazwa):  %4d, %s\n",
		uzytid, uzyt->pw_name); 


	grpid = getgid();
	grupa = getgrgid(grpid);
	printf("Rzeczywista grupa (id, nazwa):       %4d, %s\n",
		grpid, grupa -> gr_name);

	uzytid = geteuid();
	uzyt = getpwuid(uzytid);
	printf("Obowiazujacy uzytkownik (id, nazwa): %4d, %s\n",
		uzytid, uzyt->pw_name);

	
	grpid = getegid();
	grupa = getgrgid(grpid);
	printf("Obowiazujaca grupa (id, nazwa):      %4d, %s\n",
		grpid, grupa -> gr_name);
  //dodane
  printf("PID : %u, PPID: %u, PGRP: %u \n",process_id, parent_process_id, process_group_id);
  //essa
	return 0;

}
