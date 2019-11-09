//Main.c
//Breno Souza dos Reis              github.com/SdReiss
//Victor Henrique Barbosa Pereira   github.com/Lnvictor

#include "Restaurante.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(){
    int menu;
    Pedidos* Ps;
    Pedido* P;

    while(1){
        printf("============[Menu]============\n");
        printf("1. Inserir pedido\n");
        printf("2. Listar pedidos\n");
        printf("3. Remover pedido mais antigo\n");
        printf("4. Sair\n");
        printf("==============================\n");

        scanf("%d",&menu);
        printf("==============================\n");

        switch (menu) {
            case 1:
                getchar();
                addPedido(lePedido());
                break;
            case 2:
                Ps = listaPedidos();
                for(int i = 0; i < Ps->top; i++){
                    printf("Id: %d\n", Ps->Vet[i]->id);
                    printf("Pedido: %s",Ps->Vet[i]->texto);
                    printf("Mesa: %d\n",Ps->Vet[i]->mesa);
                    printf("\n");
                }
                break;
            case 3:
                P = removeMaisAntigo();
                if (P->id != 0){
                    printf("\nPedido Removido\n");
                    printf("\tId: %d\n", P->id);
                    printf("\tPedido: %s",P->texto);
                    printf("\tMesa: %d\n",P->mesa);
                    printf("\tTempo Transcorrido: %ld minutos\n",(time(NULL) - P->timesstamp)/60);
                }

                else{
                    printf("Não há pedidos registrados\n");
                }
                break;
            case 4:
                return 0;
            default:
                printf("Opcao Invalida\n");
                break;
        }
    }
}
