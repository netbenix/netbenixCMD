#ifdef _WIN32 || _WIN64
#include <windows.h>
#endif

#ifdef linux
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <gdk/gdk.h>
#include <gdk/gdkconfig.h>
#include <gtk/gtk.h>
#endif


#include "commands/test_gtk.h"
#endif


#include "etc/logo.h"
#include "utils/logger.h"
#include "utils/os_info.h"
#include "commands/help.h"

#define VERSION "0.1.0"
#define AUTHOR "netbenix"

void exit_app(){
    logger("Exiting.");
    exit(0);
}

int main(int argc, char *argv[]){
    char buffer[1024];
    logger("================================================");
    snprintf(buffer, sizeof(buffer), "Starting netbenixCMD (Version: %s)", VERSION);
    logger(buffer);
    log_Specs();
    if(argc < 2){
        printf("Not enough Arguments. Please use --help for more information.\n");
        snprintf(buffer, sizeof(buffer), "[ERROR] Not enough Arguments. Total Arguments: %d", argc -1);
        logger(buffer);
        exit_app();
    }

    showLogo(); //Show the Logo
    logger("Logo Displayed.");

    if(!strcmp(argv[1], "--help")){
        outputHelp();
    } else if (!strcmp(argv[1], "--gtk-test")){
        #ifdef linux
        createTestWindow();
        #else
        printf("[ERROR] gtk-test is linux only.\n");
        logger("[ERROR] gtk-test is linux only.");
        #endif
    } else if (!strcmp(argv[1], "--os-info")){
        logger("Showing OS Information");
        print_Specs();
    } else {
        printf("Argument unknown. Please use --help for more information.\n");
        snprintf(buffer, sizeof(buffer), "[ERROR] Argument unknown. Given argument: %s", argv[1]);
    }
    
    printf("\n");
    exit_app();
    return 0;
}


