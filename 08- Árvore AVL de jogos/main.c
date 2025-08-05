#include "avl.h"

struct avl_st {
    NO* raiz;
    int prof;
};

int main () {
    AVL* avl = NULL;
    char* aux = NULL;
    int ordem = 0;
    
    avl = preencher_avl(avl);
    
    scanf("%d\n", &ordem);

    while(TRUE) {
        aux = ler_ano();

        if(comparar_strings(aux, "F")) {
            if(ordem == 1) {
                pre_ordem(avl->raiz);
            }
            else if(ordem == 2) {
                em_ordem(avl->raiz);
            }
            else if(ordem == 3) {
                pos_ordem(avl->raiz);
            }

            break;
        }
        else {
            int ano_rem = atoi(aux);
            avl = avl_deletar(avl, ano_rem);

            free(aux);
            aux = NULL;
        }

    }

    destruir_avl(&avl);
    
    return 0;
}