#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#define TAM_MAX 1000 // numero maximo de itens na lista
#include <stdlib.h> // Necessário para malloc
#include <stdio.h>  // Necessário para printf

typedef int TipoItem;

// estrutura para lista estatica
typedef struct {
    TipoItem item[TAM_MAX];
    int pos_livre;
} Lista;

//Cria uma lista vazia
Lista* cria_lista_vazia();

//Testa se uma lista  ´e vazia
int vazia(Lista * l);

//Insere um item na lista
void insere(Lista* l, TipoItem x);

//Retira o item da lista
void retira(Lista* l, TipoItem x);

//Imprime os itens da lista
void imprime(Lista* l);

#endif // LISTA_ESTATICA_H
