#ifndef CADASTRO_H
#define CADASTRO_H

#include "util.h"

typedef struct cadastro_st CAD;

CAD* criar_cadastro();
CAD* preencher_cadastro();
boolean maior_num(CAD *raiz, char *cad);
void imprimir_cadastro(CAD *cad);
void apagar_cadastro(CAD** cad);

#endif