#include <stdio.h>

// Função recursiva para resolver o problema da Torre de Hanói
void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }
    hanoi(n - 1, origem, auxiliar, destino);
    printf("Mover disco %d de %c para %c\n", n, origem, destino);
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int n = 3; // número de discos
    printf("Solucao para %d discos:\n", n);
    hanoi(n, 'A', 'C', 'B'); // origem: A, destino: C, auxiliar: B
    return 0;
}

