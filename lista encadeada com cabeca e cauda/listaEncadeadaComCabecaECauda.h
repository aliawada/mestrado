#ifndef LISTA_ENCADEADA_COM_CABECA_E_CAUSA_H
#define LISTA_ENCADEADA_COM_CABECA_E_CAUSA_H

#include <stdlib.h> // malloc, free
#include <stdio.h> // printf

typedef int TipoItem;

struct no { // estrutura de no para lista encadeada
	TipoItem info;
	struct no * prox;
};

typedef struct { // estrutura para lista encadeada com cabeca e cauda
	struct no* cabeca;
	struct no* cauda;
} Lista;

Lista* cria_lista_vazia();
int vazia(Lista* l);
Lista* insere(Lista* l, TipoItem info);
Lista * retira(Lista* l, TipoItem info);
void imprime(Lista* l);
void libera(Lista* l);

#endif
