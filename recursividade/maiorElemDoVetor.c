#include <stdio.h>

// Função recursiva para retornar o maior elemento de um vetor
int maiorElemento(int v[], int n) {
    if (n == 1)
        return v[0];
    else {
        int maxRestante = maiorElemento(v, n - 1);
        return (maxRestante > v[n - 1]) ? maxRestante : v[n - 1];
    }
}

int main() {
    int vetor[] = {7, 3, 9, 2, 10, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int maior = maiorElemento(vetor, tamanho);
    printf("O maior elemento do vetor e: %d\n", maior);

    return 0;
}

