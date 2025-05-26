
#include <stdio.h>
#include <stdlib.h>
#include "astar.c"
#include "node_costs.c"
#include "visual_graph.c"

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// Função principal
int main() {
    // Mapa com 0 = caminho livre e 1 = obstáculo
    int grid[MAP_HEIGHT][MAP_WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
    };

    // Ponto de início e fim
    Point start = {0, 0};
    Point end = {9, 9};

    // Matriz visual que será preenchida pelo algoritmo
    char visual[MAP_HEIGHT][MAP_WIDTH];

    // Mostra graficamente os nós do grafo
    print_graph_coords(grid);

    // Chama o algoritmo A*
    if (a_star(grid, MAP_WIDTH, MAP_HEIGHT, start, end, visual)) {
        printf("\nMapa com caminho encontrado:\n\n");
        int y, x;
        for (y = 0; y < MAP_HEIGHT; y++) {
            for (x = 0; x < MAP_WIDTH; x++) {
                printf("%c ", visual[y][x]);
            }
            printf("\n");
        }

        // Mostra os custos dos nós visitados
        print_g_f_h_table(MAP_WIDTH, MAP_HEIGHT);
    } else {
        printf("Nenhum caminho encontrado.\n");
    }

    return 0;
}
