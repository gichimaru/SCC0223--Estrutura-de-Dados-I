#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogos.h"

#define TRUE 1
#define FALSE 0

typedef int boolean;
typedef struct node_st NO;
typedef struct jogos_st JOGO;

FILE* abrir_arq();
int tam_arquivo(FILE *arq);
char *read_line(FILE *file);
char* separar_strings(char* jogo, int* index);
NO* criar_node(JOGO* jogo);
int comparar_nomes(char* raiz, char*jogo);
int no_altura(NO* no);
int maior_altura(int direita, int esquerda);
int fator_balanceamento(NO* no);
char* ler_ano();
boolean comparar_strings(const char *string1, const char *string2);

#endif