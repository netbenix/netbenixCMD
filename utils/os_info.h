#ifndef _OS_INFO_H_
#define _OS_INFO_H_

static inline void native_cpuid(unsigned int *eax, unsigned int *ebx, unsigned int *ecx, unsigned int *edx);
unsigned int getCPUStepping();
unsigned int getCPUFamily();
double getCPUClockSpeed();
char* getCPUType();
char* getOS();
char* getArch();
void print_Specs();
void log_Specs();

#endif