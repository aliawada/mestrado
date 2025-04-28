#include "filaEncadeada.c"

int main() {
    // Cria uma fila vazia
    Fila* f = cria_fila_vazia();

    // Verifica se está vazia
    if (vazia(f))
        printf("A fila esta vazia!\n");

    // Enfileira elementos
    enqueue(f, 10);
    enqueue(f, 20);
    enqueue(f, 30);

    // Imprime a fila
    imprimir_fila(f);

    // Desenfileira dois elementos
    TipoItem* x = dequeue(f);
    if (x != NULL) {
        printf("Desenfileirado: %d\n", *x);
        free(x);
    }

    x = dequeue(f);
    if (x != NULL) {
        printf("Desenfileirado: %d\n", *x);
        free(x);
    }

    // Imprime novamente
    imprimir_fila(f);

    // Enfileira mais um
    enqueue(f, 40);
    imprimir_fila(f);

    // Verifica se a fila está vazia
    if (!vazia(f))
        printf("A fila ainda tem elementos.\n");

    // Limpa o restante
    while (!vazia(f)) {
        TipoItem* y = dequeue(f);
        printf("Removendo: %d\n", *y);
        free(y);
    }

    imprimir_fila(f);
    free(f);

    return 0;
}

