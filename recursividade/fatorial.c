#include <stdio.h>

int fatorial(int n) {
    if(n == 0)
        return 1;
    else
        return n * fatorial(n - 1);
}

int main() {
    int numero = 5;
    int resultado = fatorial(numero);
    printf("Fatorial de %d e %d\n", numero, resultado);
    return 0;
}

