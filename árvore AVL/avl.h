#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NoAVL {
    int valor;
    int altura;
    struct NoAVL *esq;
    struct NoAVL *dir;
} NoAVL;

NoAVL* criar_no(int valor);
int altura(NoAVL* no);
int max(int a, int b);
int fator_balanceamento(NoAVL* no);

NoAVL* rotacao_direita(NoAVL* y);
NoAVL* rotacao_esquerda(NoAVL* x);
NoAVL* rotacao_esquerda_direita(NoAVL* no);
NoAVL* rotacao_direita_esquerda(NoAVL* no);

NoAVL* balancear(NoAVL* no);
NoAVL* inserir(NoAVL* raiz, int valor);
NoAVL* remover(NoAVL* raiz, int valor);
NoAVL* buscar(NoAVL* raiz, int valor);

void em_ordem(NoAVL* raiz);
void liberar_arvore(NoAVL* raiz);

void imprimir_arvore(NoAVL* raiz, int nivel);

#endif

