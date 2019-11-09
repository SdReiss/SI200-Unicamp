//main.c
#include <stdio.h>
#include <stdlib.h>
#include "Relogio.h"

int main(int argc, char** argv) {
    start();
    long int aux = 0;

    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            for(int k=0;k<1000;k++){
                aux++;
            }
        }
    }

    finish();

    printf("Tempo = %lfs",getDelta());

    return (EXIT_SUCCESS);
}
