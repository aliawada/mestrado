#include "filaEstatica.h"

FilaEstatica* cria_fila_estatica_vazia() {
    FilaEstatica* f = malloc(sizeof(FilaEstatica));
    f->inicio = 0;
    f->fim = 0;
    return f;
}

int vazia_estatica(FilaEstatica* f) {
    return (f->inicio == f->fim);
}

int cheia_estatica(FilaEstatica* f) {
    return (f->fim >= TAM_MAX);
}

void enqueue_estatica(FilaEstatica* f, TipoItem x) {
    if (!cheia_estatica(f)) {
        f->vet[f->fim++] = x;
    } else {
        printf("Fila estatica cheia!\n");
    }
}

TipoItem* dequeue_estatica(FilaEstatica* f) {
    if (!vazia_estatica(f)) {
        TipoItem* aux = malloc(sizeof(TipoItem));
        *aux = f->vet[f->inicio++];
        return aux;
    } else {
        printf("Fila estatica vazia!\n");
        return NULL;
    }
}

void imprimir_fila_estatica(FilaEstatica* f) {
    if (vazia_estatica(f)) {
        printf("Fila estatica vazia.\n");
        return;
    }
    printf("Fila estatica: ");
    int i;
    for (i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->vet[i]);
    }
    printf("\n");
}
