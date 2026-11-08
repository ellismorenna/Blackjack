#ifndef BARALHO_H
#define BARALHO_H

#include "pilha.h"

typedef struct {
    Pilha pilha;
} Baralho;

void criarBaralho(Baralho *baralho); //inicializa pilha de 52 cartas
void embaralharBaralho(Baralho *baralho); //misturar as cartas
int comprarCarta(Baralho *baralho, Carta *carta); //retirar uma carta do topo da pilha
int baralhoVazio(const Baralho *baralho); //verificar se nao ha mais cartas

#endif