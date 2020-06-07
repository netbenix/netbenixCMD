#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <linux/limits.h>
#include "logger.h"

char loggerDirPath[PATH_MAX];

void logger(char message[512]){
	FILE *log_file;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char buffer[1024];
	snprintf(buffer, sizeof(buffer), "%s/output.log", loggerDirPath);
	log_file = fopen(buffer, "a");
	fprintf(log_file, "[%d-%02d-%02d %02d:%02d:%02d] ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	fprintf(log_file, "%s\n", message);
	fclose(log_file);
}