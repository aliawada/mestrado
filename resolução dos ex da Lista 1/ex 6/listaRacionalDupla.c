#include "listaRacionalDupla.h"

ListaRacional* cria_lista() {
    ListaRacional* l = (ListaRacional*)malloc(sizeof(ListaRacional));
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

int vazia(ListaRacional* l) {
    return l->inicio == NULL;
}

void FLVazia(ListaRacional* l) {
    No* p = l->inicio;
    while (p != NULL) {
        No* temp = p;
        p = p->prox;
        limpar(temp->info); // limpa o RACIONAL alocado
        free(temp);
    }
    l->inicio = l->fim = NULL;
}

void inserir_inicio(ListaRacional* l, RACIONAL* r) {
    No* novo = (No*)malloc(sizeof(No));
    novo->info = r;
    novo->ant = NULL;
    novo->prox = l->inicio;

    if (vazia(l))
        l->fim = novo;
    else
        l->inicio->ant = novo;

    l->inicio = novo;
}

void inserir_fim(ListaRacional* l, RACIONAL* r) {
    No* novo = (No*)malloc(sizeof(No));
    novo->info = r;
    novo->prox = NULL;
    novo->ant = l->fim;

    if (vazia(l))
        l->inicio = novo;
    else
        l->fim->prox = novo;

    l->fim = novo;
}

void inserep(ListaRacional* l, int p, RACIONAL* r) {
    if (p <= 0 || vazia(l)) {
        inserir_inicio(l, r);
        return;
    }

    No* atual = l->inicio;
    int i = 0;

    while (i < p - 1 && atual->prox != NULL) {
        atual = atual->prox;
        i++;
    }

    if (atual == l->fim) {
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
    No* p = l->inicio;
    while (p != NULL) {
        if (p->info->num == r->num && p->info->den == r->den)
            break;
        p = p->prox;
    }

    if (p == NULL) return;

    if (p->ant != NULL)
        p->ant->prox = p->prox;
    else
        l->inicio = p->prox;

    if (p->prox != NULL)
        p->prox->ant = p->ant;
    else
        l->fim = p->ant;

    limpar(p->info);
    free(p);
}

void retira_pos(ListaRacional* l, int pos, RACIONAL** r_out) {
    No* p = l->inicio;
    int i = 0;

    while (p != NULL && i < pos) {
        p = p->prox;
        i++;
    }

    if (p == NULL) return;

    *r_out = p->info;

    if (p->ant != NULL)
        p->ant->prox = p->prox;
    else
        l->inicio = p->prox;

    if (p->prox != NULL)
        p->prox->ant = p->ant;
    else
        l->fim = p->ant;

    free(p);
}

int busca(ListaRacional* l, RACIONAL* r) {
    No* p = l->inicio;
    int i = 0;
    while (p != NULL) {
        if (p->info->num == r->num && p->info->den == r->den)
            return i;
        p = p->prox;
        i++;
    }
    return -1;
}

RACIONAL* soma_elementos(ListaRacional* l, int p1, int p2) {
    No* a = l->inicio;
    No* b = l->inicio;
    int i = 0;
    while (a != NULL && i < p1) { a = a->prox; i++; }
    i = 0;
    while (b != NULL && i < p2) { b = b->prox; i++; }

    if (a == NULL || b == NULL) return NULL;
    return adicao(a->info, b->info);
}

RACIONAL* multiplica_elementos(ListaRacional* l, int p1, int p2) {
    No* a = l->inicio;
    No* b = l->inicio;
    int i = 0;
    while (a != NULL && i < p1) { a = a->prox; i++; }
    i = 0;
    while (b != NULL && i < p2) { b = b->prox; i++; }

    if (a == NULL || b == NULL) return NULL;
    return multiplicacao(a->info, b->info);
}

void imprime_lista(ListaRacional* l) {
    No* p = l->inicio;
    printf("[ ");
    while (p != NULL) {
        imprimir(p->info);
        printf(" ");
        p = p->prox;
    }
    printf("]\n");
}

