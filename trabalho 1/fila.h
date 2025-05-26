#ifndef FILA_H
#define FILA_H

typedef struct Cliente {
    char cpf[15];
} Cliente;

typedef struct NoFila {
    Cliente cliente;
    struct NoFila* prox;
} NoFila;

typedef struct {
    NoFila* inicio;
    NoFila* fim;
} Fila;

void inicializarFila(Fila* f);
void enfileirar(Fila* f, Cliente c);
Cliente desenfileirar(Fila* f);
int filaVazia(Fila* f);
void imprimirFila(Fila* f);

#endif
