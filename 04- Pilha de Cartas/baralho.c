#include "baralho.h"

typedef struct node_st NO;

struct carta_st{
    char *nipe;
    int simbolo;
};

struct pilha_st{
    NO *topo;
    int tamanho; 
};

struct node_st{
    CARTA *carta;
    NO *anterior;
};

BARALHO* criar_baralho() {
    BARALHO* baralho;
    baralho = (BARALHO*)malloc(sizeof(BARALHO));

    if(baralho != NULL) {
        baralho->topo = NULL;
        baralho->tamanho = 0;
        return(baralho);
    }

    exit(0);
}

int empilhar_carta(BARALHO *baralho, CARTA *carta){
    NO *aux;
    aux = (NO*)malloc(sizeof(NO));

    if(aux != NULL) {
        aux->carta = carta;
        aux->anterior = baralho->topo;
        baralho->topo = aux;
        baralho->tamanho++;
        return TRUE;
    }

    return ERRO_PILHA;
}

void empilhar_baralho(BARALHO *baralho) {
    CARTA *carta;

    if(baralho != NULL) {
        while(baralho->tamanho != 52){
            carta = criar_carta();
            empilhar_carta(baralho, carta);
        }
    }

    return;
}

boolean baralho_vazio(const BARALHO *baralho) {
    if(baralho != NULL) {
        return baralho->tamanho == 0;
    }

    return ERRO_PILHA;
}

CARTA* desempilhar_carta(BARALHO* baralho) {
    CARTA *carta_aux = NULL;
    NO *aux = NULL;

    if((baralho != NULL) && (!baralho_vazio(baralho))) {
        aux = baralho->topo;
        carta_aux = baralho->topo->carta;
        baralho->topo = baralho->topo->anterior;
        aux->anterior = NULL;
        baralho->tamanho--;

        free(aux);
        aux = NULL;

        return(carta_aux);
    }
    
    return NULL;
}

void desempilhar_baralho(BARALHO *baralho) {
    CARTA *carta = NULL;
    int soma = 0, total = 0;

    do{
        carta = desempilhar_carta(baralho);
        soma = valor_carta(carta);
        total = total + soma;

        free(carta->nipe);
        carta->nipe = NULL;
        free(carta);
        carta = NULL;
    } while((total < 21) && (!baralho_vazio(baralho)));

    imprimir_resultado(total);

    return;
}

void imprimir_resultado(const int total) {

    if(total == 21) {
        printf("Ganhou ;)");
    } 
    else {
        printf("Perdeu :(\n");
        printf("Soma :: %d", total);
    }

    return;
}

void destruir_baralho(BARALHO **baralho) {
    NO* aux;

    if(((*baralho) != NULL) && (!baralho_vazio(*baralho))) { 

        while((*baralho)->topo != NULL) {
            aux = (*baralho)->topo;
            (*baralho)->topo = (*baralho)->topo->anterior;
            destruir_carta(&aux->carta);
            aux->anterior = NULL;
            free(aux);
            aux = NULL;
        }
    }
    free(*baralho);
    *baralho = NULL;

    return;
}