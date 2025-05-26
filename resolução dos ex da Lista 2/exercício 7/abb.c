#include "abb.h"

NoABB* inserir_abb(NoABB* raiz, int valor) {
    if (raiz == NULL) {
        NoABB* novo = (NoABB*)malloc(sizeof(NoABB));
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (valor < raiz->valor)
        raiz->esq = inserir_abb(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir_abb(raiz->dir, valor);
    return raiz;
}

void imprimir_arvore_abb(NoABB* raiz, int nivel) {
    if (raiz == NULL) return;
    imprimir_arvore_abb(raiz->dir, nivel + 1);
    int i;
	for (i = 0; i < nivel; i++) printf("    ");
    printf("%d\n", raiz->valor);
    imprimir_arvore_abb(raiz->esq, nivel + 1);
}

void liberar_abb(NoABB* raiz) {
    if (raiz) {
        liberar_abb(raiz->esq);
        liberar_abb(raiz->dir);
        free(raiz);
    }
}
