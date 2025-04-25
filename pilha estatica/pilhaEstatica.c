#include "pilhaEstatica.h"

Pilha* criar_pilha_vazia(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = 0;
	return p;
}

int vazia(Pilha * p) {
	return (p->topo == 0);
}

int cheia(Pilha* p) {
	return (p->topo == TAM_MAX);
}

//Empilha um elemento
void push(Pilha* p, TipoItem x) {
	if(!cheia(p)){
		p->vet[p->topo++] = x;
	}
	else printf("Pilha cheia!");
}

//Desempilha um elemento
TipoItem* pop(Pilha* p) {
	if(!vazia(p)){
		TipoItem* aux = (TipoItem*) malloc(sizeof(TipoItem));
		p->topo--;
		*aux = p->vet[p->topo];
		return aux;
	} else {
		printf("Pilha vazia!"); 
		return NULL;
	}
}
