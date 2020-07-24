#include <stdio.h>
#include "logo.h"
char logo_row1[59] = "            _   _                _       ____ __  __ ____  ";
char logo_row2[59] = " _ __   ___| |_| |__   ___ _ __ (_)_  __/ ___|  \\/  |  _ \\ ";
char logo_row3[59] = "| '_ \\ / _ \\ __| '_ \\ / _ \\ '_ \\| \\ \\/ / |   | |\\/| | | | |";
char logo_row4[59] = "| | | |  __/ |_| |_) |  __/ | | | |>  <| |___| |  | | |_| |";
char logo_row5[59] = "|_| |_|\\___|\\__|_.__/ \\___|_| |_|_/_/\\_\\\\____|_|  |_|____/ ";

//Prints the logo
void showLogo(){
    printf("\033[0;34m%s\033[0m\n", logo_row1);
    printf("\033[0;34m%s\033[0m\n", logo_row2);
    printf("\033[0;34m%s\033[0m\n", logo_row3);
    printf("\033[0;34m%s\033[0m\n", logo_row4);
    printf("\033[0;34m%s\033[0m\n\n", logo_row5);
}