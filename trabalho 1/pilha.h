#ifndef PILHA_H
#define PILHA_H

#include "vestuario.h"

typedef struct NoPilha {
    Item item;
    struct NoPilha* prox;
} NoPilha;

typedef struct {
    NoPilha* topo;
} Pilha;

void inicializarPilha(Pilha* p);
void empilhar(Pilha* p, Item item);
Item desempilhar(Pilha* p);
int pilhaVazia(Pilha* p);
void imprimirPilha(Pilha* p);

#endif

