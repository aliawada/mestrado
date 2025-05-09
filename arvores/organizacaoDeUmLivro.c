#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXTO 100

// Estrutura de nó da árvore (parte do livro)
typedef struct no {
    char titulo[MAX_TEXTO];
    struct no* primeiroFilho;
    struct no* proximoIrmao;
} NoLivro;

// Cria novo nó
NoLivro* criarNo(const char* titulo) {
    NoLivro* novo = (NoLivro*)malloc(sizeof(NoLivro));
    if (novo != NULL) {
        strcpy(novo->titulo, titulo);
        novo->primeiroFilho = NULL;
        novo->proximoIrmao = NULL;
    }
    return novo;
}

// Adiciona um filho ao nó
void adicionarFilho(NoLivro* pai, NoLivro* filho) {
    if (pai->primeiroFilho == NULL) {
        pai->primeiroFilho = filho;
    } else {
        NoLivro* atual = pai->primeiroFilho;
        while (atual->proximoIrmao != NULL)
            atual = atual->proximoIrmao;
        atual->proximoIrmao = filho;
    }
}

// Imprime a árvore (livro) com indentação
void imprimirLivro(NoLivro* no, int nivel) {
    if (no == NULL) return;
    int i;
	for (i = 0; i < nivel; i++) printf("  ");
    printf("%s\n", no->titulo);
    imprimirLivro(no->primeiroFilho, nivel + 1);
    imprimirLivro(no->proximoIrmao, nivel);
}

// Libera memória
void liberarLivro(NoLivro* no) {
    if (no == NULL) return;
    liberarLivro(no->primeiroFilho);
    liberarLivro(no->proximoIrmao);
    free(no);
}

int main() {
    // Criando partes do livro
    NoLivro* livro = criarNo("Livro: Estrutura de Dados");

    NoLivro* cap1 = criarNo("Capítulo 1: Introdução");
    NoLivro* cap2 = criarNo("Capítulo 2: Listas");
    NoLivro* cap3 = criarNo("Capítulo 3: Árvores");

    adicionarFilho(livro, cap1);
    adicionarFilho(livro, cap2);
    adicionarFilho(livro, cap3);

    adicionarFilho(cap1, criarNo("Seção 1.1: Conceitos Básicos"));
    adicionarFilho(cap1, criarNo("Seção 1.2: Complexidade"));

    adicionarFilho(cap2, criarNo("Seção 2.1: Listas Simples"));
    adicionarFilho(cap2, criarNo("Seção 2.2: Listas Duplas"));

    adicionarFilho(cap3, criarNo("Seção 3.1: Árvores Binárias"));
    adicionarFilho(cap3, criarNo("Seção 3.2: Árvores Balanceadas"));

    // Exibe estrutura do livro
    printf("Organização do Livro:\n");
    imprimirLivro(livro, 0);

    // Libera memória
    liberarLivro(livro);
    return 0;
}

