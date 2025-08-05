#include "avl.h"

typedef struct node_st NO;

struct avl_st {
    NO* raiz;
    int prof;
};

struct jogos_st {
    char* nome;
    char* ano;
    char* produtora;
};

struct node_st {
    NO* direita;
    NO* esquerda;
    JOGO* jogo;
    int altura;
};

AVL* criar_avl() {
    AVL* avl;
    avl = (AVL*)malloc(sizeof(AVL));
    if(avl != NULL) {
        avl->raiz = NULL;
        avl->prof = 0;
        return avl;
    }

    return NULL;
}

NO* rotacao_direita(NO* raiz) {
    NO* raiz_nova = raiz->esquerda;
    NO* no_filho = raiz_nova->direita;

    raiz_nova->direita = raiz;
    raiz->esquerda = no_filho;

    int altura = 1 + (maior_altura(no_altura(raiz->direita), no_altura(raiz->esquerda)));
    
    raiz_nova->altura = altura;

    return raiz_nova;
}

NO* rotacao_esquerda(NO* raiz) {
    NO* nova_raiz = raiz->direita;
    NO* no_filho = nova_raiz->esquerda;

    nova_raiz->esquerda = raiz;
    raiz->direita = no_filho;

    int altura = 1 + (maior_altura(no_altura(raiz->esquerda), no_altura(raiz->direita)));

    nova_raiz->altura = altura;

    return nova_raiz;
}

NO *rotacao_hibrida1(NO *node){
    node->direita = rotacao_direita(node->direita);
    return rotacao_esquerda(node);
}

NO *rotacao_hibrida2(NO *node){
    node->esquerda = rotacao_esquerda(node->esquerda);
    return rotacao_direita(node);
}

NO* balancear_avl(NO* raiz) {

    int fator_raiz = fator_balanceamento(raiz);
    int fator_direita = fator_balanceamento(raiz->direita);
    int fator_esquerda = fator_balanceamento(raiz->esquerda);


    if((fator_raiz > 1) && (fator_esquerda >= 0)) {
        raiz = rotacao_direita(raiz);
    }
    else if((fator_raiz < -1 ) && (fator_direita <= 0)) {
        raiz = rotacao_esquerda(raiz);
    }
    else if((fator_raiz < -1) && (fator_direita > 0)) {
        raiz = rotacao_hibrida1(raiz);
    }
    else if((fator_raiz > 1) && (fator_esquerda < 0)) {
        raiz = rotacao_hibrida2(raiz);
    }

    return raiz;
}

NO* avl_inserir_no(NO* raiz, JOGO* jogo) {
    int cont = 0;
    
    if(raiz == NULL) {
        return(criar_node(jogo));
    }
    else {
        if(ano_jogo(raiz->jogo) == ano_jogo(jogo)) {
            cont = comparar_nomes(raiz->jogo->nome,jogo->nome);

            if(cont > 0) {
                raiz->direita = avl_inserir_no(raiz->direita, jogo);
            }
            else if(cont < 0) {
                raiz->esquerda = avl_inserir_no(raiz->esquerda, jogo);
            }

        }
        else if(ano_jogo(raiz->jogo) < ano_jogo(jogo)) {
            raiz->direita = avl_inserir_no(raiz->direita, jogo);
        }
        else if(ano_jogo(raiz->jogo) > ano_jogo(jogo)) {
            raiz->esquerda = avl_inserir_no(raiz->esquerda, jogo);
        }

        raiz->altura = 1 + maior_altura(no_altura(raiz->direita), no_altura(raiz->esquerda));
        raiz = balancear_avl(raiz);

        return raiz;
    }
}

AVL* avl_inserir(AVL* avl, JOGO* jogo) {
    avl->raiz = avl_inserir_no(avl->raiz, jogo);
    return avl;
}

AVL* preencher_avl() {
    int i = 0, tam_atual = 0, tam_arq = 0;
    char* aux = NULL;

    FILE* arq = abrir_arq();
    JOGO* jogo = criar_jogo();
    AVL* avl = criar_avl();

    tam_arq = tam_arquivo(arq);

    do {
        aux = read_line(arq);
        tam_atual = ftell(arq);

        preencher_jogo(aux, jogo);
    
        if(jogo != NULL) {
            avl = avl_inserir(avl,jogo);
        }

        i++;
        free(aux);
        aux = NULL;
        
    } while(tam_atual != tam_arq);
    
    fclose(arq);

    return avl;
}

void pre_ordem(NO* no) {

    if (no != NULL) {
        imprimir_jogo(no->jogo);
        pre_ordem(no->esquerda);
        pre_ordem(no->direita);
    }

    return;
}

void em_ordem(NO* no) {

    if (no != NULL) {
        em_ordem(no->esquerda);
        imprimir_jogo(no->jogo);
        em_ordem(no->direita);
    }

    return;  
}

void pos_ordem(NO* no) {

    if (no != NULL) {
        pos_ordem(no->esquerda);
        pos_ordem(no->direita);
        imprimir_jogo(no->jogo);
    }

    return; 
}

JOGO* busca_avl_no(NO* raiz, int ano_rem) {

    if(raiz != NULL) {

        if(ano_rem == ano_jogo(raiz->jogo)) {
           return (raiz->jogo);
        }
        if(ano_jogo(raiz->jogo) < ano_rem) {
            return(busca_avl_no(raiz->direita, ano_rem));
        }
        else{
            return(busca_avl_no(raiz->esquerda, ano_rem));
        }
    }

    return NULL;
}

JOGO* busca_avl(AVL* avl, int ano_rem) {
    return(busca_avl_no(avl->raiz, ano_rem));
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

    raiz->jogo = troca->jogo;
    free(troca);
    troca = NULL;
    return;
}

boolean no_deletar(NO** raiz, int ano) {
    if((*raiz) == NULL) {
        return FALSE;
    }

    if(ano == ano_jogo((*raiz)->jogo)) {
        apagar_jogo(&(*raiz)->jogo);
        free((*raiz)->jogo);
        ((*raiz)->jogo) = NULL;

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
    }
    else{
        if(ano_jogo((*raiz)->jogo) < ano) {
            no_deletar(&(*raiz)->direita, ano);
        }
        else{
            no_deletar(&(*raiz)->esquerda, ano);
        }
    }

    (*raiz)->altura = 1 + maior_altura(no_altura((*raiz)->esquerda),no_altura((*raiz)->direita));
    (*raiz) = balancear_avl((*raiz));

    return TRUE;
}

AVL* avl_deletar(AVL* avl, int ano_rem) {

    while(busca_avl(avl, ano_rem) != NULL) {
        no_deletar(&avl->raiz, ano_rem);
    }

    return avl;
}

void apagar_arvore(NO** raiz) {

    if (*raiz != NULL) {
        apagar_arvore(&(*raiz)->direita);
        apagar_arvore(&(*raiz)->esquerda);
        apagar_jogo(&(*raiz)->jogo);

        free((*raiz)->jogo);
        (*raiz)->jogo = NULL;

        free(*raiz);
        *raiz = NULL;
    }
    
    return;
}

void destruir_avl(AVL** avl) {
    apagar_arvore(&(*avl)->raiz);
    free(*avl);
    *avl = NULL;
    return;
}