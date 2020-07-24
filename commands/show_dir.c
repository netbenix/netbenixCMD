#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>
#include <dirent.h>
#include <string.h>

#include "show_dir.h"
#include "../utils/logger.h"

// Color Codes:
// Reset:       \033[0m
// Red:         \033[0;31m
// Green:       \033[0;32m
// Yellow:      \033[0;33m
// Blue:        \033[0;34m
// Magenta:     \033[0;35m
// Cyan:        \033[0;36m
// BoldRed:     \033[1;31m
// BoldGreen:   \033[1;32m
// BoldYellow:  \033[1;33m
// BoldBlue:    \033[1;34m
// BoldMagenta: \033[1;35m
// BoldCyan:    \033[1;36m

void showDirectory(char *arg[]){
	DIR *d;
	struct dirent *dir;
	char path[PATH_MAX];
	
	d = opendir(arg[1]); //Try to open directory
	if(d == NULL){ //Check if directory exists
		printf("Folder not found.\n");
		return;
	}
	realpath(arg[1], path); //Get the absolute path of the directory
	if(d){
		while((dir = readdir(d))){
			if(dir->d_type == 8){	//IF IS FILE
				printf("\033[1;34m%s\033[0m\n", dir->d_name);
			} else if(dir->d_type == 4){ //IF IS DIR
				printf("\033[1;33m%s\033[0m\n", dir->d_name);
			} else { //IF IS !FILE AND !DIR
				printf("%s\n", dir->d_name);
			}
		}
		closedir(d); //Close directory
	}
}