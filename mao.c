#include <stddef.h>
#include "mao.h"

//inicializa a mao
void inicializarMao(Mao *mao) {
    inicializarLista(&mao->cartas);
}

//encaminha a carta para a lista encadeada da mao
int adicionarCarta(Mao *mao, Carta carta) {
    return inserirNoFinal(&mao->cartas, carta);
}

// calcula a pontuacao e a variacao de valores do As 
// O valor é escolhido com o objetivo de chegar o mais perto possível de 21 sem ultrapassar.
int calcularPontuacao(const Mao *mao) {

    int pontuacao = 0;
    int quantidadeAses = 0;

    No *atual = mao->cartas.inicio;

    while (atual != NULL) {

        int valor = obterPontuacao(atual->carta);

        pontuacao += valor;

        if (atual->carta.valor == 1) {
            quantidadeAses++;
        }

        atual = atual->proximo;
    }

    while (quantidadeAses > 0 && pontuacao + 10 <= 21) {
        pontuacao += 10;
        quantidadeAses--;
    }

    return pontuacao;
}

//reutiliza o TAD lista para limpar a mao
void limparMao(Mao *mao) {
    liberarLista(&mao->cartas);
}