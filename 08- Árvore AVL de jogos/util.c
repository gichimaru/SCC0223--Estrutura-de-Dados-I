#include "util.h"

typedef struct node_st NO;

struct node_st {
    NO* direita;
    NO* esquerda;
    JOGO* jogo;
    int altura;
};

struct jogos_st {
    char* nome;
    char* ano;
    char* produtora;
};

FILE* abrir_arq() {
    FILE* arq;
    arq = fopen("CSV.csv", "r+");

    if(arq == NULL) {
        printf("Arquivo nulo");
        fclose(arq);
        exit(0);
    }

    fseek(arq,3,SEEK_SET);

    return arq;
}

int tam_arquivo(FILE *arq){
    int tam = 0;

    fseek(arq, 0, SEEK_END);
    tam = ftell(arq);
    fseek(arq, 3, SEEK_SET);

    return tam;
}

char* read_line(FILE *arq){
    char *string = NULL;
    char ch = '\0';
    int i = 0;

    do{
        fread(&ch, sizeof(char), 1, arq);

        if(ch != '\n') {
            string = (char*)realloc(string,  (i + 1) * sizeof(char));

            if(string != NULL){
                string[i] = ch;
                i++;
            }
        }

    } while(ch != '\n');

    string = (char*)realloc(string,  (i + 1) * sizeof(char));

    if(string != NULL) {
        string[i] = '\0';
    } 

    return string;
}

char* separar_strings(char* jogo, int* index) {
    char* string = NULL;
    char ch = 'a';
    int i = 0;

    while((ch != '\0') && (ch != ';')) {
        ch = jogo[*index];

        string = (char*) realloc(string, (i+1)* sizeof(char));

        if(string != NULL) {
            if(ch != '\0' && ch != ';') {
                string[i] = ch;
            }
            else{
                string[i] = '\0';
            }
        }

        i++;
        (*index)++;
    }

    return string;
}

NO* criar_node(JOGO* jogo) {
    NO* no;
    no = (NO*)malloc(sizeof(NO));
    
    if(no != NULL) {
        no->jogo = jogo;
        no->direita = NULL;
        no->esquerda = NULL;
        no->altura = 0;
        return no;
    }

    return NULL;
}

int comparar_nomes(char* raiz, char*jogo) {
    return (strcmp(raiz, jogo));
}

int no_altura(NO* no) {

    if(no == NULL) {
        return (-1);
    }
    
    return no->altura;
}

int maior_altura(int direita, int esquerda) {

    if(direita > esquerda) {
        return direita;
    }
    else{
        return(esquerda);
    }
    
    return (-2566);
}

int fator_balanceamento(NO* no) {

    if(no != NULL) {
        int fator_esq = no_altura(no->esquerda);
        int fator_dir = no_altura(no->direita);
        int fator = (fator_esq - fator_dir);

        return fator;
    }

    return 0;
}

char* ler_ano() {
    char* string = NULL;
    char ch = '\0';
    int i = 0;

    while((ch = getchar()) == '\n' || ch == '\r');
    if(ch != EOF)
        ungetc(ch, stdin);
    
    do{
        ch = (char)getchar();

        if(ch == 'F') {
            return "F\0";
        }

        string = (char*)realloc(string, ++i * sizeof(char));
        string[i - 1] = ch;

    }while(ch != '\n' && ch != '\r');

    string[i-1] = '\0';

    return string;
}

boolean comparar_strings(const char *string1, const char *string2) {
    
    if(strcmp(string1, string2) != 0) {
        return FALSE;
    }

    return TRUE;
}