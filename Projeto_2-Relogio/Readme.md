# Projeto RElógio

Segue abaixo o enunciado

Exerc´ıcios 10) Vocˆe recebeu uma fun¸c˜ao chamada Relogio.h conforme abaixo. Tamb´em recebeu a
fun¸c˜ao main.c. Est´a faltando a fun¸c˜ao Relogio.c. Fa¸ca a implementa¸c˜ao da fun¸c˜ao Relogio.c. Vocˆe n˜ao
pode alterar as arquivos Relogio.h e main.c
//relogio.h
#ifndef RELOGIO_H
#define RELOGIO_H
15
/*
Inicia a contagem do tempo.
*/
void start();
/*
Finaliza a contagem do tempo.
*/
void finish();
/**obtem o tempo transorrido entre o start e o finish em segundos do
tipo double com precis~ao de microsegundos
Exemplo 1.123456s
*/
double getDelta();
#endif /* RELOGIO_H */
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

