#include <stdio.h>
#include "logo.h"
char logo_row1[59] = "            _   _                _       ____ __  __ ____  ";
char logo_row2[59] = " _ __   ___| |_| |__   ___ _ __ (_)_  __/ ___|  \\/  |  _ \\ ";
char logo_row3[59] = "| '_ \\ / _ \\ __| '_ \\ / _ \\ '_ \\| \\ \\/ / |   | |\\/| | | | |";
char logo_row4[59] = "| | | |  __/ |_| |_) |  __/ | | | |>  <| |___| |  | | |_| |";
char logo_row5[59] = "|_| |_|\\___|\\__|_.__/ \\___|_| |_|_/_/\\_\\\\____|_|  |_|____/ ";

void showLogo(){
    printf("%s\n", logo_row1);
    printf("%s\n", logo_row2);
    printf("%s\n", logo_row3);
    printf("%s\n", logo_row4);
    printf("%s\n\n", logo_row5);
}