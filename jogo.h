#ifndef JOGO_H
#define JOGO_H

#include "baralho.h"
#include "mao.h"

#define JOGO_EM_ANDAMENTO 0
#define JOGADOR_VENCEU 1
#define COMPUTADOR_VENCEU 2
#define EMPATE 3

typedef struct {
    Baralho baralho;
    Mao maoJogador;
    Mao maoComputador;
    int partidaEncerrada;
    int jogadorParou;
    int resultado;
} Jogo;

// Inicializa uma nova partida
void inicializarJogo(Jogo *jogo);

// Distribui duas cartas para cada participante
void distribuirCartas(Jogo *jogo);

// Compra uma carta para o jogador
int comprarCartaJogador(Jogo *jogo);

// Executa a jogada automática do computador
void vezComputador(Jogo *jogo);

// Determina o vencedor
void verificarResultado(Jogo *jogo);

// Libera a memória utilizada
void finalizarJogo(Jogo *jogo);

#endif