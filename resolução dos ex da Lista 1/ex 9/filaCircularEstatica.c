#include "filaCircularEstatica.h"

FilaCircularEstatica* cria_fila_circular_estatica() {
    FilaCircularEstatica* f = malloc(sizeof(FilaCircularEstatica));
    f->inicio = 0;
    f->fim = 0;
    return f;
}

int vazia_circular_estatica(FilaCircularEstatica* f) {
    return (f->inicio == f->fim);
}

int cheia_circular_estatica(FilaCircularEstatica* f) {
    return ((f->fim + 1) % TAM_MAX == f->inicio);
}

void enqueue_circular_estatica(FilaCircularEstatica* f, TipoItem x) {
    if (!cheia_circular_estatica(f)) {
        f->vet[f->fim] = x;
        f->fim = (f->fim + 1) % TAM_MAX;
    } else {
        printf("Fila circular estatica cheia!\n");
    }
}

TipoItem* dequeue_circular_estatica(FilaCircularEstatica* f) {
    if (!vazia_circular_estatica(f)) {
        TipoItem* ret = malloc(sizeof(TipoItem));
        *ret = f->vet[f->inicio];
        f->inicio = (f->inicio + 1) % TAM_MAX;
        return ret;
    } else {
        printf("Fila circular estatica vazia!\n");
        return NULL;
    }
}

void imprimir_fila_circular_estatica(FilaCircularEstatica* f) {
    printf("Fila circular estatica: ");
    int i = f->inicio;
    while (i != f->fim) {
        printf("%d ", f->vet[i]);
        i = (i + 1) % TAM_MAX;
    }
    printf("\n");
}
