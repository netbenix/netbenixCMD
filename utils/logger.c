#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logger.h"


void logger(char message[512]){
	FILE *log_file;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	log_file = fopen("output.log", "a");
	fprintf(log_file, "[%d-%02d-%02d %02d:%02d:%02d] ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	fprintf(log_file, "%s\n", message);
	fclose(log_file);
}