#include "listaEncadeadaComCabecaECauda.h"

// Cria uma lista com cabeça e cauda nulas (lista vazia)
Lista* cria_lista_vazia() {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if (l == NULL) {
        printf("Erro ao alocar memória para a lista.\n");
        return NULL;
    }
    l->cabeca = NULL;
    l->cauda = NULL;
    return l;
}

// Verifica se a lista está vazia
int vazia(Lista* l) {
    return (l->cabeca == NULL);
}

// Insere novo item no início da lista
Lista* insere(Lista* l, TipoItem info) {
	if (l == NULL) {
    	printf("Lista não inicializada.\n");
    	return l;
	}
	
    struct no* novo = (struct no*) malloc(sizeof(struct no));
    if (novo == NULL) {
        printf("Erro ao alocar memória para novo nó.\n");
        return l;
    }

    novo->info = info;
    novo->prox = l->cabeca;
    l->cabeca = novo;

    if (l->cauda == NULL) {
        // Primeiro elemento inserido
        l->cauda = novo;
    }

    return l;
}

// Remove o primeiro elemento com o valor info
Lista* retira(Lista* l, TipoItem info) {
	if (l == NULL) {
    	printf("Lista não inicializada.\n");
    	return l;
	}
	
    struct no* anterior = NULL;
    struct no* atual = l->cabeca;

    while (atual != NULL && atual->info != info) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Elemento %d não encontrado.\n", info);
        return l;
    }

    if (anterior == NULL) {
        // Remoção na cabeça
        l->cabeca = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    // Se for a cauda, atualize a cauda
    if (atual == l->cauda) {
        l->cauda = anterior;
    }
    
    if (l->cabeca == NULL) {
    	l->cauda = NULL;
	}

    free(atual);
    return l;
}

// Imprime os elementos da lista
void imprime(Lista* l) {
	if (l == NULL) {
    	printf("Lista não inicializada.\n");
    	return ;
	}
	
    if (vazia(l)) {
        printf("Lista vazia\n");
        return;
    }

    struct no* p = l->cabeca;
    printf("[");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("]\n");
}

void libera(Lista* l) {
    struct no* p = l->cabeca;
    while (p != NULL) {
        struct no* temp = p;
        p = p->prox;
        free(temp);
    }
    free(l);
}
