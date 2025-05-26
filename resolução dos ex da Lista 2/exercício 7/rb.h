#ifndef RB_H
#define RB_H

#include <stdio.h>
#include <stdlib.h>

typedef enum { VERMELHO, PRETO } Cor;

typedef struct NoRB {
    int valor;
    Cor cor;
    struct NoRB *esq, *dir;
} NoRB;

NoRB* inserir_rb(NoRB* raiz, int valor);
void imprimir_arvore_rb(NoRB* raiz, int nivel);
void liberar_rb(NoRB* raiz);

#endif