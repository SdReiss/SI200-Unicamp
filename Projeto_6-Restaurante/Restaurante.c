//Restaurante.c
//Breno Souza dos Reis              github.com/SdReiss
//Victor Henrique Barbosa Pereira   github.com/Lnvictor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Restaurante.h"

Pedido* newPedido(int mesa, char* texto, int Id, long int timesstamp){
    Pedido* P = (Pedido*) malloc (sizeof(Pedido));
    P->texto = (char*) malloc (strlen(texto) * sizeof(char));

    P->id = Id;
    P->mesa = mesa;
    strcpy(P->texto, texto);
    P->timesstamp = timesstamp;

    return P;
}

Pedido* lePedido(){
    int mesa;
    char texto[1000];
    int Id;
    long int timesstamp = (long int) time(NULL);
    Pedido* P;

    printf("Descreva o pedido:\n");
    fgets(texto, 1000, stdin);

    printf("Escolha a mesa\n");
    scanf("%d", &mesa);
    getchar();

    FILE*  Arquivo;
    Arquivo = fopen("MAX_ID.txt", "r");

    if(Arquivo == NULL){
        Arquivo = fopen("MAX_ID.txt", "w");
        fprintf(Arquivo, "1\n");
        Id = 1;
        fclose(Arquivo);
    }

    else{
        fscanf(Arquivo, "%d", &Id);
        Id++;
        fclose(Arquivo);
        Arquivo = fopen("MAX_ID.txt", "w");
        fprintf(Arquivo, "%d\n", Id);
        fclose(Arquivo);
    }
    P = newPedido(mesa, texto, Id, timesstamp);
    return P;
}

void addPedido(Pedido* P){
    FILE* Arquivo;
    Arquivo = fopen("Pedidos.txt","a+");
    fprintf(Arquivo, "%d", P->id);
    fprintf(Arquivo, "%s", P->texto);
    fprintf(Arquivo, "%d\n", P->mesa);
    fprintf(Arquivo, "%ld\n", P->timesstamp);

    fclose(Arquivo);
}

Pedidos* listaPedidos(){
    Pedidos* Ps = (Pedidos*) malloc (sizeof(Pedidos));
    Ps->top = 0;
    int mesa, Id, aux, i;
    char texto[1000];
    long int timesstamp;
    FILE* Arquivo;
    Arquivo = fopen("MAX_ID.txt", "r");
    fscanf(Arquivo, "%d", &aux);
    fclose(Arquivo);

    Arquivo = fopen("Pedidos.txt", "r");
    fscanf(Arquivo, "%d", &Id);
    fclose(Arquivo);

    aux-=Id-1;

    Arquivo = fopen("Pedidos.txt", "r");

    for(i = 0; i < aux; i++){
        fscanf(Arquivo, "%d", &Id);
        fgets(texto, 1000, Arquivo);
        fscanf(Arquivo, "%d", &mesa);
        fscanf(Arquivo, "%ld", &timesstamp);
        Ps->Vet[i] = newPedido(mesa, texto, Id, timesstamp);
    }

    Ps->top = i;
    fclose(Arquivo);

    return Ps;
}

Pedido* removeMaisAntigo(){
    Pedidos* P = listaPedidos();
    FILE* Arquivo;

    if (P->top > 1){
    Arquivo = fopen("Pedidos.txt", "w");
    fprintf(Arquivo, "%d", P->Vet[1]->id);
    fprintf(Arquivo, "%s", P->Vet[1]->texto);
    fprintf(Arquivo, "%d\n", P->Vet[1]->mesa);
    fprintf(Arquivo, "%ld\n", P->Vet[1]->timesstamp);

    fclose(Arquivo);

        for(int i = 2; i < P->top; i++){
        addPedido(P->Vet[i]);
        }
    }
    else{
        Arquivo = fopen("Pedidos.txt", "w");
        fclose(Arquivo);
    }

    return P->Vet[0];
}
