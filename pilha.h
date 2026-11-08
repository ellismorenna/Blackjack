#ifndef PILHA_H
#define PILHA_H

#include "carta.h"

#define TAMANHO_PILHA 52

typedef struct {
    Carta cartas[TAMANHO_PILHA];
    int topo;
} Pilha;

void inicializarPilha(Pilha *pilha);
int empilhar(Pilha *pilha, Carta carta);
int desempilhar(Pilha *pilha, Carta *carta);
int pilhaVazia(const Pilha *pilha);
int pilhaCheia(const Pilha *pilha);

#endif