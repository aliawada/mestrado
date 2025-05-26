#include "avl.h"

int altura(NoAVL* no) {
    return no ? no->altura : -1;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int fator_balanceamento(NoAVL* no) {
    return altura(no->esq) - altura(no->dir);
}

NoAVL* rotacao_direita(NoAVL* y) {
    NoAVL* x = y->esq;
    NoAVL* T2 = x->dir;
    x->dir = y;
    y->esq = T2;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    return x;
}

NoAVL* rotacao_esquerda(NoAVL* x) {
    NoAVL* y = x->dir;
    NoAVL* T2 = y->esq;
    y->esq = x;
    x->dir = T2;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    return y;
}

NoAVL* balancear(NoAVL* no) {
    if (!no) return NULL;
    no->altura = max(altura(no->esq), altura(no->dir)) + 1;
    int fb = fator_balanceamento(no);
    if (fb > 1) {
        if (fator_balanceamento(no->esq) >= 0)
            return rotacao_direita(no);
        else {
            no->esq = rotacao_esquerda(no->esq);
            return rotacao_direita(no);
        }
    } else if (fb < -1) {
        if (fator_balanceamento(no->dir) <= 0)
            return rotacao_esquerda(no);
        else {
            no->dir = rotacao_direita(no->dir);
            return rotacao_esquerda(no);
        }
    }
    return no;
}

NoAVL* inserir_avl(NoAVL* raiz, int valor) {
    if (!raiz) {
        NoAVL* novo = (NoAVL*)malloc(sizeof(NoAVL));
        novo->valor = valor;
        novo->altura = 0;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (valor < raiz->valor)
        raiz->esq = inserir_avl(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir_avl(raiz->dir, valor);
    return balancear(raiz);
}

void imprimir_arvore_avl(NoAVL* raiz, int nivel) {
    if (!raiz) return;
    imprimir_arvore_avl(raiz->dir, nivel + 1);
    int i;
	for (i = 0; i < nivel; i++) printf("    ");
    printf("%d\n", raiz->valor);
    imprimir_arvore_avl(raiz->esq, nivel + 1);
}

void liberar_avl(NoAVL* raiz) {
    if (raiz) {
        liberar_avl(raiz->esq);
        liberar_avl(raiz->dir);
        free(raiz);
    }
}
