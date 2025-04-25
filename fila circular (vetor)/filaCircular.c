#include "filaCircular.h"

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

//Enfileira um elemento
void enqueue(Fila* f, TipoItem x) {
	if(!cheia(f)) {
		f->vet[f->fim] = x;
		f->fim++;
 		if(f->fim == TAM_MAX) // implementa circularidade
 			f->fim = 0;
 		else 
			printf("Fila cheia!");
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

