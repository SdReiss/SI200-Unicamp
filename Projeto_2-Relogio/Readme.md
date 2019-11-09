# Projeto Relógio

Segue abaixo o enunciado

Você recebeu uma função chamada Relogio.h conforme abaixo. Também recebeu a função main.c. Está faltando a função Relogio.c. Faça a implementação da função Relogio.c. Você não pode alterar as arquivos Relogio.h e main.c

//relogio.h

#ifndef RELOGIO_H

#define RELOGIO_H

/*
Inicia a contagem do tempo.
*/

void start();

/*
Finaliza a contagem do tempo.
*/

void finish();

/**obtem o tempo transorrido entre o start e o finish em segundos do
tipo double com precisão de microsegundos
Exemplo 1.123456s
*/

double getDelta();

#endif 

/* RELOGIO_H */

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
