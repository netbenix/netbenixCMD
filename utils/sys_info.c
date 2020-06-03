#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

#include "sys_info.h"
#include "logger.h"
#include <cpuid.h>


static inline void native_cpuid(unsigned int *eax, unsigned int *ebx, 
					unsigned int *ecx, unsigned int *edx){

	asm volatile ("cpuid"
		: "=a" (*eax),
		  "=b" (*ebx),
		  "=c" (*ecx),
		  "=d" (*edx)
		: "0" (*eax), "2" (*ecx));

}

unsigned int getCPUStepping(){
	unsigned eax,ebx,ecx,edx;
	unsigned int stepping;
	eax=1;
	native_cpuid(&eax, &ebx, &ecx, &edx);

	stepping = (eax >> 0) & 0xF;

	return stepping;
}

unsigned int getCPUFamily(){
	unsigned eax,ebx,ecx,edx;
	unsigned int family;
	eax = 1;
	native_cpuid(&eax, &ebx, &ecx, &edx);

	family = (eax >> 8) & 0xF;

	return family;
}

char* getCPUType(){
	unsigned eax,ebx,ecx,edx;
	unsigned int type_id;
	char* type;
	type = malloc(sizeof(char) * 40);
	eax = 1;
	native_cpuid(&eax, &ebx, &ecx, &edx);
	type_id = (eax >> 12) & 0xF;
	if(type_id == 00){
		strcpy(type, "Original OEM Processor");
	}else if(type_id == 01){
		strcpy(type, "Intel Overdrive Processor");
	}else if(type_id == 10){
		strcpy(type, "Dual processor");
	}else{
		strcpy(type, "Reserved value");
	}

	return type;
}

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
	printf("CPU Stepping: %u\n", getCPUStepping());
	printf("CPU Family: %u\n", getCPUFamily());
	printf("CPU Type: %s\n", getCPUType());
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
