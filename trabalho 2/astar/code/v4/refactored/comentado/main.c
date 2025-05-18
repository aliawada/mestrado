// v4 refactored comentado
#include <stdio.h>
#include <stdlib.h>
#include "astar.c"
#include "node_costs.c"
#include "visual_graph.c"

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// Função que mostra as coordenadas dos nós livres do grid como um grafo
void print_graph_coords(int grid[MAP_HEIGHT][MAP_WIDTH]);

int main() {
    // Grid do mapa: 0 = livre, 1 = obstáculo
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

    // Ponto de início e fim do caminho
    Point start = {0, 0};
    Point end = {9, 9};

    char visual[MAP_HEIGHT][MAP_WIDTH];

    // Mostrar o grafo por coordenadas
    print_graph_coords(grid);

    // Executar o algoritmo A*
    if (a_star(grid, MAP_WIDTH, MAP_HEIGHT, start, end, visual)) {
        printf("\nMapa com caminho encontrado:\n\n");

        int y, x;
        // Imprimir visualmente o caminho
        for (y = 0; y < MAP_HEIGHT; y++) {
            for (x = 0; x < MAP_WIDTH; x++) {
                printf("%c ", visual[y][x]);
            }
            printf("\n");
        }

        // Mostrar tabela de custos g, h e f
        print_g_f_h_table(MAP_WIDTH, MAP_HEIGHT);

        extern Node nodes[10][10];
        int total_path_cost = 0;
        Point p = end;

        // Soma do custo real (g) de cada nó do caminho
        while (!(nodes[p.y][p.x].parent_x == p.x && nodes[p.y][p.x].parent_y == p.y)) {
            total_path_cost += nodes[p.y][p.x].g;
            int px = nodes[p.y][p.x].parent_x;
            int py = nodes[p.y][p.x].parent_y;
            p.x = px;
            p.y = py;
        }
        total_path_cost += nodes[p.y][p.x].g;

        printf("\nSoma total dos custos dos nós no caminho: %d\n", total_path_cost);
    } else {
        printf("Nenhum caminho encontrado.\n");
    }

    return 0;
}
