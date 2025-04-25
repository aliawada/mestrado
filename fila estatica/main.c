#include "filaEstatica.c"

int main() {
    // Cria fila vazia
    Fila* fila = cria_fila_vazia();

    // Verifica se a fila está vazia
    if (vazia(fila)) {
        printf("Fila criada esta vazia.\n");
    }

    // Enfileira elementos
    enqueue(fila, 10);
    enqueue(fila, 20);
    enqueue(fila, 30);
    enqueue(fila, 40);

    // Imprime a fila
    imprime_fila(fila);

    // Verifica se está cheia
    if (cheia(fila)) {
        printf("Fila esta cheia.\n");
    } else {
        printf("Fila nao esta cheia.\n");
    }

    // Desenfileira dois elementos
    TipoItem* item1 = dequeue(fila);
    if (item1 != NULL) {
        printf("Elemento desenfileirado: %d\n", *item1);
        free(item1);
    }

    TipoItem* item2 = dequeue(fila);
    if (item2 != NULL) {
        printf("Elemento desenfileirado: %d\n", *item2);
        free(item2);
    }

    // Imprime novamente após remoções
    imprime_fila(fila);

    // Testa a remoção até esvaziar
    while (!vazia(fila)) {
        TipoItem* item = dequeue(fila);
        if (item != NULL) {
            printf("Removido: %d\n", *item);
            free(item);
        }
    }

    // Tenta remover de fila vazia
    TipoItem* itemNulo = dequeue(fila);
    if (itemNulo == NULL) {
        printf("Nao foi possivel remover: fila vazia.\n");
    }

    // Libera memória da fila
    free(fila);

    return 0;
}
