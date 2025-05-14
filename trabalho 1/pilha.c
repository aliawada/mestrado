#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializarPilha(Pilha* p) {
    p->topo = NULL;
}

void empilhar(Pilha* p, Item item) {
    NoPilha* novo = (NoPilha*) malloc(sizeof(NoPilha));
    novo->item = item;
    novo->prox = p->topo;
    p->topo = novo;
}

Item desempilhar(Pilha* p) {
    Item vazio = {0};
    if (p->topo == NULL) return vazio;
    NoPilha* temp = p->topo;
    Item item = temp->item;
    p->topo = p->topo->prox;
    free(temp);
    return item;
}

int pilhaVazia(Pilha* p) {
    return p->topo == NULL;
}

void imprimirPilha(Pilha* p) {
    NoPilha* atual = p->topo;
    while (atual) {
        printf("%d - %s - %s - %s - Tam: %d\n", atual->item.codigo, atual->item.tipo, atual->item.marca, atual->item.cor, atual->item.tamanho);
        atual = atual->prox;
    }
}
