#include "jogos.h"

struct jogos_st {
    char* nome;
    int ano;
    char* produtora;
};

JOGO* criar_jogo() {
    JOGO* jogo;
    jogo = (JOGO*)malloc(sizeof(JOGO));
    if(jogo != NULL) {
        jogo->nome = NULL;
        jogo->ano = -1;
        jogo->produtora = NULL;
        return jogo;
    }

    return NULL;
}

void preencher_jogo(char* jog, JOGO* jogo) {
    int index = 0;
    char* ano = NULL;
    int aux = 0;

    jogo->nome = separar_strings(jog, &index);
    ano = separar_strings(jog, &index);
    jogo->produtora = separar_strings(jog, &index);

    aux = atoi(ano);
    jogo->ano = aux;

    free(ano);
    ano = NULL;
    
    return;
}

void imprimir_jogo(JOGO* jogo) {
    printf("%s\n", jogo->nome);
    return;
}

void apagar_jogo(JOGO** jogo) {
    free((*jogo)->nome);
    (*jogo)->nome = NULL;
    free((*jogo)->produtora);
    (*jogo)->produtora = NULL;
    return;
}

int ano_jogo(JOGO* jogo){
    return jogo->ano;
}