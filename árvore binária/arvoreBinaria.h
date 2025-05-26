#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no* esq;
    struct no* dir;
};

typedef struct no* arvore;

arvore* cria_arvore_vazia();
int vazia(arvore r);
void in_ordem(arvore r);
void pre_ordem(arvore r);
void pos_ordem(arvore r);
int contar_elementos(arvore r);
int soma_elementos(arvore r);
int maximo(arvore r);
int minimo(arvore r);
arvore insere_arvore_binaria(arvore r, int x);
arvore remove_arvore_binaria(arvore r, int x);
arvore busca_arvore_binaria(arvore r, int x);
void libera_arvore(arvore r);

#endif

