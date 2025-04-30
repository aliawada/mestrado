#ifndef FILA_CIRCULAR_ENCADEADA_H
#define FILA_CIRCULAR_ENCADEADA_H

#include <stdlib.h>
#include <stdio.h>

typedef int TipoItem;

// nó para fila encadeada circular
struct no {
    TipoItem info;
    struct no* prox;
};

// Fila Encadeada Circular: guarda ponteiro para o último nó
typedef struct {
    struct no* fim;
} FilaCircularEncadeada;

FilaCircularEncadeada* cria_fila_circular_encadeada_vazia();
int vazia_circular_encadeada(FilaCircularEncadeada* f);
void enqueue_circular_encadeada(FilaCircularEncadeada* f, TipoItem x);
TipoItem* dequeue_circular_encadeada(FilaCircularEncadeada* f);
void imprimir_fila_circular_encadeada(FilaCircularEncadeada* f);

#endif
