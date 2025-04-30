#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.c"
#include "filaEncadeada.c"

int main() {
    // Teste da Fila Estática
    printf("=== Teste da Fila Estatica ===\n");
    FilaEstatica* fe = cria_fila_estatica_vazia();
    printf("Esta vazia? %s\n", vazia_estatica(fe) ? "Sim" : "Nao");
	int i;
    for (i = 1; i <= 5; i++) {
        enqueue_estatica(fe, i * 10);
    }
    imprimir_fila_estatica(fe);

    TipoItem* it_est;
    it_est = dequeue_estatica(fe);
    if (it_est) {
        printf("Desenfileirado: %d\n", *it_est);
        free(it_est);
    }
    imprimir_fila_estatica(fe);

    free(fe);

    // Teste da Fila Encadeada
    printf("\n=== Teste da Fila Encadeada ===\n");
    FilaEncadeada* fd = cria_fila_encadeada_vazia();
    printf("Esta vazia? %s\n", vazia_encadeada(fd) ? "Sim" : "Não");
	
    for (i = 1; i <= 5; i++) {
        enqueue_encadeada(fd, i * 100);
    }
    imprimir_fila_encadeada(fd);

    TipoItem* it_enc = dequeue_encadeada(fd);
    if (it_enc) {
        printf("Desenfileirado: %d\n", *it_enc);
        free(it_enc);
    }
    imprimir_fila_encadeada(fd);

    // Libera a fila encadeada
    struct no* aux;
    while (fd->inicio) {
        aux = fd->inicio;
        fd->inicio = fd->inicio->prox;
        free(aux);
    }
    free(fd);

    return 0;
}
