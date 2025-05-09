#include "pilhaEstatica.h"

PilhaEstatica* criar_pilha_estatica() {
    PilhaEstatica* p = (PilhaEstatica*) malloc(sizeof(PilhaEstatica));
    p->topo = 0;
    return p;
}

void FPVazia_estatica(PilhaEstatica* p) {
    p->topo = 0;
}

int vazia_estatica(PilhaEstatica* p) {
    return (p->topo == 0);
}

int cheia_estatica(PilhaEstatica* p) {
    return (p->topo == TAM_MAX);
}

void push_estatica(PilhaEstatica* p, TipoItem x) {
    if (!cheia_estatica(p)) {
        p->vet[p->topo++] = x;
    } else {
        printf("Pilha cheia!\n");
    }
}

TipoItem* pop_estatica(PilhaEstatica* p) {
    if (!vazia_estatica(p)) {
        TipoItem* aux = (TipoItem*) malloc(sizeof(TipoItem));
        *aux = p->vet[--(p->topo)];
        return aux;
    } else {
        printf("Pilha vazia!\n");
        return NULL;
    }
}

TipoItem* topo_estatica(PilhaEstatica* p) {
    if (!vazia_estatica(p)) {
        TipoItem* aux = (TipoItem*) malloc(sizeof(TipoItem));
        *aux = p->vet[p->topo - 1];
        return aux;
    } else {
        return NULL;
    }
}

int tamanho_estatica(PilhaEstatica* p) {
    return p->topo;
}

