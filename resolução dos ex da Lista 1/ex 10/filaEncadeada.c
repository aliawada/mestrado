#include "filaEncadeada.h"

Fila* cria_fila_vazia() {
    Fila* f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int vazia(Fila* f) {
    return (f->inicio == NULL);
}

void enqueue(Fila* f, TipoItem x) {
    struct no* novo = malloc(sizeof(struct no));
    novo->info = x;
    novo->prox = NULL;
    if (vazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

TipoItem* dequeue_traseira(Fila* f) {
    if (vazia(f)) {
        return NULL;
    }
    // Remoção pelo mesmo fim: trajetoria de 1 elemento
    struct no* prev = NULL;
    struct no* cur = f->inicio;
    while (cur->prox != NULL) {
        prev = cur;
        cur = cur->prox;
    }
    // cur aponta ao nó final
    TipoItem* ret = malloc(sizeof(TipoItem));
    *ret = cur->info;
    if (prev == NULL) {
        // único elemento
        f->inicio = NULL;
        f->fim = NULL;
    } else {
        prev->prox = NULL;
        f->fim = prev;
    }
    free(cur);
    return ret;
}

void imprimir_fila(Fila* f) {
    printf("Fila (parte traseira removida): ");
    struct no* p = f->inicio;
    while (p) {
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}

void libera_fila(Fila* f) {
    TipoItem* tmp;
    while ((tmp = dequeue_traseira(f)) != NULL) {
        free(tmp);
    }
    free(f);
}
