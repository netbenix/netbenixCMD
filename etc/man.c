#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "man.h"

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

//Main function to start man is at the bottom

//MAN ENTRIES

//LS
void manEntry_ls(){
    printf("\033[0;33m##################\033[0m\n");
    printf("\033[0;33m# Manual of \033[0;36m'ls' \033[0;33m#\033[0m\n");
    printf("\033[0;33m##################\033[0m\n\n");
    printf("\033[0;33mNAME\033[0m\n");
    printf("\t\033[0;36mls - list directory contents\033[0m\n\n");
    printf("\033[0;33mUSAGE\033[0m\n");
    printf("\t\033[0;36mls \033[0;35m[DIRECTORY]\033[0m\n\n");
    printf("\033[0;33mDESCRIPTION\033[0m\n");
    printf("\t\033[0;36mList files and directorys in the given directory. Sorts entries alphabetically.\033[0m\n\n");
}

//CD
void manEntry_cd(){
    printf("\033[0;33m##################\033[0m\n");
    printf("\033[0;33m# Manual of \033[0;36m'cd' \033[0;33m#\033[0m\n");
    printf("\033[0;33m##################\033[0m\n");
    printf("\033[0;33mNAME\033[0m\n");
    printf("\t\033[0;36mcd - change directory\033[0m\n\n");
    printf("\033[0;33mUSAGE\033[0m\n");
    printf("\t\033[0;36mcd \033[0;35m[DIRECTORY]\033[0m\n\n");
    printf("\033[0;33mDESCRIPTION\033[0m\n");
    printf("\t\033[0;36mChanged the currently selected directory.\033[0m\n\n");
}

//MAN
void manEntry_man(){
    printf("\033[0;33m###################\033[0m\n");
    printf("\033[0;33m# Manual of \033[0;36m'man' \033[0;33m#\033[0m\n");
    printf("\033[0;33m###################\033[0m\n\n");
    printf("\033[0;33mNAME\033[0m\n");
    printf("\t\033[0;36mman - manual\033[0m\n\n");
    printf("\033[0;33mUSAGE\033[0m\n");
    printf("\t\033[0;36mman \033[0;35m[COMMAND]\033[0m\n\n");
    printf("\033[0;33mDESCRIPTION\033[0m\n");
    printf("\t\033[0;36mShows the manual of given command.\033[0m\n\n");
}



//MAIN FUNCTION
void showManEntry(char *arg[]){
    if(!strcmp(arg[1], "man")){
        manEntry_man();
    } else if(!strcmp(arg[1], "ls")){
        manEntry_ls();
    } else if(!strcmp(arg[1], "cd")){
        manEntry_cd();
    } else {
        printf("Entry not found.\n");
    }
}