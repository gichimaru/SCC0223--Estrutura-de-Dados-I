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

CATALOGO *criar_catalogo() {

    CATALOGO *catalogo;
    catalogo = (CATALOGO*)malloc(sizeof(CATALOGO));

    if(catalogo != NULL) {
        catalogo->verificador = 0;

        return (catalogo);
    }

    return (NULL);
}

char* nome_jogo(JOGO *jogo) {

    if(jogo != NULL) {
        return (jogo->nome);
    }

    return (NULL);
}

boolean verifica_A(char *aux) {
    char *fim = "A\0";

    return (comparar_strings(aux, fim));
}

void pesquisar_ano( CATALOGO *catalogo){
    int ano = 0;
    int jogos_enc = 0;

    scanf("%d", &ano);
    for(int i = 0; i < catalogo->verificador; i++) {

        if(catalogo->jogos[i]->ano == ano){

            printf("%s\n", nome_jogo(catalogo->jogos[i]));
            jogos_enc++;
        }
    }

    if (jogos_enc == 0) {
        printf("Nada encontrado\n");
    }

    return;
}

boolean verifica_E(char *aux){
    char *fim = "E\0";

    return(comparar_strings(aux, fim));
}

char* prod_jogo(JOGO *jogo) {

    if(jogo != NULL) {
        return (jogo->produtora);
    }

    return (NULL);
}

boolean comparar_produtoras(JOGO *jogo,char *produtora) {

    if(comparar_strings(prod_jogo(jogo), produtora)) {
        return TRUE;
    }

    return FALSE;
}

void procurar_produtora(CATALOGO *catalogo, char *produtora) {
    int jogos_enc = 0;

    for(int i = 0; i < catalogo->verificador; i++) {

        if(comparar_produtoras(catalogo->jogos[i], produtora)){
            
            printf("%s\n", nome_jogo(catalogo->jogos[i]));
            jogos_enc++;
        }
    }

    if (jogos_enc == 0) {
        printf("Nada encontrado\n");
    }

    return;
}

void pesquisar_prod(CATALOGO *catalogo){
    char *produtora;

    produtora = ler_nom_prod();
    procurar_produtora(catalogo, produtora);

    return;
}

void pesquisar(CATALOGO *catalogo){
    char aux[100];

    while(verifica_F(aux) == FALSE) {

        if(verifica_A(aux) == TRUE){
            pesquisar_ano(catalogo);
        }
        if(verifica_E(aux) == TRUE){
            pesquisar_prod(catalogo);
        }
    }

    return;
}

void apagar_catalogo(CATALOGO *catalogo){

    if (catalogo != NULL) {
        deletar_jogos(catalogo);

        free(catalogo);
        catalogo = NULL;
    }

    return;
}