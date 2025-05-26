
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "astar.h"

#define INF 999999
#define ABS(x) ((x) < 0 ? -(x) : (x))

Node nodes[10][10];

int is_valid(int x, int y, int width, int height, int grid[][10]) {
    return x >= 0 && y >= 0 && x < width && y < height && grid[y][x] == 0;
}

int heuristic(Point a, Point b) {
    return ABS(a.x - b.x) + ABS(a.y - b.y);
}

void reconstruct_path(Node nodes[][10], Point end, char visual[][10], Point start) {
    Point p = end;
    while (!(nodes[p.y][p.x].parent_x == p.x && nodes[p.y][p.x].parent_y == p.y)) {
        if (!(p.x == end.x && p.y == end.y))
            visual[p.y][p.x] = '.';
        int px = nodes[p.y][p.x].parent_x;
        int py = nodes[p.y][p.x].parent_y;
        p.x = px;
        p.y = py;
    }
}

int a_star(int grid[][10], int width, int height, Point start, Point end, char visual[][10]) {
	int y, x;
    for ( y = 0; y < height; y++)
        for ( x = 0; x < width; x++)
            visual[y][x] = grid[y][x] ? '#' : ' ';

    visual[start.y][start.x] = 'S';
    visual[end.y][end.x] = 'E';

    nodes[start.y][start.x].pt = start;
    nodes[start.y][start.x].g = 0;
    nodes[start.y][start.x].h = heuristic(start, end);
    nodes[start.y][start.x].f = nodes[start.y][start.x].h;
    nodes[start.y][start.x].parent_x = start.x;
    nodes[start.y][start.x].parent_y = start.y;
    nodes[start.y][start.x].in_open = 1;

    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {-1, 0, 0, 1};

    while (1) {
        int min_f = INF, cx = -1, cy = -1, y, x;
        for ( y = 0; y < height; y++) {
            for ( x = 0; x < width; x++) {
                if (nodes[y][x].in_open && nodes[y][x].f < min_f) {
                    min_f = nodes[y][x].f;
                    cx = x;
                    cy = y;
                }
            }
        }

        if (cx == -1) return 0;

        nodes[cy][cx].in_open = 0;
        nodes[cy][cx].in_closed = 1;

        if (cx == end.x && cy == end.y) {
            reconstruct_path(nodes, end, visual, start);
            return 1;
        }
		int i;
        for ( i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (!is_valid(nx, ny, width, height, grid)) continue;
            if (nodes[ny][nx].in_closed) continue;

            int tentative_g = nodes[cy][cx].g + 1;

            if (!nodes[ny][nx].in_open || tentative_g < nodes[ny][nx].g) {
                nodes[ny][nx].pt.x = nx;
                nodes[ny][nx].pt.y = ny;
                nodes[ny][nx].g = tentative_g;
                nodes[ny][nx].h = heuristic(nodes[ny][nx].pt, end);
                nodes[ny][nx].f = nodes[ny][nx].g + nodes[ny][nx].h;
                nodes[ny][nx].parent_x = cx;
                nodes[ny][nx].parent_y = cy;
                nodes[ny][nx].in_open = 1;
            }
        }
    }
}
