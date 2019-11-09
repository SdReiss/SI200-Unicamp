# Projeto Baralho

Segue abaixo o enunciado do projeto:

Projeto 1) Fazer em dupla. Neste projeto você vai receber um arquivo de cabeçalho baralho.h conforme abaixo:

//baralho.h

#ifndef BARALHO_H
#define BARALHO_H
#define OURO 0
#define ESPADA 1
#define COPA 2
#define PAUS 3

typedef struct Carta{
	//valor entre 1 e 13
	int valor;
	// valor entre 0 e 3
	int naipe;
}Carta;

typedef struct Baralho{
	Carta *c[100];
	int topo;
}Baralho;

//cria uma carta
Carta * newCarta(int valor, int naipe);

//cria um baralho com zero cartas
Baralho * newBaralho();

//adiciona uma carta no baralho
void addCarta(Baralho *b, Carta *c);

//remove um carta do topo do baralho
Carta * removeCarta(Baralho *b);

//embaralha. Faz uma permutação aleatória no baralho
void embaralha(Baralho *b);

//Ordena o baralho da menor carta para a maior.
void ordena(Baralho *b);

//imprime uma carta
void imprimeCarta(Carta *c);

//imprime o baralho
void imprimeBaralho(Baralho * b);

#endif /* BARALHO_H */


O arquivo baralho.h possui funções que precisam ser implementadas. Você deve implementar as funções do baralho.h. Você não pode alterar o arquivo baralho.h. Segue o arquivo main.c. Você também não pode mexer no arquivo main.c.

//main.c

#include <stdio.h>
#include <stdlib.h>
#include "baralho.h"

int main(int argc, char** argv) {
	Baralho * b = newBaralho();
	addCarta(b,newCarta(11,OURO));
	addCarta(b,newCarta(12,PAUS));
	addCarta(b,newCarta(11,COPA));
	addCarta(b,newCarta(1,OURO));
	addCarta(b,newCarta(2,PAUS));
	addCarta(b,newCarta(3,OURO));
	addCarta(b,newCarta(1,PAUS));

	imprimeBaralho(b);
	ordena(b);
	imprimeBaralho(b);
	embaralha(b);
	imprimeBaralho(b);
	
	return (EXIT_SUCCESS);
}


-------FIM DO ENUNCIADO--------

Este projeto foi feito em dupla com github.com/Lnvictor

