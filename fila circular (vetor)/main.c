#include "filaCircular.c"

int main() {
    Fila* f = criarFila();

    // Enfileirando elementos
    enqueue(f, 10);
    enqueue(f, 20);
    enqueue(f, 30);
    enqueue(f, 40);

    // Imprime fila atual
    imprimirFila(f);

    // Tenta enfileirar com fila cheia
    enqueue(f, 50); // Deve entrar
    enqueue(f, 60); // Deve avisar que está cheia

    imprimirFila(f);

    // Desenfileira dois elementos
    TipoItem* item1 = dequeue(f);
    TipoItem* item2 = dequeue(f);
    if (item1) {
        printf("Removido: %d\n", *item1);
        free(item1);
    }
    if (item2) {
        printf("Removido: %d\n", *item2);
        free(item2);
    }

    imprimirFila(f);

    // Enfileira mais dois
    enqueue(f, 70);
    enqueue(f, 80);

    imprimirFila(f);

    // Libera memória
    free(f);
    return 0;
}

