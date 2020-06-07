#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

#include "change_dir.h"
#include "../utils/logger.h"

void changeCurrentWorkDir(char *arg[]){
	DIR *d;
	struct dirent *dir;
	d = opendir(arg[1]);
	if(d == NULL){
		printf("Folder not found.\n");
		return;
	} else {
		chdir(arg[1]);
	}
	closedir(d);
}