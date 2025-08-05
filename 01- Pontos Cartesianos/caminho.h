#ifndef CAMINHO_H
#define CAMINHO_H

typedef struct caminho_st CAMINHO;

CAMINHO* criar_caminho(int coord, PONTO **pontos);
double calcular_dist(CAMINHO *caminho, int coord);
void imprimir_resultado(double dist);
void liberar_caminho(CAMINHO *caminho);

#endif //CAMINHO_H