#include "arvore.h"

int main() {
    AVR* arvore = NULL;
    int n = 0;
    char c = '\0';//para a pesquisa

    arvore = criar_arvore();

    scanf("%d", &n); //quantidade de contas a serem inseridas

    for(int i = 0; i < n; i++) {
        construir_arvore(arvore);
    }

    c = getchar();

    if(c == 'I') { //INSERCAO
        exec_insercao(arvore);
        arvore_pre_ordem(arvore);
    }
    else if(c == 'B') { //BUSCA
        exec_busca_binaria(arvore);
    }
    else if(c == 'R') { //REMOCAO
        exec_remocao(arvore);
        arvore_pre_ordem(arvore);
    }

    cortar_arvore(&arvore);
    
    return(0);
}

