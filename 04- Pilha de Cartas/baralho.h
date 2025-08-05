#ifndef BARALHO_H
#define BARALHO_H

#define TRUE 1
#define FALSE 0
#define ERRO_PILHA (-3200)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baralho.h"
#include "carta.h"

typedef struct pilha_st BARALHO;
typedef struct carta_st CARTA;
typedef int boolean;

BARALHO* criar_baralho();
int empilhar_carta(BARALHO *baralho, CARTA *carta);
void empilhar_baralho(BARALHO *baralho) ;
boolean baralho_vazio(const BARALHO *baralho);
CARTA* desempilhar_carta(BARALHO* baralho);
void desempilhar_baralho(BARALHO *baralho);
void imprimir_resultado(int total);
void destruir_baralho(BARALHO **baralho);

#endif //BARALHO_H
