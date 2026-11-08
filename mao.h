#ifndef MAO_H
#define MAO_H

//TAD mao utiliza o TAD lista para armazenar dinamicamente as cartas de cada participante
#include "lista.h"

typedef struct {
    Lista cartas;
} Mao;

void inicializarMao(Mao *mao);
int adicionarCarta(Mao *mao, Carta carta);
int calcularPontuacao(const Mao *mao);
void limparMao(Mao *mao);

#endif