#include <stdio.h>

// função para retornar o maior elem.
// de um vetor de n inteiros
int maiorElem(int v[], int n) {
    if (n == 1)
        return v[0];
    else {
        int x = maiorElem(v, n - 1);
        if (x > v[n - 1])
            return x;
        else
            return v[n - 1];
    }
}

int main() {
    int vetor[] = {7, 3, 9, 2, 10, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int maior = maiorElem(vetor, tamanho);
    printf("O maior elemento do vetor e: %d\n", maior);

    return 0;
}

