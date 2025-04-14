#include "listaEncadeadaSimples.h"

// Cria uma lista vazia (cabeça sentinela)
// Pré-condição: nenhuma
// Pós-condição: lista criada
Lista* cria_lista_vazia() {
    Lista* nova_lista = (Lista*) malloc(sizeof(Lista));
    if (nova_lista == NULL) {
        printf("Erro: falha ao alocar memoria para a lista.\n");
        return NULL;
    }
    nova_lista->prox = NULL;
    return nova_lista;
}

// Testa se a lista está vazia
// Pré-condição: ponteiro para a lista (cabeça não é NULL)
// Pós-condição: retorna 1 se vazia, 0 caso contrário
int vazia(Lista* l) {
    return (l->prox == NULL);
}


Lista* insere(Lista* l, TipoItem info) {
	
	Lista* aux = (Lista*) malloc(sizeof(Lista));
	
	aux->info = info;
	aux->prox = l; //encadeia com a cabeca da lista
	
	return aux;// retorna a nova cabeca
}

Lista * retira(Lista* l, TipoItem info) {
	Lista * ant = l; // elemento anterior
	Lista * p = l; // usado para encontrar o elemento
	
	// a ser retirado
	while(p!= NULL && p->info != info) { // localiza o elemento
		ant = p;
		p = p->prox;
	}
	
	if(p != NULL) { // elemento encontrado
		if(p == l) // remoc~ao na cabeca
			l = l->prox; // atualiza a cabeca
		else // remoc~ao no meio
			ant->prox = p->prox;
		
		free(p); // libera o no do elemento removido
	}
	else printf("Elemento nao encontrado");
	 
	return l;
}

void imprime(Lista* l) {
	if (vazia(l)) {
        printf("Lista vazia\n");
        return;
    }
    Lista* p = l;
    while (p->prox != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}

