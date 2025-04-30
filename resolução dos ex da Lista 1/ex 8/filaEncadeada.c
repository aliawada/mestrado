// filaEncadeada.c
#include "filaEncadeada.h"

FilaEncadeada* cria_fila_encadeada_vazia() {
    FilaEncadeada* f = malloc(sizeof(FilaEncadeada));
    f->inicio = f->fim = NULL;
    return f;
}

int vazia_encadeada(FilaEncadeada* f) {
    return (f->inicio == NULL);
}

void enqueue_encadeada(FilaEncadeada* f, TipoItem x) {
    struct no* aux = malloc(sizeof(*aux));
    aux->info = x;
    aux->prox = NULL;
    if (vazia_encadeada(f)) {
        f->inicio = aux;
    } else {
        f->fim->prox = aux;
    }
    f->fim = aux;
}

TipoItem* dequeue_encadeada(FilaEncadeada* f) {
    if (vazia_encadeada(f)) return NULL;
    TipoItem* ret = malloc(sizeof(*ret));
    struct no* aux = f->inicio;
    *ret = aux->info;
    if (f->inicio == f->fim) {
        f->fim = NULL;
    }
    f->inicio = aux->prox;
    free(aux);
    return ret;
}

void imprimir_fila_encadeada(FilaEncadeada* f) {
    struct no* p; 
    printf("Fila encadeada: ");
    for (p = f->inicio; p != NULL; p = p->prox) {
        printf("%d ", p->info);
    }
    printf("\n");
}

