#include <stdio.h>

int A(int param1, char param2) {
    // Exemplo: retorna o valor de param1 multiplicado pelo código ASCII de param2
    return param1 * (int)param2;
}

int B(int v[], int n) {
    int i, r = 0;
    char M = 'A'; // valor de M como char

    for(i = 0; i < n; i++)
        r = r + A(v[i], M); // chama função A

    return r;
}

int C() {
    int vet[5] = {1, 2, 3, 4, 5}; // preenchendo o vetor

    return B(vet, 5); // chama função B
}

int main() {
    int x = C();
    printf("Resultado final: %d\n", x);
    return 0;
}

