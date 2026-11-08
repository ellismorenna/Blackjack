#include <stdlib.h>
#include "baralho.h"

//cria baralho e suas 52 cartas
void criarBaralho(Baralho *baralho){

    inicializarPilha(&baralho->pilha);

    for(int naipe =0; naipe<4; naipe++){

        for(int valor = 0; valor <= 13; valor++){

            Carta carta = {valor, naipe};

            empilhar(&baralho->pilha, carta);
        }
    }

}

//embaralha as cartas utilizando Fisher-Yates
void embaralharBaralho(Baralho *baralho) {

    for (int i = baralho->pilha.topo; i > 0; i--) {

        //sorteia uma posicao entre 0 e i, incluindo ambas
        int j = rand() % (i + 1);

        //variavel temporaria guarda uma das cartas durante a troca
        Carta temporaria = baralho->pilha.cartas[i];

        baralho->pilha.cartas[i] = baralho->pilha.cartas[j];

        baralho->pilha.cartas[j] = temporaria;
    }
}

//remove a carta do topo da pilha e copia seu conteudo para carta
int comprarCarta(Baralho *baralho, Carta *carta) {

    return desempilhar(&baralho->pilha, carta);
}

//verifica se o baralho esta vazio
int baralhoVazio(const Baralho *baralho) {

    return pilhaVazia(&baralho->pilha);
}