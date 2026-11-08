#ifndef CARTA_H
#define CARTA_H

typedef struct{
    int valor;
    int naipe;
} Carta;

int obterPontuacao( Carta carta);


#endif