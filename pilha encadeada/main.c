#include "pilhaEncadeada.c"

int main() {
	Pilha* p = criar_pilha_vazia();

    if (vazia(p)) {
        printf("Pilha esta vazia no inicio.\n");
    }

    // Empilhar elementos
    int i;
    for (i = 1; i <= 5; i++) {
        printf("Empilhando: %d\n", i);
        push(p, i);

        // Mostrar o topo após empilhar
        TipoItem* t = topo(p);
        if (t != NULL) {
            printf("Topo atual: %d\n", *t);
            free(t);
        }
    }

    // Desempilhar elementos
    printf("Desempilhando:\n");
    while (!vazia(p)) {
        TipoItem* item = pop(p);
        if (item != NULL) {
            printf("Item desempilhado: %d\n", *item);
            free(item);
        }
    }

    if (vazia(p)) {
        printf("Pilha esta vazia no final.\n");
    }

    free(p);
	return 0;
}
