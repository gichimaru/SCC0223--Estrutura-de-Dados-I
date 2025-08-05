#ifndef CATALOGO_H
#define CATALOGO_H

#include "jogo.h"

typedef int boolean;
typedef struct jogo_st JOGO;
typedef struct catalogo_st CATALOGO;

CATALOGO *criar_catalogo();
char* nome_jogo(JOGO *jogo);
boolean verifica_A(char *aux);
int jogo_ano(JOGO *jogo);
void pesquisar_ano( CATALOGO *catalogo);
boolean verifica_E(char *aux);
char* prod_jogo(JOGO *jogo);
boolean comparar_produtoras(JOGO *jogo,char *produtora);
void procurar_produtora(CATALOGO *catalogo, char *produtora);
void pesquisar_prod(CATALOGO *catalogo);
void pesquisar(CATALOGO *catalogo);
void apagar_catalogo(CATALOGO *catalogo);

#endif