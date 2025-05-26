#include "avl.h"

int altura(NoAVL* no) {
    return (no == NULL) ? -1 : no->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int fator_balanceamento(NoAVL* no) {
    return altura(no->esq) - altura(no->dir);
}

NoAVL* criar_no(int valor) {
    NoAVL* novo = (NoAVL*)malloc(sizeof(NoAVL));
    novo->valor = valor;
    novo->altura = 0;
    novo->esq = novo->dir = NULL;
    return novo;
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

NoAVL* rotacao_esquerda_direita(NoAVL* no) {
    no->esq = rotacao_esquerda(no->esq);
    return rotacao_direita(no);
}

NoAVL* rotacao_direita_esquerda(NoAVL* no) {
    no->dir = rotacao_direita(no->dir);
    return rotacao_esquerda(no);
}

NoAVL* balancear(NoAVL* no) {
    if (!no) return NULL;

    no->altura = max(altura(no->esq), altura(no->dir)) + 1;
    int fb = fator_balanceamento(no);

    if (fb > 1) {
        if (fator_balanceamento(no->esq) >= 0) {
            printf("Rotação simples à direita em %d\n", no->valor);
            return rotacao_direita(no);
        } else {
            printf("Rotação esquerda-direita (dupla) em %d\n", no->valor);
            return rotacao_esquerda_direita(no);
        }
    }

    if (fb < -1) {
        if (fator_balanceamento(no->dir) <= 0) {
            printf("Rotação simples à esquerda em %d\n", no->valor);
            return rotacao_esquerda(no);
        } else {
            printf("Rotação direita-esquerda (dupla) em %d\n", no->valor);
            return rotacao_direita_esquerda(no);
        }
    }

    return no;
}

NoAVL* inserir(NoAVL* raiz, int valor) {
    if (!raiz) return criar_no(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);
    else
        return raiz; // Valor duplicado

    return balancear(raiz);
}

NoAVL* buscar(NoAVL* raiz, int valor) {
    if (!raiz || raiz->valor == valor) return raiz;
    return (valor < raiz->valor) ? buscar(raiz->esq, valor) : buscar(raiz->dir, valor);
}

NoAVL* menor_valor(NoAVL* no) {
    while (no && no->esq) no = no->esq;
    return no;
}

NoAVL* remover(NoAVL* raiz, int valor) {
    if (!raiz) return NULL;

    if (valor < raiz->valor)
        raiz->esq = remover(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = remover(raiz->dir, valor);
    else {
        if (!raiz->esq || !raiz->dir) {
            NoAVL* temp = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);
            return temp;
        } else {
            NoAVL* temp = menor_valor(raiz->dir);
            raiz->valor = temp->valor;
            raiz->dir = remover(raiz->dir, temp->valor);
        }
    }

    return balancear(raiz);
}

void em_ordem(NoAVL* raiz) {
    if (raiz) {
        em_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        em_ordem(raiz->dir);
    }
}

void liberar_arvore(NoAVL* raiz) {
    if (raiz) {
        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);
        free(raiz);
    }
}

void imprimir_arvore(NoAVL* raiz, int nivel) {
    if (raiz == NULL)
        return;

    imprimir_arvore(raiz->dir, nivel + 1);
	
	int i;
    for (i = 0; i < nivel; i++)
        printf("    ");
    printf("%d\n", raiz->valor);

    imprimir_arvore(raiz->esq, nivel + 1);
}

