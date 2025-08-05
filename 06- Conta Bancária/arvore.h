#ifndef ARVORE_H
#define ARVORE_H

#include "cadastro.h"

typedef struct node_st NO;
typedef struct arvore_st AVR;

AVR* criar_arvore();
boolean construir_arvore(AVR* arvore);
NO* criar_node(CAD* cad);
NO* arv_inserir_node(NO* raiz, CAD * cadastro);//nooode
void exec_insercao(AVR* arvore);
void arvore_pre_ordem(AVR *arvore);
void pre_ordem_recursao(NO *raiz);//noode
CAD* arvore_busc(AVR* arvore, char* cpf);
CAD* arvore_buscar_no(NO* raiz, char*cpf);//niodeee
void exec_busca_binaria(AVR* arvore);
void troca_no_removido(NO* troca, NO* raiz, NO* ant);//nooode
boolean arv_remover_node(NO **raiz, char* cpf);//nodeee
boolean exec_remocao(AVR* arvore);
void cortar_arvore(AVR **arvore) ;
void apagar_arvore(NO** raiz);

#endif