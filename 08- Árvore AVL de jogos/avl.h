#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "jogos.h"

typedef struct avl_st AVL;

AVL* criar_avl();
NO* rotacao_direita(NO* raiz);
NO* rotacao_esquerda(NO* raiz);
NO* balancear_avl(NO* raiz);
NO* avl_inserir_no(NO* raiz, JOGO* jogo);
AVL* avl_inserir(AVL* avl, JOGO* jogo);
AVL* preencher_avl();
void pre_ordem(NO* no);
void em_ordem(NO* no);
void pos_ordem(NO* no);
JOGO* busca_avl_no(NO* raiz, int ano_rem);
JOGO* busca_avl(AVL* avl, int ano_rem);
void troca_no_removido(NO* troca, NO* raiz, NO* ant);
boolean no_deletar(NO** raiz, int ano);
AVL* avl_deletar(AVL* avl, int ano_rem);
void apagar_arvore(NO** raiz);
void destruir_avl(AVL** avl);
NO *rotacao_hibrida1(NO *node);
NO *rotacao_hibrida2(NO *node);
#endif