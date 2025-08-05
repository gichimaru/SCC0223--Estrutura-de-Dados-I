#include "ponto.h"
#include "caminho.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int coordenadas = 0;
    double distancia = 0.0;
    PONTO **pontos;
    CAMINHO *caminho;

    scanf("%d", &coordenadas);

    pontos = criar_pontos(coordenadas);
    caminho = criar_caminho(coordenadas, pontos);

    distancia = calcular_dist(caminho, coordenadas);
    imprimir_resultado(distancia);

    liberar_pontos(pontos, coordenadas);
    liberar_caminho(caminho);

    return 0;
}