#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct pessoa {
    char nome[MAX_NOME];
    struct pessoa* filho1;
    struct pessoa* filho2;
} Pessoa;

// Cria uma nova pessoa
Pessoa* criarPessoa(const char* nome) {
    Pessoa* nova = (Pessoa*)malloc(sizeof(Pessoa));
    if (nova != NULL) {
        strcpy(nova->nome, nome);
        nova->filho1 = NULL;
        nova->filho2 = NULL;
    }
    return nova;
}

// Mostra a árvore genealógica em pré-ordem
void mostrarArvore(Pessoa* p, int nivel) {
    if (p == NULL) return;
    int i;
	for (i = 0; i < nivel; i++) printf("  ");
    printf("%s\n", p->nome);
    mostrarArvore(p->filho1, nivel + 1);
    mostrarArvore(p->filho2, nivel + 1);
}

// Libera memória da árvore
void liberarArvore(Pessoa* p) {
    if (p == NULL) return;
    liberarArvore(p->filho1);
    liberarArvore(p->filho2);
    free(p);
}

int main() {
    // Criando os membros
    Pessoa* joao = criarPessoa("João");
    Pessoa* pedro = criarPessoa("Pedro");
    Pessoa* ana = criarPessoa("Ana");
    Pessoa* carla = criarPessoa("Carla");

    // Ligando os filhos
    joao->filho1 = pedro;
    joao->filho2 = ana;
    ana->filho1 = carla;

    // Exibe a árvore
    printf("Árvore Genealógica:\n");
    mostrarArvore(joao, 0);

    // Libera memória
    liberarArvore(joao);

    return 0;
}

