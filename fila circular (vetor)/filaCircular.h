#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#define TAM_MAX 1000

#include <stdlib.h>
#include <stdio.h>

typedef int TipoItem;

typedef struct {
    TipoItem vet[TAM_MAX];
    int inicio, fim;
} Fila;

Fila* criarFila();
int vazia(Fila* f);
int cheia(Fila* f);
void enqueue(Fila* f, TipoItem x);
TipoItem* dequeue(Fila * f);
void imprimirFila(Fila* f);

#endif
