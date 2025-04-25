#include "filaEstatica.h"

Fila* cria_fila_vazia() {
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->inicio = 0;
	f->fim = 0;
	return f;
}

int vazia(Fila* f) {
	return (f->inicio == f->fim);
}

int cheia(Fila* f) {
	return (f->fim >= TAM_MAX);
}

// Enfileira um elemento
void enqueue(Fila* f, TipoItem x) {
	if(!cheia(f)){
		f->vet[f->fim] = x;
		f->fim++;
	} else {
		printf("Fila cheia!");
 	}
}

// Desenfileira um elemento
TipoItem* dequeue(Fila * f) {
	if(!vazia(f)) {
		TipoItem* aux = (TipoItem*) malloc(sizeof(TipoItem));
		*aux = f->vet[f->inicio++];
		return aux;
	} else {
		printf("Fila vazia!");
		return NULL;
	}
}

// Função auxiliar para imprimir a fila
void imprime_fila(Fila* f) {
    if (vazia(f)) {
        printf("Fila está vazia.\n");
        return;
    }

    printf("Fila: ");
    int i;
    for (i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->vet[i]);
    }
    printf("\n");
}
