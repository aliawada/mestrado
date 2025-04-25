#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include <stdlib.h>
#include <stdio.h>

typedef int TipoItem;

typedef struct no {
    TipoItem info;
    struct no* prox;
} No;

typedef struct {
    No* ultimo; // ponteiro para o último nó
} Lista;

// Criação e verificação
Lista* cria_lista_vazia();
int vazia(Lista* l);
void FLVazia(Lista* l);

// Inserção e remoção
void inserir_inicio(Lista* l, TipoItem x);
void inserir_fim(Lista* l, TipoItem x);
void inserep(Lista* l, int p, TipoItem x);
void retira(Lista* l, TipoItem x);
void retira_pos(Lista* l, int p, TipoItem* x);

// Busca, ordenação e concatenação
int busca(Lista* l, TipoItem x);
void ordenar(Lista* l);
void concatenar(Lista* l1, Lista* l2);

// Exibição
void imprime(Lista* l);

#endif

