#ifndef LISTA_ESTATICA_2_H
#define LISTA_ESTATICA_2_H

#define TAM_MAX 1000
#include <stdlib.h>
#include <stdio.h>

typedef int TipoItem;

typedef struct {
    TipoItem item[TAM_MAX];
    int primeiro, ultimo;
    int pos;
} Lista;

Lista* cria_lista_vazia();
int vazia(Lista* l);
void insere(Lista* l, TipoItem x);
void retira(Lista* l, TipoItem x);
void imprime(Lista* l);
void imprime2(Lista* l);
TipoItem primeiro(Lista* l);
TipoItem proximo(Lista* l);

void inserir_inicio(Lista* l, TipoItem x);
int busca(Lista* l, TipoItem x);
void FLVazia(Lista* l);
void inserep(Lista* l, int p, TipoItem x);
TipoItem retira_pos(Lista* l, int p);
void ordenar(Lista* l);
void concatenar(Lista* l1, Lista* l2);

#endif // LISTA_ESTATICA_2_H

