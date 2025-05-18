
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "astar.h"

// Definições auxiliares
#define INF 999999
#define ABS(x) ((x) < 0 ? -(x) : (x))

// Matriz global que armazena os dados dos nós
Node nodes[10][10];

/// Inicializa os nós da matriz e o mapa visual com base no grid original
/// Define os valores iniciais dos custos g, h e f, e marca o nó inicial como aberto
void initialize_nodes(int width, int height, int grid[][10], char visual[][10], Point start, Point end) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            visual[y][x] = grid[y][x] ? '#' : ' ';
            nodes[y][x] = (Node){.pt = {x, y}, .g = INF, .h = 0, .f = INF, .parent_x = -1, .parent_y = -1, .in_open = 0, .in_closed = 0};
        }
    }
    // Marcar início e fim no mapa
    visual[start.y][start.x] = 'S';
    visual[end.y][end.x] = 'E';

    // Configuração inicial do nó de partida
    nodes[start.y][start.x].g = 0;
    nodes[start.y][start.x].h = heuristic(start, end);
    nodes[start.y][start.x].f = nodes[start.y][start.x].h;
    nodes[start.y][start.x].parent_x = start.x;
    nodes[start.y][start.x].parent_y = start.y;
    nodes[start.y][start.x].in_open = 1;
}

/// Calcula a heurística (distância de Manhattan) entre dois pontos
int heuristic(Point a, Point b) {
    return ABS(a.x - b.x) + ABS(a.y - b.y);
}

/// Verifica se uma coordenada é válida e não é obstáculo
int is_valid(int x, int y, int width, int height, int grid[][10]) {
    return x >= 0 && y >= 0 && x < width && y < height && grid[y][x] == 0;
}

/// Reconstrói o caminho final percorrido, alterando a matriz visual com '.'
void reconstruct_path(Point end, char visual[][10], Point start) {
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

/// Atualiza os vizinhos válidos de um nó (cima, baixo, esquerda, direita)
void update_neighbors(int cx, int cy, int dx[], int dy[], int width, int height, int grid[][10], Point end) {
    int i;
    for (i = 0; i < 4; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (!is_valid(nx, ny, width, height, grid)) continue;
        if (nodes[ny][nx].in_closed) continue;

        int tentative_g = nodes[cy][cx].g + 1;

        // Atualiza o nó se ele ainda não estiver aberto ou se encontrou um caminho melhor
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

/// Retorna a coordenada do nó com menor f na lista aberta
int get_lowest_f(int width, int height, int* out_x, int* out_y) {
    int min_f = INF, x, y;
    *out_x = -1;
    *out_y = -1;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (nodes[y][x].in_open && nodes[y][x].f < min_f) {
                min_f = nodes[y][x].f;
                *out_x = x;
                *out_y = y;
            }
        }
    }
    return min_f;
}

/// Função principal do algoritmo A*, que busca o menor caminho entre dois pontos
int a_star(int grid[][10], int width, int height, Point start, Point end, char visual[][10]) {
    initialize_nodes(width, height, grid, visual, start, end);
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {-1, 0, 0, 1};

    while (1) {
        int cx, cy;
        int min_f = get_lowest_f(width, height, &cx, &cy);
        if (cx == -1) return 0; // Nenhum caminho encontrado

        nodes[cy][cx].in_open = 0;
        nodes[cy][cx].in_closed = 1;

        if (cx == end.x && cy == end.y) {
            reconstruct_path(end, visual, start);
            return 1;
        }

        update_neighbors(cx, cy, dx, dy, width, height, grid, end);
    }
}
