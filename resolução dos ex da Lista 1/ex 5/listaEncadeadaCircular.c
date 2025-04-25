#include "listaEncadeadaCircular.h"

Lista* cria_lista_vazia() {
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if (!l) return NULL;

    No* sentinela = (No*)malloc(sizeof(No));
    if (!sentinela) {
        free(l);
        return NULL;
    }

    sentinela->prox = sentinela; // circular: aponta para si mesma
    l->sentinela = sentinela;
    return l;
}

int vazia(Lista* l) {
    return l->sentinela->prox == l->sentinela;
}

void inserir_inicio(Lista* l, TipoItem x) {
    No* novo = (No*)malloc(sizeof(No));
    novo->info = x;
    novo->prox = l->sentinela->prox;
    l->sentinela->prox = novo;

    // Se era o único elemento, ele também é o último
    if (novo->prox == l->sentinela) {
        novo->prox = l->sentinela;
    } else {
        // Atualiza o último nó para apontar pro sentinela
        No* p = novo->prox;
        while (p->prox != l->sentinela) p = p->prox;
        p->prox = l->sentinela;
    }
}

void inserir_fim(Lista* l, TipoItem x) {
    No* novo = (No*)malloc(sizeof(No));
    novo->info = x;
    novo->prox = l->sentinela;

    No* p = l->sentinela;
    while (p->prox != l->sentinela)
        p = p->prox;

    p->prox = novo;
}

void inserep(Lista* l, int p, TipoItem x) {
    No* atual = l->sentinela;
    int i = 0;
    while (atual->prox != l->sentinela && i < p) {
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

    while (p != l->sentinela && p->info != x) {
        ant = p;
        p = p->prox;
    }

    if (p != l->sentinela) {
        ant->prox = p->prox;
        free(p);
    }
}

void retira_pos(Lista* l, int p, TipoItem* x) {
    No* ant = l->sentinela;
    No* atual = ant->prox;
    int i = 0;

    while (atual != l->sentinela && i < p) {
        ant = atual;
        atual = atual->prox;
        i++;
    }

    if (atual != l->sentinela) {
        *x = atual->info;
        ant->prox = atual->prox;
        free(atual);
    }
}

int busca(Lista* l, TipoItem x) {
    No* p = l->sentinela->prox;
    int i = 0;

    while (p != l->sentinela) {
        if (p->info == x)
            return i;
        p = p->prox;
        i++;
    }

    return -1;
}

void FLVazia(Lista* l) {
    No* p = l->sentinela->prox;
    while (p != l->sentinela) {
        No* temp = p;
        p = p->prox;
        free(temp);
    }
    l->sentinela->prox = l->sentinela;
}

void imprime(Lista* l) {
    No* p = l->sentinela->prox;
    if (p == l->sentinela) {
        printf("Lista vazia\n");
        return;
    }

    printf("[ ");
    while (p != l->sentinela) {
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
        while (p->prox != l->sentinela && p->prox != NULL) {
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
    if (vazia(l2)) return;

    No* fim1 = l1->sentinela;
    while (fim1->prox != l1->sentinela)
        fim1 = fim1->prox;

    No* inicio2 = l2->sentinela->prox;
    fim1->prox = inicio2;

    No* fim2 = inicio2;
    while (fim2->prox != l2->sentinela)
        fim2 = fim2->prox;

    fim2->prox = l1->sentinela;

    free(l2->sentinela);
    free(l2);
}

