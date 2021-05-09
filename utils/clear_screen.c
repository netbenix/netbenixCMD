#include <stdio.h>
#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__)
#include <sys/ioctl.h>
#include <unistd.h>
#endif

#include "clear_screen.h"


void clearScreen(){
    #if defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    for(int i = 0; i < rows; i++){
        printf("\n");
    }
    #elif defined(__linux__)
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    for(int i = 0; i < w.ws_row; i++){
        printf("\n");
    }
    #endif
}