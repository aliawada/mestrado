// filaEncadeada.h
#ifndef FILA_ENCADEADA_H
#define FILA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>

typedef int TipoItem;

// nó da fila encadeada
struct no {
    TipoItem info;
    struct no* prox;
};

// novo nome para evitar colisão
typedef struct {
    struct no* inicio;
    struct no* fim;
} FilaEncadeada;

// protótipos renomeados
FilaEncadeada* cria_fila_encadeada_vazia();
int vazia_encadeada(FilaEncadeada* f);
void enqueue_encadeada(FilaEncadeada* f, TipoItem x);
TipoItem* dequeue_encadeada(FilaEncadeada* f);
void imprimir_fila_encadeada(FilaEncadeada* f);

#endif

