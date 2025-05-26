
#include <stdio.h>
#include "astar.h"

// A matriz nodes foi declarada como global no astar.c
extern Node nodes[10][10];

// Esta função imprime os valores g, h e f dos nós que foram abertos ou fechados.
// Serve para entender como o algoritmo A* tomou suas decisões.
void print_g_f_h_table(int width, int height) {
    printf("\nTabela de custos (g, h, f) dos nós visitados:\n\n");
    int y, x;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (nodes[y][x].in_closed || nodes[y][x].in_open) {
                printf("[%d,%d] g=%d h=%d f=%d\n", y, x,
                       nodes[y][x].g, nodes[y][x].h, nodes[y][x].f);
            }
        }
    }
}
