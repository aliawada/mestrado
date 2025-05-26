#include "rb.h"

int eh_vermelho(NoRB* no) {
    return no != NULL && no->cor == VERMELHO;
}

NoRB* rotacao_esquerda_rb(NoRB* h) {
    NoRB* x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = VERMELHO;
    return x;
}

NoRB* rotacao_direita_rb(NoRB* h) {
    NoRB* x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->cor = h->cor;
    h->cor = VERMELHO;
    return x;
}

void troca_cores_rb(NoRB* h) {
    h->cor = VERMELHO;
    if (h->esq) h->esq->cor = PRETO;
    if (h->dir) h->dir->cor = PRETO;
}

NoRB* balancear_rb(NoRB* h) {
    if (eh_vermelho(h->dir) && !eh_vermelho(h->esq))
        h = rotacao_esquerda_rb(h);
    if (eh_vermelho(h->esq) && eh_vermelho(h->esq->esq))
        h = rotacao_direita_rb(h);
    if (eh_vermelho(h->esq) && eh_vermelho(h->dir))
        troca_cores_rb(h);
    return h;
}

NoRB* inserir_rec_rb(NoRB* h, int valor) {
    if (h == NULL) {
        NoRB* novo = (NoRB*)malloc(sizeof(NoRB));
        novo->valor = valor;
        novo->cor = VERMELHO;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (valor < h->valor)
        h->esq = inserir_rec_rb(h->esq, valor);
    else if (valor > h->valor)
        h->dir = inserir_rec_rb(h->dir, valor);

    return balancear_rb(h);
}

NoRB* inserir_rb(NoRB* raiz, int valor) {
    raiz = inserir_rec_rb(raiz, valor);
    raiz->cor = PRETO;
    return raiz;
}

void imprimir_arvore_rb(NoRB* raiz, int nivel) {
    if (!raiz) return;
    imprimir_arvore_rb(raiz->dir, nivel + 1);
    int i;
	for (i = 0; i < nivel; i++) printf("    ");
    printf("%d (%s)\n", raiz->valor, raiz->cor == VERMELHO ? "R" : "B");
    imprimir_arvore_rb(raiz->esq, nivel + 1);
}

void liberar_rb(NoRB* raiz) {
    if (raiz) {
        liberar_rb(raiz->esq);
        liberar_rb(raiz->dir);
        free(raiz);
    }
}
