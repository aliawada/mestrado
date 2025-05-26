#include <stdio.h>

// Função recursiva para calcular potencia
int potencia(int base, int expoente) {
    if (expoente == 0)
        return 1;
    else
        return base * potencia(base, expoente - 1);
}

int main() {
    int base = 2;
    int expoente = 5;

    int resultado = potencia(base, expoente);
    printf("%d elevado a %d e %d\n", base, expoente, resultado);

    return 0;
}
