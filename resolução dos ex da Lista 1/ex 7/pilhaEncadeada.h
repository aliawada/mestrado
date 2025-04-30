#ifndef PILHA_ENCADEADA_H
#define PILHA_ENCADEADA_H

#include "pilha.h"

typedef struct no {
    TipoItem info;
    struct no* prox;
} No;

typedef struct {
    No* topo;
} PilhaEncadeada;

PilhaEncadeada* criar_pilha_encadeada();
void FPVazia_encadeada(PilhaEncadeada* p);
int vazia_encadeada(PilhaEncadeada* p);
void push_encadeada(PilhaEncadeada* p, TipoItem x);
TipoItem* pop_encadeada(PilhaEncadeada* p);
TipoItem* topo_encadeada(PilhaEncadeada* p);
int tamanho_encadeada(PilhaEncadeada* p);

#endif

