#include "pilhaEncadeada.h"

Pilha* criar_pilha_vazia() {
	Pilha* aux = (Pilha*) malloc(sizeof(Pilha));
	aux->topo = NULL;
	return aux;
}

int vazia(Pilha* p) {
	return (p->topo == NULL);
}

// L^e o topo da pilha sem desempilhar
TipoItem* topo(Pilha* p) {
	if(!vazia(p)) {
		TipoItem* x = (TipoItem*) malloc(sizeof(TipoItem));
		*x = p->topo->info;
		return x;
	} else
		return NULL;
}

// Empilha um item
void push(Pilha* p, TipoItem x) {
	struct no* aux = (struct no*) malloc(sizeof(struct no));
	aux->info = x;
	aux->prox = p->topo;
	p->topo = aux;
}

//Desempilha um item
TipoItem* pop(Pilha* p) {
	if(!vazia(p)) {
		TipoItem* x = (TipoItem*) malloc(sizeof(TipoItem));
		struct no* aux = p->topo;
		*x = p->topo->info;
		p->topo = p->topo->prox;
		free(aux);
		return x;
	} else {
		printf("Pilha vazia!");
		return NULL;
	}
}
