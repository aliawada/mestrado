#ifndef LISTA_ENCADEADA_SIMPLES_H
#define LISTA_ENCADEADA_SIMPLES_H

#include <stdlib.h>
#include <stdio.h>

typedef int TipoItem;

typedef struct no {
    TipoItem info;
    struct no* prox;
} No;

typedef No Lista;

Lista* cria_lista_vazia();
int vazia(Lista* l);
Lista* inserir_inicio(Lista* l, TipoItem x);
Lista* inserir_fim(Lista* l, TipoItem x);
Lista* inserep(Lista* l, int p, TipoItem x);
Lista* retira(Lista* l, TipoItem x);
Lista* retira_pos(Lista* l, int p, TipoItem* x);
int busca(Lista* l, TipoItem x);
void FLVazia(Lista** l);
void imprime(Lista* l);
void ordenar(Lista** l);
void concatenar(Lista** l1, Lista* l2);

#endif

