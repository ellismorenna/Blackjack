#include "carta.h"

int obterPontuacao (Carta carta) {
    
    if (carta.valor == 1) {
        return 1;
    }

    if (carta.valor >=11 && carta.valor<=13){
        return 10;
    }

    return carta.valor;

}