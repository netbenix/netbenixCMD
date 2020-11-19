<<<<<<< HEAD
#include <stdio.h>
#include <unistd.h>

#include "your-reality.h"

//Lyrics from "Your Reality" by Dan Salvato

//fs -> flush & sleep
void fs(int milliseconds){
    fflush(stdout);
    usleep(milliseconds*1000);
}

//p -> printf
void p(char* txt){
    printf(txt);
}

void yourReality(){
    
    printf("\e[?25l");
    p("Loading   ");
    for(int i = 0; i < 2; i++){
        //\033[XC   =>     X columns right
        //\033[XD   =>     X columns left
        printf("\033[3D   "); printf("\033[3D"); 
        fs(500); printf("."); fs(500); printf("."); fs(500); printf("."); fs(500);
        
    }
    printf("\n");
    printf("\033[0;33mEvery ");  fs(350); printf("day, ");
    fs(700);
    p("I "); fs(450); p("imagine "); fs(350); p("a "); fs(350); p("future "); fs(350); p("where "); fs(750);
    p("i "); fs(300); p("can "); fs(300); p("be "); fs(300); p("with "); fs(300); p("you.");

    p("\033[0m");
    printf("\e[?25h");
}
=======
#include <stdio.h>
#include <unistd.h>

#include "your-reality.h"

//Lyrics from "Your Reality" by Dan Salvato

//fs -> flush & sleep
void fs(int milliseconds){
    fflush(stdout);
    usleep(milliseconds*1000);
}

//p -> printf
void p(char* txt){
    printf(txt);
}

void yourReality(){
    
    printf("\e[?25l");
    p("Loading   ");
    for(int i = 0; i < 2; i++){
        //\033[XC   =>     X columns right
        //\033[XD   =>     X columns left
        printf("\033[3D   "); printf("\033[3D"); 
        fs(500); printf("."); fs(500); printf("."); fs(500); printf("."); fs(500);
        
    }
    printf("\n");
    printf("\033[0;33mEvery ");  fs(350); printf("day, ");
    fs(700);
    p("I "); fs(450); p("imagine "); fs(350); p("a "); fs(350); p("future "); fs(350); p("where "); fs(750);
    p("i "); fs(300); p("can "); fs(300); p("be "); fs(300); p("with "); fs(300); p("you.");

    p("\033[0m");
    printf("\e[?25h");
}
>>>>>>> f1cf6269f94065bfb8498dd7ef06bfbb61442b80
