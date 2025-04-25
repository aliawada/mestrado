#include "listaCircular.h"

Lista* cria_lista_vazia() {
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if (!l) return NULL;
    l->ultimo = NULL;
    return l;
}

int vazia(Lista* l) {
    return l->ultimo == NULL;
}

void inserir_inicio(Lista* l, TipoItem x) {
    No* novo = (No*)malloc(sizeof(No));
    novo->info = x;

    if (vazia(l)) {
        novo->prox = novo;
        l->ultimo = novo;
    } else {
        novo->prox = l->ultimo->prox;
        l->ultimo->prox = novo;
    }
}

void inserir_fim(Lista* l, TipoItem x) {
    No* novo = (No*)malloc(sizeof(No));
    novo->info = x;

    if (vazia(l)) {
        novo->prox = novo;
        l->ultimo = novo;
    } else {
        novo->prox = l->ultimo->prox;
        l->ultimo->prox = novo;
        l->ultimo = novo;
    }
}

void inserep(Lista* l, int p, TipoItem x) {
    if (p <= 0 || vazia(l)) {
        inserir_inicio(l, x);
        return;
    }

    No* atual = l->ultimo->prox;
    int i = 0;

    while (i < p - 1 && atual != l->ultimo) {
        atual = atual->prox;
        i++;
    }

    No* novo = (No*)malloc(sizeof(No));
    novo->info = x;
    novo->prox = atual->prox;
    atual->prox = novo;

    if (atual == l->ultimo) {
        l->ultimo = novo;
    }
}

void retira(Lista* l, TipoItem x) {
    if (vazia(l)) return;

    No* atual = l->ultimo->prox;
    No* ant = l->ultimo;

    do {
        if (atual->info == x) {
            if (atual == ant) { // único nó
                free(atual);
                l->ultimo = NULL;
            } else {
                ant->prox = atual->prox;
                if (atual == l->ultimo)
                    l->ultimo = ant;
                free(atual);
            }
            return;
        }
        ant = atual;
        atual = atual->prox;
    } while (atual != l->ultimo->prox);
}

void retira_pos(Lista* l, int p, TipoItem* x) {
    if (vazia(l)) return;

    No* atual = l->ultimo->prox;
    No* ant = l->ultimo;
    int i = 0;

    while (i < p && atual != l->ultimo) {
        ant = atual;
        atual = atual->prox;
        i++;
    }

    if (i == p) {
        *x = atual->info;
        if (atual == ant) {
            free(atual);
            l->ultimo = NULL;
        } else {
            ant->prox = atual->prox;
            if (atual == l->ultimo)
                l->ultimo = ant;
            free(atual);
        }
    }
}

int busca(Lista* l, TipoItem x) {
    if (vazia(l)) return -1;

    No* p = l->ultimo->prox;
    int i = 0;

    do {
        if (p->info == x) return i;
        p = p->prox;
        i++;
    } while (p != l->ultimo->prox);

    return -1;
}

void FLVazia(Lista* l) {
    if (vazia(l)) return;

    No* atual = l->ultimo->prox;
    No* prox;

    do {
        prox = atual->prox;
        free(atual);
        atual = prox;
    } while (atual != l->ultimo->prox);

    l->ultimo = NULL;
}

void imprime(Lista* l) {
    if (vazia(l)) {
        printf("Lista vazia\n");
        return;
    }

    No* p = l->ultimo->prox;
    printf("[ ");
    do {
        printf("%d ", p->info);
        p = p->prox;
    } while (p != l->ultimo->prox);
    printf("]\n");
}

void ordenar(Lista* l) {
    if (vazia(l) || l->ultimo->prox == l->ultimo) return;

    int trocou;
    do {
        trocou = 0;
        No* p = l->ultimo->prox;

        do {
            No* next = p->prox;
            if (next != l->ultimo->prox && p->info > next->info) {
                TipoItem temp = p->info;
                p->info = next->info;
                next->info = temp;
                trocou = 1;
            }
            p = p->prox;
        } while (p != l->ultimo);
    } while (trocou);
}

void concatenar(Lista* l1, Lista* l2) {
    if (vazia(l2)) return;

    if (vazia(l1)) {
        l1->ultimo = l2->ultimo;
    } else {
        No* inicio1 = l1->ultimo->prox;
        No* inicio2 = l2->ultimo->prox;

        l1->ultimo->prox = inicio2;
        l2->ultimo->prox = inicio1;
        l1->ultimo = l2->ultimo;
    }

    free(l2);
}

