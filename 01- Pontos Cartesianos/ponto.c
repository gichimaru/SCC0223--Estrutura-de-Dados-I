#include "ponto.h"
#include <stdlib.h>
#include <stdio.h>

struct ponto_st{
    double x;
    double y;
};

PONTO** criar_pontos(int coord) {

    double abscissa = 0.0, ordenada = 0.0;
    int i = 0;
    PONTO **pontos;

    pontos = (PONTO**)malloc(sizeof(PONTO*)*coord);
    if (pontos == NULL) {
        exit(0);
    }

    for (i = 0; i < coord; i++) {
        pontos[i] = (PONTO*) malloc(sizeof(PONTO));
        if(pontos[i] == NULL) {
            exit(0);
        }
    }

    for (i = 0; i < coord; i++) {
        scanf("%lf %lf", &abscissa, &ordenada);
        pontos[i]->x = abscissa;
        pontos[i]->y = ordenada;
    }

    return(pontos);
}

void liberar_pontos(PONTO **pontos, int coord) {

    for (int i = 0; i < coord; i++) {
        free(pontos[i]);
        pontos[i] = NULL;
    }

    free(pontos);
    pontos = NULL;
        
    return;
}