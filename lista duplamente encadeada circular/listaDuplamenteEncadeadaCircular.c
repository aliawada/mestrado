#include "listaDuplamenteEncadeadaCircular.h"

// Cria uma lista vazia com cabe�a sentinela
Lista* cria_lista_vazia() {
    Lista* cabeca = (Lista*) malloc(sizeof(Lista));
    if (cabeca == NULL) {
        printf("Erro ao alocar mem�ria para a lista.\n");
        return NULL;
    }
    cabeca->prox = cabeca;
    cabeca->ant = cabeca;
    return cabeca;
}

// Verifica se a lista est� vazia
int vazia(Lista* l) {
    return (l->prox == l);
}

// Insere um novo n� ap�s a cabe�a (in�cio da lista)
Lista* insere(Lista* l, TipoItem info) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro ao alocar mem�ria para novo elemento.\n");
        return l;
    }
    novo->info = info;
    novo->prox = l->prox;
    novo->ant = l;
    l->prox->ant = novo;
    l->prox = novo;
    return l;
}

// Remove o primeiro n� com o valor info
Lista* retira(Lista* l, TipoItem info) {
    Lista* p = l->prox;

    while (p != l && p->info != info) {
        p = p->prox;
    }

    if (p == l) {
        printf("Elemento %d n�o encontrado.\n", info);
        return l;
    }

    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    free(p);
    return l;
}

// Imprime os elementos da lista
void imprime(Lista* l) {
    if (vazia(l)) {
        printf("Lista vazia\n");
        return;
    }

    Lista* p = l->prox;
    printf("[");
    while (p != l) {
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("]\n");
}
