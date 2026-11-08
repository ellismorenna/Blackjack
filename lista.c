#include <stdlib.h>
#include "lista.h"

//inicia a lista
void inicializarLista(Lista *lista) {
    lista->inicio = NULL; //lista nao possui nenhum no
    lista->tamanho = 0; //nao existe cartas armazenadas
}

//verifica se a lista esta vazia
int listaVazia(const Lista *lista) {
    return lista->inicio == NULL;
}


//insere uma carta no final
int inserirNoFinal(Lista *lista, Carta carta) {

    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->carta = carta;
    novo->proximo = NULL;

    if (listaVazia(lista)) {
        lista->inicio = novo;
    } else {

        //cria um ponteiro auxiliar chamado atual q comeca no primeiro no
        No *atual = lista->inicio;

        //percorre a lista ate o ultimo no, aquele cujo proximo é NULL
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }

        atual->proximo = novo;
    }

    lista->tamanho++;

    return 1;
}

//libera os nos alocados dinamicamento
void liberarLista(Lista *lista) {

    No *atual = lista->inicio;

    while (atual != NULL) {

        No *temporario = atual;
        atual = atual->proximo;

        free(temporario);
    }

    lista->inicio = NULL;
    lista->tamanho = 0;
}