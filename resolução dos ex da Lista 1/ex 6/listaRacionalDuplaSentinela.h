#ifndef LISTA_RACIONAL_DUPLA_SENTINELA_H
#define LISTA_RACIONAL_DUPLA_SENTINELA_H

#include "racional.h"

typedef struct no {
    RACIONAL* info;
    struct no* ant;
    struct no* prox;
} No;

typedef struct {
    No* sentinela;
} ListaRacional;

// Criação e limpeza
ListaRacional* cria_lista();
int vazia(ListaRacional* l);
void FLVazia(ListaRacional* l);

// Inserção e remoção
void inserir_inicio(ListaRacional* l, RACIONAL* r);
void inserir_fim(ListaRacional* l, RACIONAL* r);
void inserep(ListaRacional* l, int p, RACIONAL* r);
void retira(ListaRacional* l, RACIONAL* r);
void retira_pos(ListaRacional* l, int p, RACIONAL** r_out);

// Busca
int busca(ListaRacional* l, RACIONAL* r);

// Operações entre elementos da lista
RACIONAL* soma_elementos(ListaRacional* l, int p1, int p2);
RACIONAL* multiplica_elementos(ListaRacional* l, int p1, int p2);

// Utilitários
void imprime_lista(ListaRacional* l);

#endif

