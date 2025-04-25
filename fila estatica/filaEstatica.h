#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

#define TAM_MAX 1000 // numero maximo de itens na fila

#include <stdlib.h>
#include <stdio.h>
 
typedef int TipoItem;
 
// estrutura para fila usando vetor
typedef struct {
	TipoItem vet[TAM_MAX];
	int inicio, fim; // ndices do incio e fim da fila
} Fila;

Fila* cria_fila_vazia();
int vazia(Fila* f);
int cheia(Fila* f);
void enqueue(Fila* f, TipoItem x);
TipoItem* dequeue(Fila * f);
TipoItem* dequeue(Fila * f);
void imprime_fila(Fila* f);

#endif
