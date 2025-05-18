
#include <stdio.h>
#include "astar.h"

extern Node nodes[10][10];

void print_g_f_h_table(int width, int height) {
    printf("\nTabela de custos (g, h, f) dos nós visitados:\n\n");
    int y, x;
    for ( y = 0; y < height; y++) {
        for ( x = 0; x < width; x++) {
            if (nodes[y][x].in_closed || nodes[y][x].in_open) {
                printf("[%d,%d] g=%d h=%d f=%d\n", y, x,
                       nodes[y][x].g, nodes[y][x].h, nodes[y][x].f);
            }
        }
    }
}
