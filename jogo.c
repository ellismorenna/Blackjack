#include "jogo.h"
#include <stdlib.h>
#include <time.h>

// Inicializa uma nova partida
void inicializarJogo(Jogo *jogo) {

    srand((unsigned int) time(NULL));

    criarBaralho(&jogo->baralho);
    embaralharBaralho(&jogo->baralho);

    inicializarMao(&jogo->maoJogador);
    inicializarMao(&jogo->maoComputador);

    jogo->partidaEncerrada = 0;
    jogo->jogadorParou = 0;
    jogo->resultado = JOGO_EM_ANDAMENTO;
}

// Distribui duas cartas para cada participante
void distribuirCartas(Jogo *jogo) {

    Carta carta;

    for (int i = 0; i < 2; i++) {

        if (comprarCarta(&jogo->baralho, &carta)) {

            if (!adicionarCarta(&jogo->maoJogador, carta)) {
                return;
            }
        }

        if (comprarCarta(&jogo->baralho, &carta)) {

            if (!adicionarCarta(&jogo->maoComputador, carta)) {
                return;
            }
        }
    }
}

// Compra uma carta para o jogador
int comprarCartaJogador(Jogo *jogo) {

    if (jogo->partidaEncerrada || jogo->jogadorParou) {
        return 0;
    }

    Carta carta;

    if (!comprarCarta(&jogo->baralho, &carta)) {
        return 0;
    }

    if (!adicionarCarta(&jogo->maoJogador, carta)) {
        return 0;
    }

    if (calcularPontuacao(&jogo->maoJogador) > 21) {
        jogo->partidaEncerrada = 1;
        jogo->resultado = COMPUTADOR_VENCEU;
    }

    return 1;
}

// Executa a jogada automática do computador
void vezComputador(Jogo *jogo) {

    Carta carta;

    while (calcularPontuacao(&jogo->maoComputador) < 17) {

        if (!comprarCarta(&jogo->baralho, &carta)) {
            break;
        }

        if (!adicionarCarta(&jogo->maoComputador, carta)) {
            break;
        }
    }

    verificarResultado(jogo);
}

// Determina o vencedor
void verificarResultado(Jogo *jogo) {

    int pontosJogador = calcularPontuacao(&jogo->maoJogador);
    int pontosComputador = calcularPontuacao(&jogo->maoComputador);

    if (pontosJogador > 21) {
        jogo->resultado = COMPUTADOR_VENCEU;
    }
    else if (pontosComputador > 21) {
        jogo->resultado = JOGADOR_VENCEU;
    }
    else if (pontosJogador > pontosComputador) {
        jogo->resultado = JOGADOR_VENCEU;
    }
    else if (pontosComputador > pontosJogador) {
        jogo->resultado = COMPUTADOR_VENCEU;
    }
    else {
        jogo->resultado = EMPATE;
    }

    jogo->partidaEncerrada = 1;
}

// Libera a memória utilizada
void finalizarJogo(Jogo *jogo) {

    limparMao(&jogo->maoJogador);
    limparMao(&jogo->maoComputador);

    jogo->partidaEncerrada = 1;
}