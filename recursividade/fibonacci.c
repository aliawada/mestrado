#include <stdio.h>

int fibonacci(int n) {
 	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}
 
int main() {
    int numero = 5;
    int resultado = fibonacci(numero);
    printf("Fibonacci de %d e %d\n", numero, resultado);
    return 0;
}

