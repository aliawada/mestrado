#ifndef PILHA_ENCADEADA_H
#define PILHA_ENCADEADA_H

#include <stdlib.h>
#include <stdio.h>

typedef int TipoItem;

// estrutura para lista encadeada
struct no {
	TipoItem info; 
	struct no *prox; 
};

// estrutura de lista com cabeca
// para implementac~ ao de pilha
typedef struct {
	struct no* topo;
} Pilha;

Pilha* criar_pilha_vazia();
int vazia(Pilha* p);
TipoItem* topo(Pilha* p);
void push(Pilha* p, TipoItem x);
TipoItem* pop(Pilha* p);

#endif
