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
	for ( i = 0; i < nivel; i++) printf("    ");
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

NoABB* remover_abb(NoABB* raiz, int valor) {
    if (raiz == NULL) return NULL;

    if (valor < raiz->valor) {
        raiz->esq = remover_abb(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = remover_abb(raiz->dir, valor);
    } else {
        // Encontrou o nó a remover
        if (raiz->esq == NULL) {
            NoABB* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            NoABB* temp = raiz->esq;
            free(raiz);
            return temp;
        } else {
            // Dois filhos: encontrar sucessor
            NoABB* temp = raiz->dir;
            while (temp->esq) temp = temp->esq;
            raiz->valor = temp->valor;
            raiz->dir = remover_abb(raiz->dir, temp->valor);
        }
    }

    return raiz;
}

