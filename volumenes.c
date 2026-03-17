#include "volumenes.h"
#include <math.h>

double VolEsfera(double r){
    return (4.0/3.0) * 3.1416 * r * r * r;
}

double VolCubo(double l){
    return l * l * l;
}