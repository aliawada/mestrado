#ifndef RACIONAL_H
#define RACIONAL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct racional {
    int num;
    int den;
} RACIONAL;

RACIONAL *criar(int num, int den);
void limpar(RACIONAL *rac);

RACIONAL *adicao(RACIONAL *v1, RACIONAL *v2);
RACIONAL *multiplicacao(RACIONAL *v1, RACIONAL *v2);

void imprimir(RACIONAL *rac);

#endif
