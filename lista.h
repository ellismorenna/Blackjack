#ifndef LISTA_H
#define LISTA_H

#include "carta.h"

typedef struct No {
    Carta carta;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} Lista;

void inicializarLista(Lista *lista);
int inserirNoFinal(Lista *lista, Carta carta);
int listaVazia(const Lista *lista);
void liberarLista(Lista *lista);

#endif