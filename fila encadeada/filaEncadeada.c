#include "filaEncadeada.h"

Fila* cria_fila_vazia() {
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
	return f;
}

int vazia(Fila* f) {
	return (f->inicio == NULL);
}

//Enfileira um elemento
void enqueue(Fila* f, TipoItem x) {
	struct no* aux = (struct no*) malloc(sizeof(struct no));
	aux->info = x;
	aux->prox = NULL;
	if(vazia(f)) {
		f->inicio = aux;
	} else {
		f->fim->prox = aux;
	}
	f->fim = aux;
}

//Desenfileira um elemento
TipoItem* dequeue(Fila* f) {
	if(!vazia(f)) {
		TipoItem* x = (TipoItem*) malloc(sizeof(TipoItem));
		struct no* aux = f->inicio;
		*x = f->inicio->info;
		if(f->inicio == f->fim) // so tem 1 elemento
 			f->fim = NULL;
		f->inicio = f->inicio->prox;
		free(aux);
		return x;
	} else 
		return NULL;
}

// Imprime os elementos da fila
void imprimir_fila(Fila* f) {
    printf("Fila: ");
    struct no* aux = f->inicio;
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

