#ifndef FILA_ENCADEADA_H
#define FILA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>

typedef int TipoItem;

struct no {
	TipoItem info;
	struct no* prox;
};

typedef struct {
	struct no* inicio;
	struct no* fim;
} Fila;

Fila* cria_fila_vazia();
int vazia(Fila* f);
void enqueue(Fila* f, TipoItem x);
TipoItem* dequeue(Fila* f);
void imprimir_fila(Fila* f);

#endif
