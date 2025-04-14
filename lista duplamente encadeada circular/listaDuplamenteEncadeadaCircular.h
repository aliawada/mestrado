#ifndef LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H
#define LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H

#include <stdlib.h> // malloc, free
#include <stdio.h> // printf

typedef int TipoItem; // tipo dos elementos na lista

typedef struct no { //estrutura para lista duplamente encadeada circular
	TipoItem info;
	struct no * ant; // ponteiro para o elemento anterior
	struct no * prox; // ponteiro para proximo elemento
} Lista;

Lista* cria_lista_vazia();
int vazia(Lista* l);
Lista* insere(Lista* l, TipoItem info);
Lista * retira(Lista* l, TipoItem info);
void imprime(Lista* l);

#endif
