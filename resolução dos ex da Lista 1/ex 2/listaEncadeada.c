#include "listaEncadeada.h"

Lista* cria_lista_vazia() {
    return NULL;
}

int vazia(Lista* l) {
    return l == NULL;
}

Lista* inserir_inicio(Lista* l, TipoItem x) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = x;
    novo->prox = l;
    return novo;
}

Lista* inserir_fim(Lista* l, TipoItem x) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = x;
    novo->prox = NULL;

    if (vazia(l)) return novo;

    Lista* p = l;
    while (p->prox != NULL)
        p = p->prox;
    p->prox = novo;
    return l;
}

Lista* inserep(Lista* l, int p, TipoItem x) {
    if (p <= 0) return inserir_inicio(l, x);

    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = x;

    Lista* atual = l;
    int i = 0;
    while (atual != NULL && i < p - 1) {
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) {
        free(novo);
        return l;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
    return l;
}

Lista* retira(Lista* l, TipoItem x) {
    Lista* ant = NULL;
    Lista* p = l;

    while (p != NULL && p->info != x) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) return l;

    if (ant == NULL)
        l = p->prox;
    else
        ant->prox = p->prox;

    free(p);
    return l;
}

Lista* retira_pos(Lista* l, int p, TipoItem* x) {
    if (p < 0 || l == NULL) return l;

    Lista* ant = NULL;
    Lista* atual = l;
    int i = 0;

    while (atual != NULL && i < p) {
        ant = atual;
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) return l;

    *x = atual->info;

    if (ant == NULL)
        l = atual->prox;
    else
        ant->prox = atual->prox;

    free(atual);
    return l;
}

int busca(Lista* l, TipoItem x) {
    int pos = 0;
    while (l != NULL) {
        if (l->info == x) return pos;
        l = l->prox;
        pos++;
    }
    return -1;
}

void FLVazia(Lista** l) {
    Lista* p = *l;
    while (p != NULL) {
        Lista* temp = p;
        p = p->prox;
        free(temp);
    }
    *l = NULL;
}

void imprime(Lista* l) {
    if (vazia(l)) {
        printf("Lista vazia\n");
        return;
    }
    Lista* p = l;
    printf("[ ");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("]\n");
}

void ordenar(Lista** l) {
    if (*l == NULL || (*l)->prox == NULL) return;

    int trocou;
    do {
        trocou = 0;
        Lista* atual = *l;
        while (atual->prox != NULL) {
            if (atual->info > atual->prox->info) {
                TipoItem tmp = atual->info;
                atual->info = atual->prox->info;
                atual->prox->info = tmp;
                trocou = 1;
            }
            atual = atual->prox;
        }
    } while (trocou);
}

void concatenar(Lista** l1, Lista* l2) {
    if (*l1 == NULL) {
        *l1 = l2;
        return;
    }
    Lista* p = *l1;
    while (p->prox != NULL)
        p = p->prox;
    p->prox = l2;
}

