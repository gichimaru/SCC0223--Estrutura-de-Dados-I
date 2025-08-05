#include "baralho.h"

int main() {
    BARALHO *baralho;
    baralho = criar_baralho();
    
    empilhar_baralho(baralho);
    desempilhar_baralho(baralho);
    destruir_baralho(&baralho);

    return 0;
}