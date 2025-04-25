#ifndef PILHA_ESTATICA_H
#define PILHA_ESTATICA_H

#define TAM_MAX 1000

#include <stdlib.h>
#include <stdio.h>

typedef int TipoItem;

typedef struct {
	TipoItem vet[TAM_MAX];
	int topo;
} Pilha;

Pilha* criar_pilha_vazia();
int vazia(Pilha * p);
int cheia(Pilha* p);
void push(Pilha* p, TipoItem x);
TipoItem* pop(Pilha* p);

#endif
