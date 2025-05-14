#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vestuario.h"

#define MAX_ITENS 1000
static Item estoque[MAX_ITENS];
static int totalItens = 0;

void inicializarEstoque() {
    totalItens = 0;
}

void inserirItem(Item novo) {
    if (totalItens < MAX_ITENS) {
        estoque[totalItens++] = novo;
    }
}

int removerItem(int codigo) {
	int i;
    for ( i = 0; i < totalItens; i++) {
        if (estoque[i].codigo == codigo) {
            estoque[i] = estoque[--totalItens];
            return 1;
        }
    }
    return 0;
}

Item* buscarItem(int codigo) {
	int i;
    for ( i = 0; i < totalItens; i++) {
        if (estoque[i].codigo == codigo) {
            return &estoque[i];
        }
    }
    return NULL;
}

void salvarEstoque() {
    FILE* f = fopen("estoque.bin", "wb");
    if (f) {
        fwrite(&totalItens, sizeof(int), 1, f);
        fwrite(estoque, sizeof(Item), totalItens, f);
        fclose(f);
    }
}

void carregarArquivoTexto(const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "r");
    if (!f) {
        printf("Erro ao abrir arquivo %s\n", nomeArquivo);
        return;
    }

    inicializarEstoque();
    char linha[256];
    int setorAtual = -1;
    int araraAtual = -1;

    while (fgets(linha, sizeof(linha), f)) {
        if (linha[0] == 'S') {
            sscanf(linha, "S%d", &setorAtual);
        } else if (linha[0] == 'A') {
            sscanf(linha, "A%d", &araraAtual);
        } else {
            Item item;
            item.setor = setorAtual;
            item.arara = araraAtual;
            item.disponivel = 1;
            sscanf(linha, "%d, %49[^,], %49[^,], %29[^,], %d", &item.codigo, item.tipo, item.marca, item.cor, &item.tamanho);
			item.tipo[strcspn(item.tipo, "\n")] = '\0';
			item.marca[strcspn(item.marca, "\n")] = '\0';
			item.cor[strcspn(item.cor, "\n")] = '\0';

            inserirItem(item);
        }
    }

    fclose(f);
}

void imprimirEstoque() {
	int i;
    for ( i = 0; i < totalItens; i++) {
        printf("[%d] %s - %s - %s - %d (Setor %d, Arara %d)\n",
            estoque[i].codigo,
            estoque[i].tipo,
            estoque[i].marca,
            estoque[i].cor,
            estoque[i].tamanho,
            estoque[i].setor,
            estoque[i].arara);
    }
}
