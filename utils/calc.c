#include <stdio.h>

#include "calc.h"
#include "../etc/math_ext.h"
#include "logger.h"

void startCalc(){
    logger("Started calculator.");
    char op;
    printf("Calculator - Version 0.1\n\n");
    
    do{
        printf("\nOperation (h for help): ");
        scanf("%c", &op);
        chooseOperation(op);
    }while(op != 'q');
    
    
}

void chooseOperation(char op){
    logger("Operation choosen: " + op);

    switch(op){
        case '1': { OP_1(); break;};
        case 'h': { listOperations(); break;};
        case 'q': {/*do nothing bcause auto break*/ break;}
        default: { /*do none*/ break;};
    }
}

void listOperations(){
    printf("Operations List: \n\n");
    printf("1 - Addition\n");
    printf("2 - Subtraction\n");
    printf("3 - Multiply\n");
    printf("4 - Divide\n");
}

void OP_1(){
    double x, y;
    printf("1. Number: \n");
    scanf("%lf", &x);
    printf("2. Number: \n");
    scanf("%lf", &y);
    printf("\n Result: %lf\n", Add(x,y));
}

int getNumber(){
    int no;
    scanf("%d", &no);

    return no;
}