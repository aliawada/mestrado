#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializarFila(Fila* f) {
    f->inicio = f->fim = NULL;
}

void enfileirar(Fila* f, Cliente c) {
    NoFila* novo = (NoFila*) malloc(sizeof(NoFila));
    novo->cliente = c;
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

Cliente desenfileirar(Fila* f) {
    Cliente vazio = {""};
    if (f->inicio == NULL) return vazio;
    NoFila* temp = f->inicio;
    Cliente cliente = temp->cliente;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) f->fim = NULL;
    free(temp);
    return cliente;
}

int filaVazia(Fila* f) {
    return f->inicio == NULL;
}

void imprimirFila(Fila* f) {
    NoFila* atual = f->inicio;
    printf("Fila de Espera:\n");
    while (atual) {
        printf("CPF: %s\n", atual->cliente.cpf);
        atual = atual->prox;
    }
}
