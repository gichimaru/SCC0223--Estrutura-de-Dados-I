#include "ponto.h"
#include "caminho.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct caminho_st{
    double *abcsissas;
    double *ordenadas;
};

struct ponto_st{
    double x;
    double y;
};

CAMINHO* criar_caminho(int coord, PONTO **pontos) {

    int i = 0;
    CAMINHO *caminho;

    caminho = (CAMINHO*)malloc(sizeof(CAMINHO));
    if (caminho == NULL) {
        exit(0);
    }

    caminho->abcsissas = (double*)malloc(sizeof(double)*coord);
    if (caminho->abcsissas == NULL) {
        exit(0);
    }

    caminho->ordenadas = (double*)malloc(sizeof(double)*coord);
    if (caminho->ordenadas == NULL) {
        exit(0);
    }

    for (i = 0; i < coord; i++) {
        caminho->abcsissas[i] = pontos[i]->x;
        caminho->ordenadas[i] = pontos[i]->y;
    }

    return(caminho);
}

double calcular_dist(CAMINHO *caminho, int coord) {

    double dist, aux;
    aux = 0.0;
    dist = 0.0;

    for (int i = 1; i < coord; i++) {
        aux = sqrt(pow(caminho->abcsissas[i] - caminho->abcsissas[i-1], 2) +
                pow(caminho->ordenadas[i] - caminho->ordenadas[i-1], 2));

        dist = dist + aux;
    }

    return(dist);
}

void imprimir_resultado(double dist) {

    printf("%.2lf", dist);
    return;
}

void liberar_caminho(CAMINHO *caminho) {
    
    if (caminho->abcsissas != NULL) {
        free(caminho->abcsissas);
        caminho->abcsissas = NULL;
    }

    if (caminho->ordenadas != NULL) {
        free(caminho->ordenadas);
        caminho->ordenadas = NULL;
    }

    if (caminho != NULL) {
        free(caminho);
        caminho = NULL;
    }
    
    return;
}