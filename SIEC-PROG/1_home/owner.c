#include<stdio.h>
#include<sys/types.h>
#include<pwd.h>
#include<sys/stat.h>

/* Brak obslugi bledow! */

int main(int argc, char **argv) {

	struct stat statbuf;
	struct passwd *pwd;

	stat(argv[1], &statbuf);
	pwd = getpwuid(statbuf.st_uid);

	printf("Wlasciciel: %s\n", pwd -> pw_name);

	return 0;
}
