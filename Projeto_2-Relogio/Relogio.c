#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Relogio.h"

double inicio, fim, dif;

void start(){
    inicio = (double) clock () / CLOCKS_PER_SEC;
}

void finish(){
    fim = (double) clock () / CLOCKS_PER_SEC;
}

double getDelta(){
    dif = fim-inicio;
    return dif;
}
