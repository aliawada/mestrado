#include "pilhaEstatica.c"

int main() {
    Pilha* p = criar_pilha_vazia();

    // Testa se está vazia
    if (vazia(p)) {
        printf("Pilha esta vazia no inicio.\n");
    }

    // Empilha alguns elementos
    int i;
    for (i = 1; i <= 5; i++) {
        printf("Empilhando: %d\n", i);
        push(p, i);
    }

    // Testa se está cheia (não deve estar com apenas 5 elementos)
    if (cheia(p)) {
        printf("Pilha esta cheia.\n");
    } else {
        printf("Pilha ainda nao esta cheia.\n");
    }

    // Desempilha todos os elementos
    printf("Desempilhando:\n");
    while (!vazia(p)) {
        TipoItem* item = pop(p);
        if (item != NULL) {
            printf("Item desempilhado: %d\n", *item);
            free(item);
        }
    }

    // Testa novamente se está vazia
    if (vazia(p)) {
        printf("Pilha esta vazia no final.\n");
    }

    free(p);
    return 0;
}

