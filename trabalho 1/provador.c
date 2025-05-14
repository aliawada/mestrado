#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "provador.h"
#include "vestuario.h"

static Provador provadores[TOTAL_PROVADORES];
static Fila filaEspera;

void inicializarProvadores() {
	int i;
    for ( i = 0; i < TOTAL_PROVADORES; i++) {
        provadores[i].id = i;
        provadores[i].ocupado = 0;
        inicializarPilha(&provadores[i].provando);
        inicializarPilha(&provadores[i].compra);
        inicializarPilha(&provadores[i].devolucao);
    }
    inicializarFila(&filaEspera);
}

int alocarProvador(Cliente c) {
	int i;
    for ( i = 0; i < TOTAL_PROVADORES; i++) {
        if (!provadores[i].ocupado) {
            provadores[i].ocupado = 1;
            provadores[i].cliente = c;
            inicializarPilha(&provadores[i].provando);
            inicializarPilha(&provadores[i].compra);
            inicializarPilha(&provadores[i].devolucao);
            printf("Cliente %s alocado no provador %d\n", c.cpf, i);
            return i;
        }
    }
    enfileirar(&filaEspera, c);
    printf("Todos os provadores estao ocupados. Cliente %s entrou na fila.\n", c.cpf);
    return -1;
}

void liberarProvador(int id) {
    if (id < 0 || id >= TOTAL_PROVADORES || !provadores[id].ocupado) return;
    
    // Itens a comprar saem do estoque
    while (!pilhaVazia(&provadores[id].compra)) {
        Item item = desempilhar(&provadores[id].compra);
        removerItem(item.codigo);
    }

    // Itens a devolver voltam a ficar disponíveis
    while (!pilhaVazia(&provadores[id].devolucao)) {
        Item item = desempilhar(&provadores[id].devolucao);
        Item* estoqueItem = buscarItem(item.codigo);
        if (estoqueItem) estoqueItem->disponivel = 1;
    }

    provadores[id].ocupado = 0;
    printf("Provador %d foi liberado.\n", id);

    if (!filaVazia(&filaEspera)) {
        Cliente proximo = desenfileirar(&filaEspera);
        alocarProvador(proximo);
    }
}

int encontrarProvadorPorCPF(const char* cpf) {
	int i;
    for ( i = 0; i < TOTAL_PROVADORES; i++) {
        if (provadores[i].ocupado && strcmp(provadores[i].cliente.cpf, cpf) == 0)
            return i;
    }
    return -1;
}

int adicionarItemParaProvar(const char* cpf, Item* item) {
    int id = encontrarProvadorPorCPF(cpf);
    if (id == -1) return 0;
    empilhar(&provadores[id].provando, *item);
    item->disponivel = 0;
    return 1;
}

void imprimirMapaProvadores() {
	int i;
    for ( i = 0; i < TOTAL_PROVADORES; i++) {
        if (provadores[i].ocupado) {
            printf("Provador %d - CPF: %s\nItens provando:\n", i, provadores[i].cliente.cpf);
            imprimirPilha(&provadores[i].provando);
        }
    }
}

void imprimirFilaEspera() {
    imprimirFila(&filaEspera);
}
