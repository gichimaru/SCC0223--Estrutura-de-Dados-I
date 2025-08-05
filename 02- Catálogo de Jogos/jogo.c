#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "catalogo.h"

struct jogo_st {
    char nome[100];
    char produtora[100];
    int ano;
};

struct catalogo_st {
    JOGO *jogos[30];
    int verificador;
};

void ler_jogos(CATALOGO *catalogo) {
    JOGO *jogo;
    char aux[100];

    while(verifica_F(aux) == FALSE) {
        jogo = atribuir_valores(aux);

        if((catalogo != NULL) && (jogo != NULL)) {
            catalogo->jogos[catalogo->verificador] = jogo;
            catalogo->verificador++;
        }
    }

    return;
}

boolean verifica_F(char *aux) {
    char *fim = "F\0";
    char *aux1;

    aux1 = ler_nom_prod(); //fiz assim, e não direto na próxima linha,para não haver vazamento na memória
    strcpy(aux, aux1);

    free(aux1);
    aux1 = NULL;
    
    return (comparar_strings(aux, fim));
}

char* ler_nom_prod() {
    char *string = NULL;
    char ch;
    int i = 0;

    do{
        ch = (char)getchar();
        string = (char *) realloc(string, sizeof (char) * (i + 1));
        string[i] = ch;
        i++;

        if(ch == '\r') {
            ch = (char)getchar();
        }

    } while ((ch != '\n') && (ch != EOF));

    string[i- 1] = '\0';

    return (string);
}

boolean comparar_strings(const char *string1, const char *string2) {
    
    if(strcmp(string1, string2) != 0) {
        return FALSE;
    }

    return TRUE;
}

JOGO* atribuir_valores(char *nome) {
    JOGO jogo;
    char *aux, fim;
    
    if(nome != NULL) {

        strcpy(jogo.nome, nome);
        aux = ler_nom_prod();
        strcpy(jogo.produtora, aux);
        scanf("%d", &jogo.ano);

        fim = (char)getchar();
        if( fim == '\r'){
            getchar();
        }

        free(aux);
        aux = NULL;

        return (criar_jogo(jogo.nome, jogo.produtora, jogo.ano));
    }
    return (NULL);
}

JOGO* criar_jogo (char *nome, char *produtora, int ano) {
    JOGO *jogo;

    jogo = (JOGO*) malloc(sizeof(JOGO));

    if (jogo != NULL) {
        strcpy(jogo->nome, nome);
        strcpy(jogo->produtora, produtora);
        jogo->ano = ano;

        return (jogo);
    }

    return (NULL);
}

void deletar_jogos(CATALOGO *catalogo) {
    
    for(int i = 0; i < catalogo->verificador; i++) {
        if (catalogo->jogos[i] != NULL) {
            free(catalogo->jogos[i]);
            catalogo->jogos[i] = NULL;
        }
    }

    return;
}