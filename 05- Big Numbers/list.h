#ifndef NUM_H
#define NUM_H

#include "util.h"

typedef struct list_st LISTA;

void realizar_operacoes(int qtdOp);
LISTA *exec_soma();
LISTA *preencher_lista();
LISTA *criar_lista();
void inserir_elem_fim(LISTA *lista, elem x);
void somar_listas(LISTA *aux, LISTA *lista);
void inserir_elem_ini(LISTA *lista, elem x);
void free_list(LISTA *lista);
void imprimir_lista(LISTA *lista);
int maior_num();
int is_big(LISTA *l1, LISTA *l2);
int max(LISTA *l1, LISTA *l2);

#endif