#include "abb.c"

int main() {
    int chaves[] = {80, 50, 2, 4, 60, 20, 25, 75, 70, 40, 22};
    int n = sizeof(chaves)/sizeof(chaves[0]);
    NoABB* raiz = NULL;

    printf("\n--- Insercao em Arvore Binaria de Busca ---\n");
    int i;
	for (i = 0; i < n; i++) {
        printf("\nInserindo %d...\n", chaves[i]);
        raiz = inserir_abb(raiz, chaves[i]);
        imprimir_arvore_abb(raiz, 0);
    }

    liberar_abb(raiz);
    return 0;
}
