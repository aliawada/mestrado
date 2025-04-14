#include "listaDuplamenteEncadeada.h"

// Cria uma lista vazia (cabe�a sentinela)
// Pr�-condi��o: nenhuma
// P�s-condi��o: lista criada com campo prox e ant igual a NULL
Lista* cria_lista_vazia() {
    Lista* cabeca = (Lista*) malloc(sizeof(Lista));
    if (cabeca == NULL) {
        printf("Erro ao alocar mem�ria para a lista.\n");
        return NULL;
    }
    cabeca->prox = NULL;
    cabeca->ant = NULL;
    return cabeca;
}

// Verifica se a lista est� vazia (sem elementos ap�s a cabe�a)
// Pr�-condi��o: lista foi criada
// P�s-condi��o: retorna 1 se vazia, 0 se tiver elementos
int vazia(Lista* l) {
    return (l->prox == NULL);
}

// Insere novo elemento no in�cio da lista (ap�s a cabe�a)
// Pr�-condi��o: lista criada
// P�s-condi��o: elemento inserido logo ap�s a cabe�a
Lista* insere(Lista* l, TipoItem info) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para novo elemento.\n");
        return l;
    }
    novo->info = info;
    novo->ant = l;
    novo->prox = l->prox;

    if (l->prox != NULL) {
        l->prox->ant = novo;
    }

    l->prox = novo;
    return l;
}

// Remove o primeiro elemento com o valor 'info'
// Pr�-condi��o: lista criada
// P�s-condi��o: elemento removido, se encontrado
Lista* retira(Lista* l, TipoItem info) {
    Lista* p = l->prox;
    while (p != NULL && p->info != info) {
        p = p->prox;
    }

    if (p == NULL) {
        printf("Elemento %d n�o encontrado.\n", info);
        return l;
    }

    if (p->prox != NULL) {
        p->prox->ant = p->ant;
    }
    if (p->ant != NULL) {
        p->ant->prox = p->prox;
    }

    free(p);
    return l;
}

// Imprime todos os elementos da lista
// Pr�-condi��o: lista criada
// P�s-condi��o: elementos impressos do primeiro ao �ltimo
void imprime(Lista* l) {
    if (vazia(l)) {
        printf("Lista vazia\n");
    } else {
        Lista* p = l->prox;
        printf("[");
        while (p != NULL) {
            printf("%d ", p->info);
            p = p->prox;
        }
        printf("]\n");
    }
}
