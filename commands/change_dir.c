#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

#include "change_dir.h"
#include "../utils/logger.h"

void changeCurrentWorkDir(char *arg[]){
	DIR *d;
	struct dirent *dir;
	d = opendir(arg[1]); //Try to open directory
	if(d == NULL){ //Check if directory exists
		printf("Folder not found.\n");
		return;
	} else {
		chdir(arg[1]); //If directory exists, change workpath
	}
	closedir(d); //Close directory
}