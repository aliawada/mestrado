#include <stdio.h>

// versão com recursão em cauda
int fatorial_cauda(int n, int acumulador) {
    if (n == 0)
        return acumulador;
    else // chamada recursiva é a última instrução
        return fatorial_cauda(n - 1, n * acumulador);
}

int fatorial(int n) {
    return fatorial_cauda(n, 1);
}

int main() {
    int numeros[] = {0, 1, 3, 5, 7, 12};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
	int i;
    for (i = 0; i < tamanho; i++) {
        int n = numeros[i];
        printf("Fatorial de %d e %d\n", n, fatorial(n));
    }

    return 0;
}

