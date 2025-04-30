#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

#define TAM_MAX 1000 // número máximo de itens na fila estática

#include <stdlib.h>
#include <stdio.h>

typedef int TipoItem;

// Estrutura da fila estática
typedef struct {
    TipoItem vet[TAM_MAX];
    int inicio, fim;
} FilaEstatica;

// Protótipos renomeados para evitar colisões
FilaEstatica* cria_fila_estatica_vazia();
int vazia_estatica(FilaEstatica* f);
int cheia_estatica(FilaEstatica* f);
void enqueue_estatica(FilaEstatica* f, TipoItem x);
TipoItem* dequeue_estatica(FilaEstatica* f);
void imprimir_fila_estatica(FilaEstatica* f);

#endif
