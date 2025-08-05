#ifndef JOGO_H
#define JOGO_H

#define TRUE 1
#define FALSE 0
#define ERRO (-3200)

#include "catalogo.h"

typedef int boolean;
typedef struct jogo_st JOGO;

void ler_jogos(CATALOGO *catalogo);
boolean verifica_F(char *aux);
char* ler_nom_prod();
boolean comparar_strings(const char *string1, const char *string2);
JOGO* atribuir_valores(char *nome);
JOGO* criar_jogo (char *nome, char *produtora, int ano);
void deletar_jogos(CATALOGO *catalogo);

#endif