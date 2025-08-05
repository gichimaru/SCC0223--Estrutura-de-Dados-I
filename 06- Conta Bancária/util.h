#ifndef UTIL_H
#define UTIL_H

#define TRUE 1
#define FALSE 0
typedef int boolean;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"

char* read_line();
char* ler_info();
char* ler_cpf();
int is_big(char* raiz,char* cad);
void cpf_sem_pontos(char* cpf);
boolean comparar_strings(const char *string1, const char *string2);
void imprimir_cpf(char* cpf);

#endif