#ifndef PONTO_H
#define PONTO_H

typedef struct ponto_st PONTO;

PONTO** criar_pontos(int coord);
void liberar_pontos(PONTO **pontos, int coord);

#endif //PONTO_H