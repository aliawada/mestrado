#ifndef PROVADOR_H
#define PROVADOR_H

#include "fila.h"
#include "pilha.h"

#define TOTAL_PROVADORES 6

typedef struct {
    int id;
    int ocupado;
    Cliente cliente;
    Pilha provando;
    Pilha compra;
    Pilha devolucao;
} Provador;

void inicializarProvadores();
int alocarProvador(Cliente c);
void liberarProvador(int id);
int encontrarProvadorPorCPF(const char* cpf);
int adicionarItemParaProvar(const char* cpf, Item* item);
void imprimirMapaProvadores();
void imprimirFilaEspera();

#endif
