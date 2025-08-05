#ifndef JOGOS_H
#define JOGOS_H

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

typedef struct jogos_st JOGO;

JOGO* criar_jogo();
void preencher_jogo(char* jog, JOGO* jogo);
void imprimir_jogo(JOGO* jogo);
void apagar_jogo(JOGO** jogo);
int ano_jogo(JOGO* jogo);

#endif