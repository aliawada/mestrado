#include "listaEstatica.h"

Lista* cria_lista_vazia() {
    Lista* nova_lista = (Lista*)malloc(sizeof(Lista));
    nova_lista->primeiro = 0;
    nova_lista->ultimo = 0;
    nova_lista->pos = -1;
    return nova_lista;
}

int vazia(Lista* l) {
    return (l->primeiro == l->ultimo);
}

void insere(Lista* l, TipoItem x) {
    if (l->ultimo >= TAM_MAX) {
        printf("Erro: Lista cheia, nao e possivel inserir %d\n", x);
        return;
    }
    l->item[l->ultimo++] = x;
}

void retira(Lista* l, TipoItem x) {
    if (vazia(l)) {
        printf("Erro: Lista vazia, nao e possivel remover %d\n", x);
        return;
    }
    int i, encontrado = 0;
    for (i = 0; i < l->ultimo; i++) {
        if (l->item[i] == x) {
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Erro: Item %d nao encontrado na lista\n", x);
        return;
    }
    for (; i < l->ultimo - 1; i++) {
        l->item[i] = l->item[i + 1];
    }
    l->ultimo--;
}

void imprime(Lista* l) {
    if (vazia(l)) {
        printf("Lista vazia\n");
    } else {
        printf("[ ");
        int i = 0;
        for (i = l->primeiro; i < l->ultimo; i++) {
            printf("%d ", l->item[i]);
        }
        printf("]\n");
    }
}

void imprime2(Lista* l) {
    if (vazia(l)) {
        printf("Lista vazia\n");
    } else {
        TipoItem x = primeiro(l);
        printf("[ ");
        do {
            printf("%d ", x);
        } while ((x = proximo(l)) != -1);
        printf("]\n");
    }
}

TipoItem primeiro(Lista* l) {
    l->pos = -1;
    return proximo(l);
}

TipoItem proximo(Lista* l) {
    l->pos++;
    if (l->pos >= l->ultimo) return -1;
    return l->item[l->pos];
}

void inserir_inicio(Lista* l, TipoItem x) {
    if (l->ultimo >= TAM_MAX) {
        printf("Erro: Lista cheia\n");
        return;
    }
    int i = 0;
    for (i = l->ultimo; i > 0; i--) {
        l->item[i] = l->item[i - 1];
    }
    l->item[0] = x;
    l->ultimo++;
}

int busca(Lista* l, TipoItem x) {
	int i = 0;
    for (i = 0; i < l->ultimo; i++) {
        if (l->item[i] == x) return i;
    }
    return -1;
}

void FLVazia(Lista* l) {
    l->primeiro = 0;
    l->ultimo = 0;
    l->pos = -1;
}

void inserep(Lista* l, int p, TipoItem x) {
    if (p < 0 || p > l->ultimo || l->ultimo >= TAM_MAX) {
        printf("Erro: Posicao invalida ou lista cheia\n");
        return;
    }
    int i = 0;
    for (i = l->ultimo; i > p; i--) {
        l->item[i] = l->item[i - 1];
    }
    l->item[p] = x;
    l->ultimo++;
}

TipoItem retira_pos(Lista* l, int p) {
    if (p < 0 || p >= l->ultimo) {
        printf("Erro: Posicao invalida\n");
        return -1;
    }
    TipoItem retirado = l->item[p];
    int i = 0;
    for (i = p; i < l->ultimo - 1; i++) {
        l->item[i] = l->item[i + 1];
    }
    l->ultimo--;
    return retirado;
}

void ordenar(Lista* l) {
	int i = 0;
	int j = 0;
    for (i = 0; i < l->ultimo - 1; i++) {
        for (j = i + 1; j < l->ultimo; j++) {
            if (l->item[i] > l->item[j]) {
                TipoItem temp = l->item[i];
                l->item[i] = l->item[j];
                l->item[j] = temp;
            }
        }
    }
}

void concatenar(Lista* l1, Lista* l2) {
    if (l1->ultimo + (l2->ultimo - l2->primeiro) > TAM_MAX) {
        printf("Erro: nao e possivel concatenar, tamanho excedido\n");
        return;
    }
    int i = 0;
    for (i = l2->primeiro; i < l2->ultimo; i++) {
        l1->item[l1->ultimo++] = l2->item[i];
    }
}

