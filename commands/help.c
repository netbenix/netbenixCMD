#ifdef _WIN32 || _WIN64
#include <windows.h>
#include <stdio.h>
#endif

#ifdef linux
#include <stdlib.h>
#include <stdio.h>
#define OS "LINUX"
#endif

#include "help.h"

void outputHelp(){
	printf("usage: netbenixCMD [option]\n");
	printf("Options:\n");
	printf("--help		: this help page\n");
	printf("--gtk-test	: opens the gtk test ; LINUX ONLY\n");
	printf("--os-info	: shows your os informations\n");
}