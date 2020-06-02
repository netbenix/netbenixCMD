#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>

#include "os_info.h"
#include "logger.h"

char* getOS(){
	char *os;
	os = malloc(sizeof (char) * 20);
	#ifdef linux
	strcpy(os, "Linux");
	#endif

	return os;
}

char* getArch(){
	char *arch;
	arch = malloc(sizeof(char) * 20);

	#ifdef __amd64
	strcpy(arch, "64-Bit");
	#else
	strcpy(arch, "32-Bit");
	#endif

	return arch;
}

void print_Specs(){
	printf("OS: %s\n", getOS());
	printf("Architecture: %s\n", getArch());
	free(NULL);
}

void log_Specs(){
	char buffer[1024];
	logger("[INFO] System Information:");
	snprintf(buffer, sizeof(buffer), "[INFO] OS: %s", getOS());
	logger(buffer);
	snprintf(buffer, sizeof(buffer), "[INFO] Architecture: %s", getArch());
	logger(buffer);
	free(NULL);
}
