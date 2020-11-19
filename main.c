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
#include "etc/man.h"
#include "etc/math.h"
#include "etc/your-reality.h"
#include "utils/logger.h"
#include "utils/sys_info.h"
#include "utils/update_check.h"


#define VERSION "0.2.4"

bool VER_CHECK_ON_START = true;
bool DEV_MODE = false;
bool FUN_CONTENT = false;

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


//Handles the commands
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

    //Start to compare the command
    if(!strcmp(arg[0], "help")){ 
        printf("\033[1;34mcd \033[0;35m[dir]\033[0m      :   change directory\n");
        printf("\033[1;34mls \033[0;35m[dir]\033[0m      :   show contents of directory\n");
        printf("\033[1;34mhelp\033[0m          :   this help list\n");
        printf("\033[1;34mman \033[0;35m[cmd]\033[0m     :   manual for the commands\n");
        printf("\033[1;34mversion\033[0m       :   shows the version\n");
        printf("\033[1;34mexit\033[0m          :   exit the program\n");
        return 0;
    } else if(!strcmp(arg[0], "version")){ 

        printf("netbenixCMD (Version: \033[1;34m%s\033[0m)\n", VERSION);
        printf("Author: \033[1;34m%s\033[0m\n", "netbenix");
        printf("Github: \033[1;34mhttps://github.com/netbenix/netbenixCMD\033[0m\n");
        logger("Showing program version.");
        return 0;
    } else if(!strcmp(arg[0], "exit")){
        return 1;
    } else if(!strcmp(arg[0], "ls")){
        showDirectory(arg);
        return 0;
    } else if(!strcmp(arg[0], "cd")){
        changeCurrentWorkDir(arg);
        return 0;
    } else if(!strcmp(arg[0], "man")){
        showManEntry(arg);
        return 0;
    } else if(!strcmp(arg[0], "rainbow") && FUN_CONTENT){
        while(1){              
            printf("\033[0;31m#####");
            printf("\033[0;32m#####");
            printf("\033[0;33m#####");
            printf("\033[0;34m#####");
            printf("\033[0;35m#####");
        }
    } else if(!strcmp(arg[0], "your-reality") && FUN_CONTENT){
        yourReality();
    } else {
        printf("Unknown command. Please use 'help' for more information.\n");
        logger("User entered unknown command.");
        return 0;
    }
}

//Action starts here
int main(int argc, char *argv[]){
    char buffer[1024];
    extern char loggerDirPath[PATH_MAX];
    realpath("." , loggerDirPath);
    logger("================================================");
    snprintf(buffer, sizeof(buffer), "Starting netbenixCMD (Version: %s)", VERSION);
    logger(buffer);
    log_Specs(); //Log system specs
    showLogo(); //Show the logo
    logger("Logo Displayed.");
    if(argc > 2){
        printf("Too many arguments. Please use --help for more information.\n");
        snprintf(buffer, sizeof(buffer), "[ERROR] Too many arguments. Argument count: %i", argc-1);
        logger(buffer);
    }

    //Check the startup args
    if(argc == 2){
    if(!strcmp(argv[1], "--help")){
        logger("Showing Help.");
        outputHelp();
        exit(0);
    } else if (!strcmp(argv[1], "--gtk-test")){
        logger("Stating GTK Test.");
        createGTKTestWindow();
        exit(0);
    } else if (!strcmp(argv[1], "--sys-info")){
        logger("Showing System Information.");
        print_Specs();
        exit(0);
    } else if (!strcmp(argv[1], "--sql-test")){
        logger("Starting SQL Test.");
        testSQLConnection();
        exit(0);
    } else if (!strcmp(argv[1], "--no-version-check")){
        VER_CHECK_ON_START = false;
        logger("[INFO] Argument 'no-version-check' used.");
    } else if (!strcmp(argv[1], "--dev-mode")){
        VER_CHECK_ON_START = false;
        DEV_MODE = true;
        logger("[INFO] Starting in developer mode.");
    } else if (!strcmp(argv[1], "--time-to-have-fun")){
        FUN_CONTENT = true;
        logger("[WARNING] It's time... TO PARTYY.");
    } else {
        printf("Argument unknown. Please use --help for more information.\n");
        snprintf(buffer, sizeof(buffer), "[ERROR] Argument unknown. Given argument: %s", argv[1]);
        logger(buffer);
        exit(0);
    }
    }

    if(VER_CHECK_ON_START){checkForUpdate(VERSION);} //Check for newer version of client

    //If no startup arg is given, start command handler
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
    printf("\n");
    logger("Exiting.");
    return 0;
}


