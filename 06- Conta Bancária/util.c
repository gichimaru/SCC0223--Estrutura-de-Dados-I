#include "util.h"

char* read_line() {
    char *string = NULL;
    char ch = '\0';
    int i = 0;

    while((ch = getchar()) == '\n' || ch == '\r');
    if(ch != EOF)
        ungetc(ch, stdin);

    do{
        ch = (char)getchar();
        string = (char *) realloc(string, ++i * sizeof (char));
        string[i - 1] = ch;
    } while (ch != '\n' && ch != ';' && ch != '\r');

    string[i- 1] = '\0';

    return (string);
}

char* ler_info() {
    char* aux;
    aux = read_line();

    return(aux);
}

char* ler_cpf() {
    char *aux = NULL;
    char *cpf = NULL;
    int j = 0;
    aux = read_line();
    cpf = (char*)calloc(15, sizeof(char));

    for(int i = 0; i < 14; i++) {
        if(aux[i] == '.' || aux[i] == '-'){
            continue;
        }
        cpf[j] = aux[i];
        j++;
    }
    cpf[14] = '\0';
    
    free(aux);
    aux = NULL;

    return(cpf);
}

int is_big(char* raiz, char* cad) {
    
    for(int i = 0; i < 11; i++) {
        
        if(cad[i] > raiz[i]) {
            return 1;
        }
        else if(raiz[i] > cad[i]) {
            return 0;
        }
    }

    return (-1);
}

void cpf_sem_pontos(char* cpf) {
    printf("%s\n", cpf);
    return;
}

boolean comparar_strings(const char *string1, const char *string2) {
    
    if(strcmp(string1, string2) != 0) {
        return FALSE;
    }

    return TRUE;
}

void imprimir_cpf(char* cpf) {
    int i = 0;
    printf("CPF :: ");

    for(i = 0; i < 9; i++) {
        if(i%3 == 0 && i != 0) {
            printf(".");
        }
        printf("%c", cpf[i]);
    }

    printf("-");
    printf("%c%c", cpf[9], cpf[10]);

    return;
}