#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100

typedef struct no {
    char nome[MAX_NOME];
    struct no* primeiroFilho;
    struct no* proximoIrmao;
} No;

// Cria um novo nó
No* criarNo(const char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->primeiroFilho = NULL;
        novo->proximoIrmao = NULL;
    }
    return novo;
}

// Adiciona um filho ao nó pai
void adicionarFilho(No* pai, No* filho) {
    if (pai->primeiroFilho == NULL) {
        pai->primeiroFilho = filho;
    } else {
        No* atual = pai->primeiroFilho;
        while (atual->proximoIrmao != NULL)
            atual = atual->proximoIrmao;
        atual->proximoIrmao = filho;
    }
}

// Imprime a árvore com indentação
void imprimirEstrutura(No* no, int nivel) {
    if (no == NULL) return;
    int i;
	for (i = 0; i < nivel; i++) printf("  ");
    printf("%s\n", no->nome);
    imprimirEstrutura(no->primeiroFilho, nivel + 1);
    imprimirEstrutura(no->proximoIrmao, nivel);
}

// Libera memória
void liberarArvore(No* no) {
    if (no == NULL) return;
    liberarArvore(no->primeiroFilho);
    liberarArvore(no->proximoIrmao);
    free(no);
}

int main() {
    // Nó raiz
    No* diretoria = criarNo("Diretoria");

    // Níveis abaixo da diretoria
    No* tecnicaInfo = criarNo("Seção Técnica de Informática");
    No* tecnicaAcademica = criarNo("Assistência Técnica Acadêmica");
    No* tecnicaFinanceira = criarNo("Assistência Técnica Financeira");
    No* outros = criarNo("...");

    adicionarFilho(diretoria, tecnicaInfo);
    adicionarFilho(diretoria, tecnicaAcademica);
    adicionarFilho(diretoria, tecnicaFinanceira);
    adicionarFilho(diretoria, outros);

    // Filhos da Assistência Técnica Acadêmica
    No* apoio = criarNo("Serviço de Apoio Acadêmico");
    No* graduacao = criarNo("Serviço de Graduação");
    No* posGraduacao = criarNo("Serviço de Pós-Graduação");

    adicionarFilho(tecnicaAcademica, apoio);
    adicionarFilho(tecnicaAcademica, graduacao);
    adicionarFilho(tecnicaAcademica, posGraduacao);

    // Imprimir a estrutura
    printf("Estrutura Organizacional do ICMC:\n");
    imprimirEstrutura(diretoria, 0);

    // Liberar memória
    liberarArvore(diretoria);
    return 0;
}

