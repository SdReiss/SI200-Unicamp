#include <stdio.h>
#include <stdlib.h>
#include "baralho.h"
#include <time.h>
#include <string.h>

int cmpv(const void * x, const void * y){
    Carta* pri = (Carta*)x;
    Carta* seg = (Carta*)y;

    return (pri->valor - seg->valor)*(-1);
}

int cmpn(const void * x, const void * y){
    Carta* pri = (Carta*)x;
    Carta* seg = (Carta*)y;

    if(pri->valor==seg->valor)
        return (pri->naipe-seg->naipe)*(-1);
    else
        return 0;
}

int cmpx(const void * x, const void * y){
    Carta** xa = (Carta**) x;
    Carta** ya = (Carta**) y;

    if((**xa).valor > (**ya).valor){
        return 1;
    }

    if ((**xa).valor < (**ya).valor){
        return -1;
    }

    else{
        return 0;
    }

}

//cria uma carta
Carta* newCarta(int valor, int naipe){
    Carta* caux = (Carta*)malloc(sizeof(Carta));
    caux->valor = valor;
    caux->naipe = naipe;

    return caux;
}

//cria um baralho com zero cartas
Baralho* newBaralho(){
    Baralho* baux = (Baralho*)malloc(sizeof(Baralho));
    baux->topo = -1;

    return baux;
}

//adiciona uma carta no baralho
void addCarta(Baralho *b, Carta *c){
    b->c[b->topo+1] = c;

    b->topo++;
}

//remove um carta do topo do baralho
Carta* removeCarta(Baralho *b){
    free(b->c[b->topo]);
    b->topo--;
}

//embaralha. Faz uma permutação aleatória no baralho
void embaralha(Baralho *b){
    printf("\nEmbaralhando o baralho...\n");
    srand(time(NULL));
    for(int i = 0; i<b->topo; i++){
        int r = rand()%b->topo+1;
        Carta* eaux = b->c[i];
        b->c[i] = b->c[r];
        b->c[r] = eaux;
    }

}

//Ordena o baralho da menor carta para a maior.
void ordena(Baralho *b){
    printf("\nOrdenando o baralho...\n");
    qsort(b->c,b->topo+1,sizeof(Carta*),cmpx);
    //qsort(b->c,b->topo+1,sizeof(Carta),cmpn);
}

//imprime uma carta
void imprimeCarta(Carta *c){
    char naipe[10];
    switch (c->naipe) {
        case 0:
            strcpy(naipe,"OURO");
            break;
        case 1:
            strcpy(naipe,"ESPADA");
            break;
        case 2:
            strcpy(naipe,"COPA");
            break;
        case 3:
            strcpy(naipe,"PAUS");
            break;

    }
    printf("Valor: %d\nNaipe: %s\n",c->valor,naipe);
}

//imprime o baralho
void imprimeBaralho(Baralho * b){
    for(int i=0;i<b->topo+1;i++){
        printf("[Carta %d]\n",i+1);
        imprimeCarta(b->c[i]);
        printf("\n");
    }
}
