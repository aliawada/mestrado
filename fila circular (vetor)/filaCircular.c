#include "filaCircular.h"

// Cria uma fila vazia
Fila* criarFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = 0;
        f->fim = 0;
    }
    return f;
}

//Testa se a fila esta vazia
int vazia(Fila* f) {
	return (f->inicio == f->fim);
}
 
//Testa se a fila esta cheia
int cheia(Fila* f) {
	//testa se a posic~ao seguinte ao fim e igual a posic~ao de incio
	// usando aritmetica modular
	return ((f->fim + 1)%TAM_MAX == f->inicio);
}

void enqueue(Fila* f, TipoItem x) {
	if(!cheia(f)) {
		f->vet[f->fim] = x;
		f->fim = (f->fim + 1) % TAM_MAX; // circularidade
	} else {
		printf("Fila cheia!\n");
	}
}

// Desenfileira um elemento
TipoItem* dequeue(Fila * f) {
	if(!vazia(f)) {
		TipoItem* aux = (TipoItem*) malloc(sizeof(TipoItem));
 		*aux = f->vet[f->inicio];
 		f->inicio++;
 		if(f->inicio == TAM_MAX) // implementa circularidade
 			f->inicio = 0;
 		return aux;
 	} else {
		printf("Fila vazia!");
		return NULL;
 	}
}

// Imprime os elementos da fila
void imprimirFila(Fila* f) {
    printf("Fila: ");
    int i = f->inicio;
    while (i != f->fim) {
        printf("%d ", f->vet[i]);
        i = (i + 1) % TAM_MAX;
    }
    printf("\n");
}

