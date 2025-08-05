#ifndef CARTAS_H
#define CARTAS_H

#define TRUE 1
#define FALSE 0
#define ERRO (-1200)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baralho.h"

typedef struct carta_st CARTA;
typedef int boolean;

CARTA* criar_carta();
char* ler_nipe();
int valor_carta(CARTA* carta);
void destruir_carta(CARTA** carta);

#endif //CARTAS_H