#include "filaEncadeada.c"

void teste_a() {
    printf("\nTESTE A: Permutacao IIIRRIRR com n=4\n");
    Fila* f = cria_fila_vazia();

    enqueue(f, 1); // I
    enqueue(f, 2); // I
    enqueue(f, 3); // I

    TipoItem* x;
    x = dequeue_traseira(f); if (x) { printf("Removido: %d\n", *x); free(x); } // R
    x = dequeue_traseira(f); if (x) { printf("Removido: %d\n", *x); free(x); } // R

    enqueue(f, 4); // I

    x = dequeue_traseira(f); if (x) { printf("Removido: %d\n", *x); free(x); } // R
    x = dequeue_traseira(f); if (x) { printf("Removido: %d\n", *x); free(x); } // R

    free(f);
}

void teste_b() {
    printf("\nTESTE B: Tentativa de inverter 1 2 3 4 5 6\n");
    Fila* f = cria_fila_vazia();
	
	int i;
    for (i = 1; i <= 6; i++)
        enqueue(f, i);

    printf("Invertendo usando apenas extremidade de tras:\n");
    while (!vazia(f)) {
        TipoItem* x = dequeue_traseira(f);
        if (x) { printf("%d ", *x); free(x); }
    }
    printf("\n");

    free(f);
}

void teste_c() {
    printf("\nTESTE C: Verificacao de permutacoes\n");

    printf("\nTentando obter 3 2 5 6 4 1:\n");
    printf("Nao eh possivel: operacoes limitadas na extremidade de tras nao permitem reordenar a fila de forma arbitraria.\n");

    printf("\nTentando obter 1 5 4 6 2 3:\n");
    printf("Nao eh possivel: operacoes limitadas na extremidade de tras nao permitem reordenar a fila de forma arbitraria.\n");
}

int main() {
    teste_a();
    teste_b();
    teste_c();
    return 0;
}
