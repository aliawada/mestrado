#ifndef LISTA_ENCADEADA_COM_NO_H
#define LISTA_ENCADEADA_COM_NO_H

#include <stdlib.h>
#include <stdio.h>

typedef int TipoItem;

typedef struct no {
    TipoItem info;
    struct no* prox;
} No;

typedef struct {
    No* sentinela; // ponteiro para o nó sentinela
} Lista;

Lista* cria_lista_vazia();
int vazia(Lista* l);
void inserir_inicio(Lista* l, TipoItem x);
void inserir_fim(Lista* l, TipoItem x);
void inserep(Lista* l, int p, TipoItem x);
void retira(Lista* l, TipoItem x);
void retira_pos(Lista* l, int p, TipoItem* x);
int busca(Lista* l, TipoItem x);
void FLVazia(Lista* l);
void imprime(Lista* l);
void ordenar(Lista* l);
void concatenar(Lista* l1, Lista* l2);

#endif

