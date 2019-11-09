//Restaurante.h
//Breno Souza dos Reis              github.com/SdReiss
//Victor Henrique Barbosa Pereira   github.com/Lnvictor

#ifndef RESTAURANTE_H
#define RESTAURANTE_H

typedef struct Pedido{
    int id;
    char* texto;
    int mesa;
    long int timesstamp;
}Pedido;

typedef struct Pedidos{
    Pedido* Vet[1000];
    int top;
}Pedidos;

Pedido* newPedido(int mesa, char* texto, int Id, long int timesstamp);

Pedido* lePedido();

void addPedido(Pedido* P);

Pedidos* listaPedidos();

Pedido* removeMaisAntigo();

#endif /* RESTAURANTE_H */
