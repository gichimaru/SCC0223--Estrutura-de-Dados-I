#include "carta.h"

struct carta_st{
    char *nipe;
    int simbolo;
};

CARTA* criar_carta() {
    CARTA* carta;
    char aux = '\0';
    
    carta = (CARTA*)malloc(sizeof(CARTA));
    
    if(carta == NULL) {
        return NULL;
    }

    carta->simbolo = 0;
    carta->nipe = ler_nipe();
    aux = getchar();

    if((aux >= '0') && (aux <= '9')){
        ungetc(aux, stdin);
        scanf(" %d", &carta->simbolo);
    }
    else{
        carta->simbolo = 10;
    }

    return(carta);//duidudufifio
}

char* ler_nipe() {
    char *string = NULL;
    char ch = '\0';
    int i = 0;

    while((ch = getchar()) == '\n');
    if(ch != EOF)
        ungetc(ch, stdin);

    do{
        ch = (char)getchar();
        string = (char *) realloc(string, ++i * sizeof (char));
        string[i - 1] = ch;
    } while (ch != ' ');

    string[i- 1] = '\0';

    return (string);
}

int valor_carta(CARTA *carta) {
    if(carta != NULL) {
        return(carta->simbolo);
    }
    return ERRO;
}

void destruir_carta(CARTA** carta) {
    free((*carta)->nipe);
    (*carta)->nipe = NULL;
    free(*carta);
    *carta = NULL;

    return;
}