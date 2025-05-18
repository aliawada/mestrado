
#include <stdio.h>
#include <stdlib.h>
#include "astar.h"

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// Essa função imprime a matriz (grid) mostrando as coordenadas dos nós livres
// Isso ajuda a visualizar a estrutura como um grafo
void print_graph_coords(int grid[MAP_HEIGHT][MAP_WIDTH]) {
    printf("Visualização do grafo (coordenadas dos nós livres):\n\n");
    int y, x;
    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            if (grid[y][x] == 0)
                printf("[%d,%d] ", y, x);
            else
                printf("   #   ");
        }
        printf("\n");
        for (x = 0; x < MAP_WIDTH; x++) {
            if (grid[y][x] == 0 && x < MAP_WIDTH - 1 && grid[y][x + 1] == 0)
                printf("   |   ");
            else
                printf("       ");
        }
        printf("\n");
    }
    printf("\n");
}
