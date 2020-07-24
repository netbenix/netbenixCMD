#include <stdlib.h>
#include <stdio.h>

#include "help.h"

//Print the help
void outputHelp(){
	printf("usage: netbenixCMD [option]\n");
	printf("Options:\n");
	printf("--help		: this help page\n");
	printf("--gtk-test	: opens the gtk test\n");
	printf("--sql-test	: make a test connection to a mysql server\n");
	printf("--sys-info	: shows informations about your system\n");
}