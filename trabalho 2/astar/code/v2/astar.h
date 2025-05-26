
#ifndef ASTAR_H
#define ASTAR_H

typedef struct {
    int x, y;
} Point;

int a_star(int grid[][10], int width, int height, Point start, Point end, char visual[][10]);

#endif
