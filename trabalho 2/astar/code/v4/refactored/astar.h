
#ifndef ASTAR_H
#define ASTAR_H

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pt;
    int g, h, f;
    int parent_x, parent_y;
    int in_open, in_closed;
} Node;

extern Node nodes[10][10];

int a_star(int grid[][10], int width, int height, Point start, Point end, char visual[][10]);

void print_g_f_h_table(int width, int height);

#endif
