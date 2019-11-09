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
tipo double com precis~
ao de microsegundos
Exemplo 1.123456s
*/

double getDelta();

#endif /* RELOGIO_H */
