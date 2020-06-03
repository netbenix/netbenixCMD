#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <gdk/gdk.h>
#include <gdk/gdkconfig.h>
#include <gtk/gtk.h>

#include "commands/help.h"
#include "commands/gtk_test.h"
#include "commands/sql_test.h"
#include "etc/logo.h"
#include "utils/logger.h"
#include "utils/sys_info.h"


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
        logger("Showing Help.");
        outputHelp();
    } else if (!strcmp(argv[1], "--gtk-test")){
        logger("Stating GTK Test.");
        createGTKTestWindow();
    } else if (!strcmp(argv[1], "--sys-info")){
        logger("Showing System Information.");
        print_Specs();
    } else if (!strcmp(argv[1], "--sql-test")){
        logger("Starting SQL Test.");
        testSQLConnection();
    } else {
        printf("Argument unknown. Please use --help for more information.\n");
        snprintf(buffer, sizeof(buffer), "[ERROR] Argument unknown. Given argument: %s", argv[1]);
        logger(buffer);
    }
    
    printf("\n");
    exit_app();
    return 0;
}


