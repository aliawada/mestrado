#include "listaRacionalDuplaSentinela.h"

ListaRacional* cria_lista() {
    ListaRacional* l = (ListaRacional*)malloc(sizeof(ListaRacional));
    l->sentinela = (No*)malloc(sizeof(No));
    l->sentinela->prox = l->sentinela;
    l->sentinela->ant = l->sentinela;
    l->sentinela->info = NULL;
    return l;
}

int vazia(ListaRacional* l) {
    return l->sentinela->prox == l->sentinela;
}

void FLVazia(ListaRacional* l) {
    No* p = l->sentinela->prox;
    while (p != l->sentinela) {
        No* temp = p;
        p = p->prox;
        limpar(temp->info);
        free(temp);
    }
    l->sentinela->prox = l->sentinela;
    l->sentinela->ant = l->sentinela;
}

void inserir_inicio(ListaRacional* l, RACIONAL* r) {
    No* novo = (No*)malloc(sizeof(No));
    novo->info = r;

    novo->prox = l->sentinela->prox;
    novo->ant = l->sentinela;

    l->sentinela->prox->ant = novo;
    l->sentinela->prox = novo;
}

void inserir_fim(ListaRacional* l, RACIONAL* r) {
    No* novo = (No*)malloc(sizeof(No));
    novo->info = r;

    novo->prox = l->sentinela;
    novo->ant = l->sentinela->ant;

    l->sentinela->ant->prox = novo;
    l->sentinela->ant = novo;
}

void inserep(ListaRacional* l, int p, RACIONAL* r) {
    No* atual = l->sentinela->prox;
    int i = 0;

    while (atual != l->sentinela && i < p) {
        atual = atual->prox;
        i++;
    }

    No* novo = (No*)malloc(sizeof(No));
    novo->info = r;
    novo->prox = atual;
    novo->ant = atual->ant;

    atual->ant->prox = novo;
    atual->ant = novo;
}

void retira(ListaRacional* l, RACIONAL* r) {
    No* p = l->sentinela->prox;
    while (p != l->sentinela) {
        if (p->info->num == r->num && p->info->den == r->den)
            break;
        p = p->prox;
    }

    if (p == l->sentinela) return;

    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    limpar(p->info);
    free(p);
}

void retira_pos(ListaRacional* l, int pos, RACIONAL** r_out) {
    No* p = l->sentinela->prox;
    int i = 0;

    while (p != l->sentinela && i < pos) {
        p = p->prox;
        i++;
    }

    if (p == l->sentinela) return;

    *r_out = p->info;

    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    free(p);
}

int busca(ListaRacional* l, RACIONAL* r) {
    No* p = l->sentinela->prox;
    int i = 0;
    while (p != l->sentinela) {
        if (p->info->num == r->num && p->info->den == r->den)
            return i;
        p = p->prox;
        i++;
    }
    return -1;
}

RACIONAL* soma_elementos(ListaRacional* l, int p1, int p2) {
    No* a = l->sentinela->prox;
    No* b = l->sentinela->prox;
    int i = 0;
    while (a != l->sentinela && i < p1) { a = a->prox; i++; }
    i = 0;
    while (b != l->sentinela && i < p2) { b = b->prox; i++; }

    if (a == l->sentinela || b == l->sentinela) return NULL;
    return adicao(a->info, b->info);
}

RACIONAL* multiplica_elementos(ListaRacional* l, int p1, int p2) {
    No* a = l->sentinela->prox;
    No* b = l->sentinela->prox;
    int i = 0;
    while (a != l->sentinela && i < p1) { a = a->prox; i++; }
    i = 0;
    while (b != l->sentinela && i < p2) { b = b->prox; i++; }

    if (a == l->sentinela || b == l->sentinela) return NULL;
    return multiplicacao(a->info, b->info);
}

void imprime_lista(ListaRacional* l) {
    No* p = l->sentinela->prox;
    printf("[ ");
    while (p != l->sentinela) {
        imprimir(p->info);
        printf(" ");
        p = p->prox;
    }
    printf("]\n");
}

