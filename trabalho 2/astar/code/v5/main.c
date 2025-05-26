
#include <stdio.h>
#include <stdlib.h>
#include "astar.c"
#include "node_costs.c"
#include "visual_graph.c"

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

void print_graph_coords(int grid[MAP_HEIGHT][MAP_WIDTH]);

extern int alternative_g_values[100];
extern int alternative_g_count;

int main() {
    int grid[MAP_HEIGHT][MAP_WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
    };

    Point start = {0, 0};
    Point end = {9, 9};

    char visual[MAP_HEIGHT][MAP_WIDTH];

    print_graph_coords(grid);

    if (a_star(grid, MAP_WIDTH, MAP_HEIGHT, start, end, visual)) {
        printf("\nMapa com caminho encontrado:\n\n");

        int y, x;
        for (y = 0; y < MAP_HEIGHT; y++) {
            for (x = 0; x < MAP_WIDTH; x++) {
                printf("%c ", visual[y][x]);
            }
            printf("\n");
        }

        print_g_f_h_table(MAP_WIDTH, MAP_HEIGHT);

        extern Node nodes[10][10];
        int total_path_cost = 0;
        Point p = end;
        while (!(nodes[p.y][p.x].parent_x == p.x && nodes[p.y][p.x].parent_y == p.y)) {
            total_path_cost += nodes[p.y][p.x].g;
            int px = nodes[p.y][p.x].parent_x;
            int py = nodes[p.y][p.x].parent_y;
            p.x = px;
            p.y = py;
        }
        total_path_cost += nodes[p.y][p.x].g;

        printf("\n? Caminho escolhido até o destino: g = %d\n", nodes[end.y][end.x].g);

		printf("\n? Outros caminhos possíveis até o destino (com custo maior):\n");
		
		int encontrou_alternativa = 0;
		for (x = 0; x < alternative_g_count; x++) {
		    if (alternative_g_values[x] > nodes[end.y][end.x].g) {
		        printf("  Caminho alternativo %d: g = %d\n", x + 1, alternative_g_values[x]);
		        encontrou_alternativa = 1;
		    }
		}
		if (!encontrou_alternativa) {
		    printf("  Nenhum caminho alternativo com custo maior foi encontrado.\n");
		}

    } else {
        printf("Nenhum caminho encontrado.\n");
    }

    return 0;
}
