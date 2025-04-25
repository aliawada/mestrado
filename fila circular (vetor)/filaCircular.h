#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#include <stdlib.h>
#include <stdio.h>

int vazia(Fila* f);
int cheia(Fila* f);
void enqueue(Fila* f, TipoItem x);
TipoItem* dequeue(Fila * f);

#endif
