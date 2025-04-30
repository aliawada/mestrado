#ifndef PILHA_ESTATICA_H
#define PILHA_ESTATICA_H

#include "pilha.h"

#define TAM_MAX 1000

typedef struct {
    TipoItem vet[TAM_MAX];
    int topo;
} PilhaEstatica;

PilhaEstatica* criar_pilha_estatica();
void FPVazia_estatica(PilhaEstatica* p);
int vazia_estatica(PilhaEstatica* p);
int cheia_estatica(PilhaEstatica* p);
void push_estatica(PilhaEstatica* p, TipoItem x);
TipoItem* pop_estatica(PilhaEstatica* p);
TipoItem* topo_estatica(PilhaEstatica* p);
int tamanho_estatica(PilhaEstatica* p);

#endif

