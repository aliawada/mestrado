#include <stdio.h>
#include <stdlib.h>

// ------------------------ No Generico ------------------------

typedef struct No {
    void* dado;
    struct No* prox;
} No;

No* criar_no(void* dado) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

void inserir_no(No** lista, No* novo) {
    if (*lista == NULL) {
        *lista = novo;
    } else {
        No* aux = *lista;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}

void liberar_lista(No* lista, void (*libera_dado)(void*)) {
    while (lista != NULL) {
        No* temp = lista;
        lista = lista->prox;
        if (libera_dado != NULL)
            libera_dado(temp->dado);
        free(temp);
    }
}

// ------------------------ Pilha Generica ------------------------

typedef struct {
    No* topo;
} Pilha;

Pilha* criar_pilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha* p, void* dado) {
    No* novo = criar_no(dado);
    novo->prox = p->topo;
    p->topo = novo;
}

void* pop(Pilha* p) {
    if (p->topo == NULL) return NULL;
    No* temp = p->topo;
    void* dado = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return dado;
}

void liberar_pilha(Pilha* p, void (*libera_dado)(void*)) {
    liberar_lista(p->topo, libera_dado);
    free(p);
}

// ------------------------ Fila Generica ------------------------

typedef struct {
    No* inicio;
    No* fim;
} Fila;

Fila* criar_fila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

void enqueue(Fila* f, void* dado) {
    No* novo = criar_no(dado);
    if (f->fim == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void* dequeue(Fila* f) {
    if (f->inicio == NULL) return NULL;
    No* temp = f->inicio;
    void* dado = temp->dado;
    f->inicio = temp->prox;
    if (f->inicio == NULL)
        f->fim = NULL;
    free(temp);
    return dado;
}

void liberar_fila(Fila* f, void (*libera_dado)(void*)) {
    liberar_lista(f->inicio, libera_dado);
    free(f);
}

// ------------------------ Exemplo de Uso ------------------------

void liberar_int(void* dado) {
    free((int*)dado);
}

int main() {
    printf("\n--- Exemplo com Pilha Generica ---\n");
    Pilha* pilha = criar_pilha();
    int i;
    for (i = 0; i < 5; i++) {
        int* valor = (int*)malloc(sizeof(int));
        *valor = i;
        push(pilha, valor);
    }
    for (i = 0; i < 5; i++) {
        int* valor = (int*)pop(pilha);
        if (valor) {
            printf("Pilha pop: %d\n", *valor);
            free(valor);
        }
    }
    liberar_pilha(pilha, liberar_int);

    printf("\n--- Exemplo com Fila Generica ---\n");
    Fila* fila = criar_fila();
    for (i = 0; i < 5; i++) {
        int* valor = (int*)malloc(sizeof(int));
        *valor = i;
        enqueue(fila, valor);
    }
    for (i = 0; i < 5; i++) {
        int* valor = (int*)dequeue(fila);
        if (valor) {
            printf("Fila dequeue: %d\n", *valor);
            free(valor);
        }
    }
    liberar_fila(fila, liberar_int);

    return 0;
}


