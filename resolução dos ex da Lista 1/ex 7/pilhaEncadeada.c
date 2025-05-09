#include "pilhaEncadeada.h"

PilhaEncadeada* criar_pilha_encadeada() {
    PilhaEncadeada* aux = (PilhaEncadeada*) malloc(sizeof(PilhaEncadeada));
    aux->topo = NULL;
    return aux;
}

void FPVazia_encadeada(PilhaEncadeada* p) {
    while (!vazia_encadeada(p)) {
        No* aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
}

int vazia_encadeada(PilhaEncadeada* p) {
    return (p->topo == NULL);
}

TipoItem* topo_encadeada(PilhaEncadeada* p) {
    if (!vazia_encadeada(p)) {
        TipoItem* x = (TipoItem*) malloc(sizeof(TipoItem));
        *x = p->topo->info;
        return x;
    } else {
        return NULL;
    }
}

void push_encadeada(PilhaEncadeada* p, TipoItem x) {
    No* aux = (No*) malloc(sizeof(No));
    aux->info = x;
    aux->prox = p->topo;
    p->topo = aux;
}

TipoItem* pop_encadeada(PilhaEncadeada* p) {
    if (!vazia_encadeada(p)) {
        TipoItem* x = (TipoItem*) malloc(sizeof(TipoItem));
        No* aux = p->topo;
        *x = aux->info;
        p->topo = aux->prox;
        free(aux);
        return x;
    } else {
        printf("Pilha vazia!\n");
        return NULL;
    }
}

int tamanho_encadeada(PilhaEncadeada* p) {
    int count = 0;
    No* aux = p->topo;
    while (aux != NULL) {
        count++;
        aux = aux->prox;
    }
    return count;
}

