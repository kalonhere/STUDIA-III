#include <stdio.h>
#include <dirent.h>

// brak obslugi bledow!

int main() {
	DIR* dirp;
	struct dirent* direntp;

	dirp = opendir(".");
	for(;;) {
		direntp = readdir(dirp);
		if(direntp == NULL) break;
		printf( "%s\n", direntp->d_name);
	}
														        
	closedir(dirp);																			    
	return 0;
}
