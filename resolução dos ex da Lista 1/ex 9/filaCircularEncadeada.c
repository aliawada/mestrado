#include "filaCircularEncadeada.h"

FilaCircularEncadeada* cria_fila_circular_encadeada_vazia() {
    FilaCircularEncadeada* f = malloc(sizeof(FilaCircularEncadeada));
    f->fim = NULL;
    return f;
}

int vazia_circular_encadeada(FilaCircularEncadeada* f) {
    return (f->fim == NULL);
}

void enqueue_circular_encadeada(FilaCircularEncadeada* f, TipoItem x) {
    struct no* novo = malloc(sizeof(struct no));
    novo->info = x;
    if (vazia_circular_encadeada(f)) {
        novo->prox = novo;
        f->fim = novo;
    } else {
        novo->prox = f->fim->prox;
        f->fim->prox = novo;
        f->fim = novo;
    }
}

TipoItem* dequeue_circular_encadeada(FilaCircularEncadeada* f) {
    if (vazia_circular_encadeada(f)) return NULL;
    struct no* primeiro = f->fim->prox;
    TipoItem* ret = malloc(sizeof(TipoItem));
    *ret = primeiro->info;
    if (primeiro == f->fim) {
        f->fim = NULL;
    } else {
        f->fim->prox = primeiro->prox;
    }
    free(primeiro);
    return ret;
}

void imprimir_fila_circular_encadeada(FilaCircularEncadeada* f) {
    if (vazia_circular_encadeada(f)) {
        printf("Fila circular encadeada vazia.\n");
        return;
    }
    printf("Fila circular encadeada: ");
    struct no* p = f->fim->prox;
    do {
        printf("%d ", p->info);
        p = p->prox;
    } while (p != f->fim->prox);
    printf("\n");
}

