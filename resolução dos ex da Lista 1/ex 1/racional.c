#include "racional.h"

struct racional {
	int num;
	int den;
};

// Função auxiliar para calcular o máximo divisor comum (MDC)
int mdc(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// Cria e simplifica um número racional
RACIONAL* criar(int num, int den) {
	if (den == 0) {
		printf("Erro: denominador não pode ser zero.\n");
		return NULL;
	}

	RACIONAL* novo = (RACIONAL*) malloc(sizeof(RACIONAL));
	if (novo == NULL) {
		printf("Erro de alocação.\n");
		return NULL;
	}

	int divisor = mdc(abs(num), abs(den));
	novo->num = num / divisor;
	novo->den = den / divisor;

	// Garante denominador positivo
	if (novo->den < 0) {
		novo->num *= -1;
		novo->den *= -1;
	}

	return novo;
}

// Libera a memória alocada
void limpar(RACIONAL *rac) {
	if (rac != NULL) {
		free(rac);
	}
}

// Imprime um número racional
void imprimir(RACIONAL *rac) {
	if (rac == NULL) {
		printf("Racional inválido.\n");
		return;
	}
	printf("%d/%d\n", rac->num, rac->den);
}

// Soma dois racionais
RACIONAL *adicao(RACIONAL *v1, RACIONAL *v2) {
	if (v1 == NULL || v2 == NULL) return NULL;

	int num = v1->num * v2->den + v2->num * v1->den;
	int den = v1->den * v2->den;

	return criar(num, den);
}

// Multiplica dois racionais
RACIONAL *multiplicacao(RACIONAL *v1, RACIONAL *v2) {
	if (v1 == NULL || v2 == NULL) return NULL;

	int num = v1->num * v2->num;
	int den = v1->den * v2->den;

	return criar(num, den);
}


