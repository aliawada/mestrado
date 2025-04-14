#ifndef LISTA_ENCADEADA_SIMPLES_H
#define LISTA_ENCADEADA_SIMPLES_H

#include <stdlib.h> // Necessário para malloc, free
#include <stdio.h>  // Necessário para printf
 
typedef int TipoItem; // tipo dos elementos na lista
 
typedef struct no { //estrutura para lista encadeada
	TipoItem info;
	struct no * prox; // ponteiro para proximo elemento
} Lista;

Lista* cria_lista_vazia();

int vazia(Lista* l);

Lista* insere(Lista* l, TipoItem info);

Lista * retira(Lista* l, TipoItem info);

void imprime(Lista* l);

#endif
