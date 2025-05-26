#include "rb.c"

int main() {
    int chaves[] = {80, 50, 2, 4, 60, 20, 25, 75, 70, 40, 22};
    int n = sizeof(chaves)/sizeof(chaves[0]);
    NoRB* raiz = NULL;

    printf("\n--- Insercao em Arvore Vermelho-Preta ---\n");
    int i;
	for (i = 0; i < n; i++) {
        printf("\nInserindo %d...\n", chaves[i]);
        raiz = inserir_rb(raiz, chaves[i]);
        imprimir_arvore_rb(raiz, 0);
    }

    liberar_rb(raiz);
    return 0;
}
