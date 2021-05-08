#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../utils/logger.h"

#include "math_ext.h"

double Add(double x, double y){
    return(x + y);
}

double Sub(double x, double y){
    return(x - y);
}

double Mul(double x, double y){
    return(x * y);
}
double Div(double x, double y){
    if (y == 0.0)
        return 0.0;
    else 
        return(x / y);
}

double CubeVolume(double a){
    return pow(a, 3);
}

double SphereVolume(double r){
    return (4/3*M_PI*pow(r, 3));
}