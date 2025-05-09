#include <stdio.h>

// Retorna 1 se n é par ou 0 se é ímpar
int par(int n) {
    if (n == 0)
        return 1;
    if (n > 0)
        return impar(n - 1);
    else
        return par(-n);
}

// Retorna 1 se n é ímpar ou 0 se é par
int impar(int n) {
    if (n == 0)
        return 0;
    if (n > 0)
        return par(n - 1);
    else
        return impar(-n);
}

int main() {
    int numeros[] = {-3, -2, 0, 1, 2, 7, 10};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
	
	int i;
    for (i = 0; i < tamanho; i++) {
        int n = numeros[i];
        printf("Numero %d e %s\n", n, par(n) ? "par" : "impar");
    }

    return 0;
}

