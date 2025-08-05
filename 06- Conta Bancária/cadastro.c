#include "cadastro.h"
#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastro_st {
    char *cpf;
    char *nome;
    char *idade;
    char *saldo;
};

CAD* criar_cadastro() {
    CAD* cadastro;
    cadastro = (CAD*)malloc(sizeof(CAD));

    if(cadastro != NULL) {
        cadastro->cpf = NULL;
        cadastro->nome = NULL;
        cadastro->idade = NULL;
        cadastro->saldo = NULL;
        return(cadastro);
    }

    return NULL;
}

CAD* preencher_cadastro() {
    CAD* cad = NULL;
    cad = criar_cadastro();

    if(cad != NULL) {
        cad->cpf= ler_cpf();
        cad->nome = ler_info();
        cad->idade = ler_info();
        cad->saldo = ler_info();
        return cad;
    } 
    
    return NULL;
}

boolean maior_num(CAD *raiz, char *cpf) {
    int maior = is_big(raiz->cpf, cpf);

    if(maior == 1) {
        return TRUE;
    }

    return FALSE;
}

void imprimir_cadastro(CAD *cad) {
    printf("Conta :: %s\n", cad->nome);
    imprimir_cpf(cad->cpf);
    printf("\nIdade :: %s", cad->idade);
    printf("\nSaldo atual :: R$ %s\n",cad->saldo);
    return;
}

void apagar_cadastro(CAD** cad) {
    free((*cad)->cpf);
    (*cad)->cpf = NULL;
    free((*cad)->nome);
    (*cad)->nome = NULL;
    free((*cad)->idade);
    (*cad)->idade = NULL;
    free((*cad)->saldo);
    (*cad)->saldo = NULL;
    
    return;
}