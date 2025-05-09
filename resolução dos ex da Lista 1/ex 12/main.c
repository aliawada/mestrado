
#include <stdio.h>
#include <stdlib.h>

typedef enum {ATOMO, LISTA} Tipo;

typedef struct ListaGen {
    Tipo tipo;
    union {
        int valor;
        struct ListaGen* sublista;
    } dado;
    struct ListaGen* prox;
} ListaGen;

ListaGen* cria_atomo(int valor) {
    ListaGen* novo = (ListaGen*)malloc(sizeof(ListaGen));
    novo->tipo = ATOMO;
    novo->dado.valor = valor;
    novo->prox = NULL;
    return novo;
}

ListaGen* cria_lista(ListaGen* sublista) {
    ListaGen* novo = (ListaGen*)malloc(sizeof(ListaGen));
    novo->tipo = LISTA;
    novo->dado.sublista = sublista;
    novo->prox = NULL;
    return novo;
}

void inserir(ListaGen** lista, ListaGen* novo) {
    if (*lista == NULL) {
        *lista = novo;
    } else {
        ListaGen* aux = *lista;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}

void imprimir_lista(ListaGen* lista) {
    printf("(");
    while (lista != NULL) {
        if (lista->tipo == ATOMO) {
            printf("%d", lista->dado.valor);
        } else {
            imprimir_lista(lista->dado.sublista);
        }
        if (lista->prox != NULL) printf(", ");
        lista = lista->prox;
    }
    printf(")");
}

int soma_lista(ListaGen* lista) {
    int soma = 0;
    while (lista != NULL) {
        if (lista->tipo == ATOMO) {
            soma += lista->dado.valor;
        } else {
            soma += soma_lista(lista->dado.sublista);
        }
        lista = lista->prox;
    }
    return soma;
}

void liberar_lista(ListaGen* lista) {
    while (lista != NULL) {
        ListaGen* temp = lista;
        if (lista->tipo == LISTA) {
            liberar_lista(lista->dado.sublista);
        }
        lista = lista->prox;
        free(temp);
    }
}

ListaGen* buscar_elemento(ListaGen* lista, int valor) {
    while (lista != NULL) {
        if (lista->tipo == ATOMO && lista->dado.valor == valor) {
            return lista;
        } else if (lista->tipo == LISTA) {
            ListaGen* encontrado = buscar_elemento(lista->dado.sublista, valor);
            if (encontrado != NULL) return encontrado;
        }
        lista = lista->prox;
    }
    return NULL;
}

int contar_elementos(ListaGen* lista) {
    int count = 0;
    while (lista != NULL) {
        if (lista->tipo == ATOMO) {
            count++;
        } else {
            count += contar_elementos(lista->dado.sublista);
        }
        lista = lista->prox;
    }
    return count;
}

int main() {
    printf("\n--- Lista Generalizada - Aplicacao Completa! ---\n");

    ListaGen* lista = NULL;
    inserir(&lista, cria_atomo(1));

    ListaGen* sub1 = NULL;
    inserir(&sub1, cria_atomo(2));
    inserir(&sub1, cria_atomo(3));
    inserir(&lista, cria_lista(sub1));

    inserir(&lista, cria_atomo(4));

    ListaGen* sub2 = NULL;
    inserir(&sub2, cria_atomo(5));

    ListaGen* subsub = NULL;
    inserir(&subsub, cria_atomo(6));
    inserir(&subsub, cria_atomo(7));
    inserir(&sub2, cria_lista(subsub));

    inserir(&lista, cria_lista(sub2));

    printf("Lista criada: ");
    imprimir_lista(lista);
    printf("\n");

    printf("Soma de todos os atomos: %d\n", soma_lista(lista));
    printf("Total de elementos: %d\n", contar_elementos(lista));

    int valor_busca = 6;
    ListaGen* encontrado = buscar_elemento(lista, valor_busca);
    if (encontrado != NULL) {
        printf("Elemento %d encontrado na lista!\n", valor_busca);
    } else {
        printf("Elemento %d NAO encontrado na lista.\n", valor_busca);
    }

    liberar_lista(lista);

    return 0;
}
