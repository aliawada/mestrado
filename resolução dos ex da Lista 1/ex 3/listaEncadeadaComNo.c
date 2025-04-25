#include "listaEncadeadaComNo.h"

// Cria uma lista com nó sentinela
Lista* cria_lista_vazia() {
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if (l == NULL) return NULL;

    No* sentinela = (No*)malloc(sizeof(No));
    if (sentinela == NULL) {
        free(l);
        return NULL;
    }

    sentinela->prox = NULL;
    l->sentinela = sentinela;
    return l;
}

int vazia(Lista* l) {
    return l->sentinela->prox == NULL;
}

void inserir_inicio(Lista* l, TipoItem x) {
    No* novo = (No*)malloc(sizeof(No));
    novo->info = x;
    novo->prox = l->sentinela->prox;
    l->sentinela->prox = novo;
}

void inserir_fim(Lista* l, TipoItem x) {
    No* novo = (No*)malloc(sizeof(No));
    novo->info = x;
    novo->prox = NULL;

    No* p = l->sentinela;
    while (p->prox != NULL)
        p = p->prox;

    p->prox = novo;
}

void inserep(Lista* l, int p, TipoItem x) {
    No* atual = l->sentinela;
    int i = 0;

    while (atual->prox != NULL && i < p) {
        atual = atual->prox;
        i++;
    }

    No* novo = (No*)malloc(sizeof(No));
    novo->info = x;
    novo->prox = atual->prox;
    atual->prox = novo;
}

void retira(Lista* l, TipoItem x) {
    No* ant = l->sentinela;
    No* p = ant->prox;

    while (p != NULL && p->info != x) {
        ant = p;
        p = p->prox;
    }

    if (p != NULL) {
        ant->prox = p->prox;
        free(p);
    }
}

void retira_pos(Lista* l, int p, TipoItem* x) {
    No* ant = l->sentinela;
    No* atual = ant->prox;
    int i = 0;

    while (atual != NULL && i < p) {
        ant = atual;
        atual = atual->prox;
        i++;
    }

    if (atual != NULL) {
        *x = atual->info;
        ant->prox = atual->prox;
        free(atual);
    }
}

int busca(Lista* l, TipoItem x) {
    No* p = l->sentinela->prox;
    int i = 0;

    while (p != NULL) {
        if (p->info == x)
            return i;
        p = p->prox;
        i++;
    }

    return -1;
}

void FLVazia(Lista* l) {
    No* p = l->sentinela->prox;
    while (p != NULL) {
        No* temp = p;
        p = p->prox;
        free(temp);
    }
    l->sentinela->prox = NULL;
}

void imprime(Lista* l) {
    No* p = l->sentinela->prox;
    if (p == NULL) {
        printf("Lista vazia\n");
        return;
    }

    printf("[ ");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("]\n");
}

void ordenar(Lista* l) {
    if (vazia(l)) return;

    int trocou;
    do {
        trocou = 0;
        No* p = l->sentinela->prox;
        while (p != NULL && p->prox != NULL) {
            if (p->info > p->prox->info) {
                TipoItem tmp = p->info;
                p->info = p->prox->info;
                p->prox->info = tmp;
                trocou = 1;
            }
            p = p->prox;
        }
    } while (trocou);
}

void concatenar(Lista* l1, Lista* l2) {
    No* p = l1->sentinela;
    while (p->prox != NULL)
        p = p->prox;

    p->prox = l2->sentinela->prox;

    // Opcional: liberar a sentinela de l2
    free(l2->sentinela);
    free(l2);
}

