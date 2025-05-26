
#include <stdio.h>
#include <stdlib.h>
#include "astar.c"

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

int main() {
    int grid[MAP_HEIGHT][MAP_WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
    };

    Point start = {0, 0};
    Point end = {9, 9};

    char visual[MAP_HEIGHT][MAP_WIDTH];

    if (a_star(grid, MAP_WIDTH, MAP_HEIGHT, start, end, visual)) {
        printf("\nMapa com caminho encontrado:\n\n");
        int y, x;
        for ( y = 0; y < MAP_HEIGHT; y++) {
            for ( x = 0; x < MAP_WIDTH; x++) {
                printf("%c ", visual[y][x]);
            }
            printf("\n");
        }
    } else {
        printf("Nenhum caminho encontrado.\n");
    }

    return 0;
}
