#include "listaRacionalDuplaCircular.h"

ListaRacional* cria_lista() {
    ListaRacional* l = (ListaRacional*)malloc(sizeof(ListaRacional));
    l->inicio = NULL;
    return l;
}

int vazia(ListaRacional* l) {
    return l->inicio == NULL;
}

void FLVazia(ListaRacional* l) {
    if (vazia(l)) return;

    No* p = l->inicio;
    do {
        No* temp = p;
        p = p->prox;
        limpar(temp->info);
        free(temp);
    } while (p != l->inicio);

    l->inicio = NULL;
}

void inserir_inicio(ListaRacional* l, RACIONAL* r) {
    No* novo = (No*)malloc(sizeof(No));
    novo->info = r;

    if (vazia(l)) {
        novo->prox = novo->ant = novo;
        l->inicio = novo;
    } else {
        No* ult = l->inicio->ant;
        novo->prox = l->inicio;
        novo->ant = ult;
        ult->prox = novo;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
}

void inserir_fim(ListaRacional* l, RACIONAL* r) {
    if (vazia(l)) {
        inserir_inicio(l, r);
        return;
    }

    No* novo = (No*)malloc(sizeof(No));
    novo->info = r;

    No* ult = l->inicio->ant;

    novo->prox = l->inicio;
    novo->ant = ult;

    ult->prox = novo;
    l->inicio->ant = novo;
}

void inserep(ListaRacional* l, int p, RACIONAL* r) {
    if (p <= 0 || vazia(l)) {
        inserir_inicio(l, r);
        return;
    }

    No* atual = l->inicio;
    int i = 0;

    while (i < p && atual->prox != l->inicio) {
        atual = atual->prox;
        i++;
    }

    if (atual->prox == l->inicio && i < p) {
        inserir_fim(l, r);
        return;
    }

    No* novo = (No*)malloc(sizeof(No));
    novo->info = r;

    novo->prox = atual->prox;
    novo->ant = atual;

    atual->prox->ant = novo;
    atual->prox = novo;
}

void retira(ListaRacional* l, RACIONAL* r) {
    if (vazia(l)) return;

    No* p = l->inicio;
    do {
        if (p->info->num == r->num && p->info->den == r->den) break;
        p = p->prox;
    } while (p != l->inicio);

    if (p->info->num != r->num || p->info->den != r->den) return;

    if (p == p->prox) { // único elemento
        limpar(p->info);
        free(p);
        l->inicio = NULL;
        return;
    }

    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    if (p == l->inicio)
        l->inicio = p->prox;

    limpar(p->info);
    free(p);
}

void retira_pos(ListaRacional* l, int pos, RACIONAL** r_out) {
    if (vazia(l)) return;

    No* p = l->inicio;
    int i = 0;
    while (i < pos && p->prox != l->inicio) {
        p = p->prox;
        i++;
    }

    if (i != pos) return;

    *r_out = p->info;

    if (p == p->prox) {
        free(p);
        l->inicio = NULL;
        return;
    }

    p->ant->prox = p->prox;
    p->prox->ant = p->ant;

    if (p == l->inicio)
        l->inicio = p->prox;

    free(p);
}

int busca(ListaRacional* l, RACIONAL* r) {
    if (vazia(l)) return -1;

    No* p = l->inicio;
    int i = 0;
    do {
        if (p->info->num == r->num && p->info->den == r->den)
            return i;
        p = p->prox;
        i++;
    } while (p != l->inicio);

    return -1;
}

RACIONAL* soma_elementos(ListaRacional* l, int p1, int p2) {
    if (vazia(l)) return NULL;

    No* a = l->inicio;
    No* b = l->inicio;
    int i = 0;

    while (a->prox != l->inicio && i < p1) { a = a->prox; i++; }
    i = 0;
    while (b->prox != l->inicio && i < p2) { b = b->prox; i++; }

    return adicao(a->info, b->info);
}

RACIONAL* multiplica_elementos(ListaRacional* l, int p1, int p2) {
    if (vazia(l)) return NULL;

    No* a = l->inicio;
    No* b = l->inicio;
    int i = 0;

    while (a->prox != l->inicio && i < p1) { a = a->prox; i++; }
    i = 0;
    while (b->prox != l->inicio && i < p2) { b = b->prox; i++; }

    return multiplicacao(a->info, b->info);
}

void imprime_lista(ListaRacional* l) {
    if (vazia(l)) {
        printf("[ ]\n");
        return;
    }

    No* p = l->inicio;
    printf("[ ");
    do {
        imprimir(p->info);
        printf(" ");
        p = p->prox;
    } while (p != l->inicio);
    printf("]\n");
}

