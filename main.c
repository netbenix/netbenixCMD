#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <gdk/gdk.h>
#include <gdk/gdkconfig.h>
#include <gtk/gtk.h>
#include <unistd.h>
#include <linux/limits.h>

#include "commands/help.h"
#include "commands/show_dir.h"
#include "commands/change_dir.h"
#include "utils/gtk_test.h"
#include "utils/sql_test.h"
#include "etc/logo.h"
#include "utils/logger.h"
#include "utils/sys_info.h"


#define VERSION "0.2.0"
#define AUTHOR "netbenix"

void exit_app(){
    logger("Exiting.");
    exit(0);
}

// Color Codes:
// Reset:       \033[0m
// Red:         \033[0;31m
// Green:       \033[0;32m
// Yellow:      \033[0;33m
// Blue:        \033[0;34m
// Magenta:     \033[0;35m
// Cyan:        \033[0;36m
// BoldRed:     \033[1;31m
// BoldGreen:   \033[1;32m
// BoldYellow:  \033[1;33m
// BoldBlue:    \033[1;34m
// BoldMagenta: \033[1;35m
// BoldCyan:    \033[1;36m


int commandHandler(char *cmd){

    char *token = strtok(cmd, " ");
    int argc = 1;
    char *arg[10];
    int i = 0;
    while( token != NULL ){
        arg[i] = token;
        token = strtok(NULL, " ");
        if(token != NULL){
            i++;
            argc++;
        }
    }
    char *p = arg[i];
    p[strlen(p)-1] = 0;
    arg[i] = p;

    if(!strcmp(arg[0], "list")){ 
        printf("\033[1;34mcd\033[0m      :   change directory\n");
        printf("\033[1;34mdir\033[0m     :   show contents of directory\n");
        printf("\033[1;34mlist\033[0m    :   this list\n");
        printf("\033[1;34mversion\033[0m :   shows the version\n");
        printf("\033[1;34mexit\033[0m    :   exit the program\n");
        return 0;
    } else if(!strcmp(arg[0], "version")){ 
        printf("netbenixCMD (Version: \033[1;34m%s\033[0m)\n", VERSION);
        printf("Author: \033[1;34m%s\033[0m\n", AUTHOR);
        logger("Showing program version.");
        return 0;
    } else if(!strcmp(arg[0], "exit")){
        return 1;
    } else if(!strcmp(arg[0], "dir")){
        showDirectory(arg);
        return 0;
    } else if(!strcmp(arg[0], "cd")){
        changeCurrentWorkDir(arg);
        return 0;
    } else {
        printf("Unknown command. Please use --help for more information.\n");
        logger("User entered unknown command.");
        return 0;
    }
}


int main(int argc, char *argv[]){
    char buffer[1024];
    extern char loggerDirPath[PATH_MAX];
    realpath("." , loggerDirPath);
    logger("================================================");
    snprintf(buffer, sizeof(buffer), "Starting netbenixCMD (Version: %s)", VERSION);
    logger(buffer);
    log_Specs();
    showLogo(); //Show the Logo
    logger("Logo Displayed.");

    if(argc > 2){
        printf("Too many arguments. Please use --help for more information.\n");
        snprintf(buffer, sizeof(buffer), "[ERROR] Too many arguments. Argument count: %i", argc-1);
        logger(buffer);
    }

    if(argc == 2){
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
    }

    if(argc == 1){
        int exit = 0;
        char cmd[128];
        logger("Starting Command Handler.");
        while (!exit){
            char cwp[255];
            printf("\033[0;32m%s> \033[0m", getcwd(cwp, 255));
            fgets(cmd, 128, stdin);
            exit = commandHandler(cmd);
        }
        logger("Exiting Command Handler.");
    }
    
    printf("\n");
    exit_app();
    return 0;
}


