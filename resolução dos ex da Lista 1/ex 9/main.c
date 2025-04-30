#include <stdio.h>
#include <stdlib.h>
#include "filaCircularEstatica.c"
#include "filaCircularEncadeada.c"

int main() {
    // Fila Circular Estática
    FilaCircularEstatica* fe = cria_fila_circular_estatica();
    int i;
    for (i = 1; i <= 5; i++) enqueue_circular_estatica(fe, i*10);
    imprimir_fila_circular_estatica(fe);
    TipoItem* e1 = dequeue_circular_estatica(fe);
    if (e1) { printf("Removido (est): %d\n", *e1); free(e1); }
    imprimir_fila_circular_estatica(fe);

    // Fila Circular Encadeada
    FilaCircularEncadeada* fd = cria_fila_circular_encadeada_vazia();
    for (i = 1; i <= 5; i++) enqueue_circular_encadeada(fd, i*100);
    imprimir_fila_circular_encadeada(fd);
    TipoItem* e2 = dequeue_circular_encadeada(fd);
    if (e2) { printf("Removido (enc): %d\n", *e2); free(e2); }
    imprimir_fila_circular_encadeada(fd);

    // Libera memoria estática
    free(fe);
    // Libera memoria encadeada
    while (!vazia_circular_encadeada(fd)) {
        TipoItem* tmp = dequeue_circular_encadeada(fd);
        free(tmp);
    }
    free(fd);

    return 0;
}

