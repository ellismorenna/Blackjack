#include "pilha.h"

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int pilhaVazia(const Pilha *pilha) {
    return pilha->topo == -1;
}

int pilhaCheia(const Pilha *pilha) {
    return pilha->topo == TAMANHO_PILHA - 1;
}

int empilhar(Pilha *pilha, Carta carta) {

    if (pilhaCheia(pilha)) {
        return 0;
    }

    pilha->topo++;
    pilha->cartas[pilha->topo] = carta;

    return 1;
}

int desempilhar(Pilha *pilha, Carta *carta) {

    if (pilhaVazia(pilha)) {
        return 0;
    }

    *carta = pilha->cartas[pilha->topo];
    pilha->topo--;

    return 1;
}