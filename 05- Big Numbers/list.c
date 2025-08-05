#include "list.h"

struct list_st {
    NO *ini;
    NO *fim;
    boolean neg;
    int qtd;
};

void realizar_operacoes(int qtdOp) {

    for (int i = 0; i < qtdOp; i++) {
        char *operacao =  read_word();

        if (!strcmp(operacao, "soma")) {

            LISTA *lista = exec_soma();
            imprimir_lista(lista);

            free_list(lista);
            lista = NULL;
        }
        else if (!strcmp(operacao, "maior")) {

            int maior = maior_num();

            if (maior == 0) {
                printf("Resultado :: False\n");
            }
            else if(maior == 1) {
                printf("Resultado :: True\n");
            }
        }
        else if (!strcmp(operacao, "menor")) {

            int maior = maior_num();

            if (maior == 0) {
                printf("Resultado :: True\n");
            }
            else if(maior == 1) {
                printf("Resultado :: False\n");
            }
        }
        else {
            int maior = maior_num();
            
            if (maior == 3) {
                printf("Resultado :: True\n");
            }
            else{
                printf("Resultado :: False\n");
            }
        }

        free(operacao);
        operacao = NULL;
    }
    return;
}

LISTA *exec_soma() {
    LISTA *l1 = preencher_lista();
    LISTA *l2 = preencher_lista();

    int tam = max(l1, l2);

    LISTA *aux = criar_lista();

    for (int i = 0; i < tam; i++){
        inserir_elem_fim(aux, '0');
    }
    
    somar_listas(aux,l1);
    somar_listas(aux,l2);

    free_list(l1);
    free_list(l2);

    return aux;
}



LISTA *criar_lista() {
    LISTA *lista = (LISTA*)malloc(sizeof(LISTA));

    if(lista != NULL) {
        lista->ini = NULL;
        lista->fim = NULL;
        lista->qtd = 0;
        lista->neg = FALSE;

        return lista;
    }

    return NULL;
}

void inserir_elem_fim(LISTA *lista, elem x) {

    if (x == '-') {
        lista->neg = TRUE;
        return;
    }

    NO *aux = (NO*)malloc(sizeof(NO));
    if(aux != NULL) {
        aux->info = x;
        aux->prox = NULL;
        aux->ant = NULL;
    }

    if (lista->ini == NULL) {
        aux->prox = lista->ini;
        aux->ant = lista->ini;
        lista->ini = aux;
        lista->fim = aux;
    }
    else {
        aux->ant = lista->fim;
        aux->prox = lista->fim->prox;
        lista->fim->prox = aux;
        lista->fim = aux;
    }
    lista->qtd++;

    return;
}

void somar_listas(LISTA *aux, LISTA *lista) {

    int maior = max(aux, lista);

    NO *aux1 = aux->fim;
    NO *aux2 = lista->fim;

    int soma = 0;
    int sobe = 0;

    for (int i = 0; i < maior; i++) {
        if (aux2 == NULL) {
            int a1 = aux1->info - '0';

            soma = (a1 + sobe) % 10;
            aux1->info = soma + '0';

            sobe = (a1 + sobe) / 10;

            if (i == maior - 1 && sobe != 0) {
                inserir_elem_ini(aux, sobe + '0');
            }
            
            aux1 = aux1->ant;            
        }
        else {
            int a1 = aux1->info - '0';
            int a2 = aux2->info - '0';

            soma = (a1 + a2 + sobe) % 10;
            aux1->info = soma + '0';

            sobe = (a1 + a2 + sobe) / 10;
            if (i == maior - 1 && sobe != 0) {
                inserir_elem_ini(aux, sobe + '0');
            }
            
            aux1 = aux1->ant;
            aux2 = aux2->ant;
        }
    }

    return;
}

void inserir_elem_ini(LISTA *lista, elem x) {

    NO *aux = (NO*)malloc(sizeof(NO));
    if(aux != NULL) {
        aux->info = x;
        aux->prox = NULL;
        aux->ant = NULL;

        aux->ant = lista->ini->ant;
        aux->prox = lista->ini;
        lista->ini->ant = aux;
        lista->ini = aux;

        lista->qtd++;
    }
    return;
}

void free_list(LISTA *lista) {
    NO *aux = lista->ini;

    while (aux != NULL) {
        lista->ini = aux->prox;
        free(aux);
        aux = lista->ini;
    }
    free(lista);
    lista = NULL;

    return;
}

void imprimir_lista(LISTA *lista) {

    while (lista->ini->info == '0') {
        NO *aux1 = lista->ini;
        lista->ini = lista->ini->prox;
        free(aux1);
    }

    NO *aux = lista->ini;
    
    if (lista->neg == TRUE)
        printf("-");
    
    printf("Resultado :: ");

    while(aux != NULL) {
        printf("%d", aux->info - '0');
        aux = aux->prox;
    }

    printf("\n");
    return;
}

LISTA *preencher_lista() {
    LISTA *lista = criar_lista();
    char ch = '\0';

    while ((ch = getchar()) == '\r' || ch == '\n');
    if (ch != EOF)
        ungetc(ch, stdin);

    while (ch != ' ' && ch != '\n' && ch != '\r') {
        ch = getchar();

        if (ch != ' ' && ch != '\n' && ch != '\r')
            inserir_elem_fim(lista, ch);
    }

    return lista;
}

int maior_num() {
    LISTA *l1 = preencher_lista();
    LISTA *l2 = preencher_lista();

    int maior = is_big(l1, l2);

    free_list(l1);
    free_list(l2);

    return maior;
}

int is_big(LISTA *l1, LISTA *l2) {

    if (!l1->neg && l2->neg) {
        return 1;
    }
    else if (l1->neg && !l2->neg) {
        return 0;
    }
    else {
        if (l1->qtd > l2->qtd) {
            return 1;
        }
        else if (l2->qtd > l1->qtd) {
            return 0;
        }
        else {
            NO *aux1 = l1->ini;
            NO *aux2 = l2->ini;

            while (aux1 != NULL) {
                if (aux1->info > aux2->info) {
                    return 1;
                }
                else if (aux2->info > aux1->info) {
                    return 0;
                }
                aux1 = aux1->prox;
                aux2 = aux2->prox;
            }
        }
    }

    return 3;
}

int max(LISTA *l1, LISTA *l2) {

    if (l1->qtd > l2->qtd) {
        return l1->qtd;
    }
    else if (l2->qtd > l1->qtd) {
        return l2->qtd;
    }

    return l1->qtd;
}
