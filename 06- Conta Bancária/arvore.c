#include "arvore.h"
#include "cadastro.h"

typedef struct node_st NO;

struct node_st {
    CAD *cadastro;
    NO *direita;
    NO *esquerda;
};

struct arvore_st {
    NO *raiz;
};

struct cadastro_st {
    char *cpf;
    char *nome;
    char *idade;
    char *saldo;
};

AVR* criar_arvore() {
    AVR* arvore;
    arvore = (AVR*)malloc(sizeof(AVR));

    if(arvore != NULL) {
        arvore->raiz = NULL;
        return(arvore);
    }

    return NULL;
}

boolean construir_arvore(AVR* arvore) {
    CAD *cadastro;
    cadastro = preencher_cadastro();

    if(cadastro != NULL) {
        arvore->raiz = arv_inserir_node(arvore->raiz, cadastro);
        return TRUE;
    }

    return FALSE;
}

NO* criar_node(CAD* cad) {
    NO* no;
    no = (NO*)malloc(sizeof(NO));
    
    if(no != NULL) {
        no->cadastro = cad;
        no->direita = NULL;
        no->esquerda = NULL;
        return(no);
    }

    return NULL;
}

NO* arv_inserir_node(NO* raiz, CAD * cadastro) {

    if(raiz == NULL) {
        raiz = criar_node(cadastro);
    }
    else if (maior_num(raiz->cadastro,cadastro->cpf)) {
        raiz->direita = arv_inserir_node(raiz->direita, cadastro);
    }
    else {
        raiz->esquerda = arv_inserir_node(raiz->esquerda, cadastro);
    }
    
    return raiz;
}

void exec_insercao(AVR* arvore) {
    construir_arvore(arvore);

    return;
}

void arvore_pre_ordem(AVR *arvore) {

    printf("Preorder\n");
    pre_ordem_recursao(arvore->raiz);
    printf("\n");
    return;
}

void pre_ordem_recursao(NO *raiz) {

    if (raiz != NULL) {
        cpf_sem_pontos(raiz->cadastro->cpf);
        pre_ordem_recursao(raiz->esquerda);
        pre_ordem_recursao(raiz->direita);
    }
    return;
}

CAD* arvore_busc(AVR* arvore, char* cpf) {
    return(arvore_buscar_no(arvore->raiz, cpf));
}

CAD* arvore_buscar_no(NO* raiz, char* cpf) {

    if(raiz == NULL) {
        return NULL;
    }

    if(comparar_strings(cpf, raiz->cadastro->cpf)) {
        return (raiz->cadastro);
    }

    if(maior_num(raiz->cadastro, cpf)){
        return(arvore_buscar_no(raiz->direita, cpf));
    }
    else{
        return(arvore_buscar_no(raiz->esquerda, cpf));
    }

    return NULL;
}

void exec_busca_binaria(AVR* arvore) {
    char *cpfBuscado = ler_cpf();
    CAD* cadastro =  NULL;

    cadastro = arvore_busc(arvore, cpfBuscado);

    if(cadastro == NULL) {
        printf("Pessoa nao encontrada");
    }
    else {
        imprimir_cadastro(cadastro);
    }

    printf("\n");//necessário para o runcodes

    apagar_cadastro(&cadastro);
    free(cpfBuscado);
    cpfBuscado = NULL;

    return ;
}

void troca_no_removido(NO* troca, NO* raiz, NO* ant) {

    if(troca->direita != NULL) {
        troca_no_removido(troca->esquerda, raiz, troca);
        return;
    }

    if(raiz == ant) {
        ant->direita = troca->direita;
    }
    else{
        ant->esquerda = troca->direita;
    }

    raiz->cadastro = troca->cadastro;
    free(troca);
    troca = NULL;
    return;
}

boolean arv_remover_node(NO **raiz, char* cpf) {

    if((*raiz) == NULL) {
        return FALSE;
    }

    if(comparar_strings(cpf, (*raiz)->cadastro->cpf)) {
        imprimir_cadastro((*raiz)->cadastro);

        apagar_cadastro(&(*raiz)->cadastro);
        free((*raiz)->cadastro);

        if((*raiz)->esquerda == NULL || (*raiz)->direita == NULL) {

            if((*raiz)->esquerda == NULL) {
                *raiz = (*raiz)->direita;
            }
            else{
                *raiz = (*raiz)->esquerda;
            }

        }
        else{
            troca_no_removido((*raiz)->direita,(*raiz), (*raiz));
        }

        free(cpf);
        cpf = NULL;
        return TRUE;
    }
    else {

        if(maior_num((*raiz)->cadastro, cpf)) {
            arv_remover_node(&(*raiz)->direita, cpf);
        }
        else{
            arv_remover_node(&(*raiz)->esquerda, cpf);
        }
    }

    return FALSE;
}

boolean exec_remocao(AVR* arvore) {
    char* cpf;
    cpf = ler_cpf();

    if(arvore != NULL) {
        return (arv_remover_node(&arvore->raiz, cpf));
    }

    return FALSE;
}

void cortar_arvore(AVR **arvore) {
    apagar_arvore(&(*arvore)->raiz);
    free(*arvore);
    *arvore = NULL;

    return;
}

void apagar_arvore(NO** raiz) {

    if (*raiz != NULL) {
        apagar_arvore(&(*raiz)->esquerda);
        apagar_arvore(&(*raiz)->direita);
        apagar_cadastro(&(*raiz)->cadastro);

        free((*raiz)->cadastro);
        (*raiz)->cadastro = NULL;
        free(*raiz);
        *raiz = NULL;
    }
    
    return;
}