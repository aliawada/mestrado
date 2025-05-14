#include "arvoreBinaria.h"

// Cria uma árvore binária de busca vazia
// Pré-condição: nenhuma
// Pós-condição: árvore criada (ponteiro para NULL)
arvore* cria_arvore_vazia() {
    arvore* nova_arvore = (arvore*) malloc(sizeof(arvore));
    if (nova_arvore == NULL) {
        printf("Erro: falha ao alocar memória para a árvore.\n");
        return NULL;
    }
    *nova_arvore = NULL;
    return nova_arvore;
}

int vazia(arvore r) {
    return (r == NULL);
}

void in_ordem(arvore r) {
    if (!vazia(r)) {
        in_ordem(r->esq);
        printf("%d ", r->info);
        in_ordem(r->dir);
    }
}

void pre_ordem(arvore r) {
    if (!vazia(r)) {
        printf("%d ", r->info);
        pre_ordem(r->esq);
        pre_ordem(r->dir);
    }
}

void pos_ordem(arvore r) {
    if (!vazia(r)) {
        pos_ordem(r->esq);
        pos_ordem(r->dir);
        printf("%d ", r->info);
    }
}

int contar_elementos(arvore r) {
    if (r == NULL) return 0;
    return 1 + contar_elementos(r->esq) + contar_elementos(r->dir);
}

int soma_elementos(arvore r) {
    if (r == NULL) return 0;
    return r->info + soma_elementos(r->esq) + soma_elementos(r->dir);
}

int maximo(arvore r) {
    while (r->dir != NULL)
        r = r->dir;
    return r->info;
}

int minimo(arvore r) {
    while (r->esq != NULL)
        r = r->esq;
    return r->info;
}

arvore insere_arvore_binaria(arvore r, int x) {
    if (vazia(r)) {
        r = (struct no*) malloc(sizeof(struct no));
        r->info = x;
        r->esq = NULL;
        r->dir = NULL;
    } else if (x < r->info) {
        r->esq = insere_arvore_binaria(r->esq, x);
    } else {
        r->dir = insere_arvore_binaria(r->dir, x);
    }
    return r;
}

arvore remove_arvore_binaria(arvore r, int x) {
    if (vazia(r)) return NULL;

    if (x < r->info) {
        r->esq = remove_arvore_binaria(r->esq, x);
    } else if (x > r->info) {
        r->dir = remove_arvore_binaria(r->dir, x);
    } else {
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            return NULL;
        } else if (r->esq == NULL) {
            arvore temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            arvore temp = r->esq;
            free(r);
            return temp;
        } else {
            r->info = maximo(r->esq);
            r->esq = remove_arvore_binaria(r->esq, r->info);
        }
    }
    return r;
}

arvore busca_arvore_binaria(arvore r, int x) {
    if (vazia(r)) return NULL;
    if (r->info == x) return r;
    if (x < r->info)
        return busca_arvore_binaria(r->esq, x);
    else
        return busca_arvore_binaria(r->dir, x);
}

void libera_arvore(arvore r) {
    if (!vazia(r)) {
        libera_arvore(r->esq);
        libera_arvore(r->dir);
        free(r);
    }
}

