#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NoAVL {
    int valor;
    int altura;
    struct NoAVL *esq, *dir;
} NoAVL;

NoAVL* inserir_avl(NoAVL* raiz, int valor);
int altura(NoAVL* no);
int fator_balanceamento(NoAVL* no);
void imprimir_arvore_avl(NoAVL* raiz, int nivel);
NoAVL* remover_avl(NoAVL* raiz, int valor);
void liberar_avl(NoAVL* raiz);

#endif
