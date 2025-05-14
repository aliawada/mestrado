#include "avl.c" 

void imprimir_estado(const char* msg, NoAVL* raiz) {
    printf("%s\n", msg);
    printf("Árvore em ordem: ");
    em_ordem(raiz);
    printf("\nAltura da raiz: %d\n", altura(raiz));
    printf("Fator de balanceamento da raiz: %d\n", fator_balanceamento(raiz));
    printf("Visual da árvore:\n");
    imprimir_arvore(raiz, 0);
    printf("\n");
}

int main() {
    NoAVL* raiz_a = NULL;
    NoAVL* raiz_b = NULL;

    // Exercício 6.a: 41, 38, 31, 12, 19, 8, 27, 49
    int valores_a[] = {41, 38, 31, 12, 19, 8, 27, 49};
    int n_a = sizeof(valores_a) / sizeof(valores_a[0]);

    printf("Construção da árvore AVL - Caso (a):\n");
    int i;
	for (i = 0; i < n_a; i++) {
        printf("Inserindo %d...\n", valores_a[i]);
        raiz_a = inserir(raiz_a, valores_a[i]);
        imprimir_estado("Estado atual da árvore:", raiz_a);
    }

    printf("Árvore final (a) construída.\n\n");

    // Exercício 6.b: 10, 20, 30, 40, 35
    int valores_b[] = {10, 20, 30, 40, 35};
    int n_b = sizeof(valores_b) / sizeof(valores_b[0]);

    printf("Construção da árvore AVL - Caso (b):\n");
	for (i = 0; i < n_b; i++) {
        printf("Inserindo %d...\n", valores_b[i]);
        raiz_b = inserir(raiz_b, valores_b[i]);
        imprimir_estado("Estado atual da árvore:", raiz_b);
    }

    printf("Árvore final (b) construída.\n\n");

    liberar_arvore(raiz_a);
    liberar_arvore(raiz_b);

    return 0;
}

