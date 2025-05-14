#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NoABB {
    int valor;
    struct NoABB *esq, *dir;
} NoABB;

NoABB* inserir_abb(NoABB* raiz, int valor);
void imprimir_arvore_abb(NoABB* raiz, int nivel);
void liberar_abb(NoABB* raiz);
NoABB* remover_abb(NoABB* raiz, int valor);

#endif
