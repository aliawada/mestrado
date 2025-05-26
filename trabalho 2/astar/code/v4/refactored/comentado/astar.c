
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "astar.h"

// Constantes auxiliares
#define INF 999999 // Um valor bem grande usado como "infinito"
#define ABS(x) ((x) < 0 ? -(x) : (x)) // Calcula valor absoluto (sem sinal negativo)

// Aqui fica a matriz global que guarda todos os nós do mapa
Node nodes[10][10];

/// Essa função inicializa todos os nós da grade.
/// Ela também define quem é o início (S) e quem é o fim (E).
void initialize_nodes(int width, int height, int grid[][10], char visual[][10], Point start, Point end) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            // Se for 1 no grid, é obstáculo (#), senão é espaço livre
            visual[y][x] = grid[y][x] ? '#' : ' ';

            // Inicializa cada nó com dados padrão (infinito, sem pai ainda)
            nodes[y][x] = (Node){
                .pt = {x, y},
                .g = INF, .h = 0, .f = INF,
                .parent_x = -1, .parent_y = -1,
                .in_open = 0, .in_closed = 0
            };
        }
    }

    // Marcar inpicio e fim visualmente no mapa
    visual[start.y][start.x] = 'S';
    visual[end.y][end.x] = 'E';

    // Configura o nó inicial (g=0 porque não andamos nada ainda)
    nodes[start.y][start.x].g = 0;
    nodes[start.y][start.x].h = heuristic(start, end); // estimativa de distáncia até o fim
    nodes[start.y][start.x].f = nodes[start.y][start.x].h;
    nodes[start.y][start.x].parent_x = start.x;
    nodes[start.y][start.x].parent_y = start.y;
    nodes[start.y][start.x].in_open = 1; // não está na lista aberta (ainda será avaliado)
}

/// Essa função calcula a "distáncia" entre dois pontos
/// Aqui usamos a distáncia de Manhattan (sem diagonais)
int heuristic(Point a, Point b) {
    return ABS(a.x - b.x) + ABS(a.y - b.y);
}

/// Verifica se a posição (x, y) está dentro dos limites do mapa e é um caminho livre
int is_valid(int x, int y, int width, int height, int grid[][10]) {
    return x >= 0 && y >= 0 && x < width && y < height && grid[y][x] == 0;
}

/// Quando a gente chega no destino, essa função reconstrói o caminho final
/// e desenha ele no mapa usando '.'
void reconstruct_path(Point end, char visual[][10], Point start) {
    Point p = end;
    // Anda de trás pra frente, indo dos pais até o início
    while (!(nodes[p.y][p.x].parent_x == p.x && nodes[p.y][p.x].parent_y == p.y)) {
        if (!(p.x == end.x && p.y == end.y)) {
            visual[p.y][p.x] = '.'; // marca caminho
        }
        int px = nodes[p.y][p.x].parent_x;
        int py = nodes[p.y][p.x].parent_y;
        p.x = px;
        p.y = py;
    }
}

/// Atualiza os vizinhos (cima, baixo, esquerda, direita) do nó atual
void update_neighbors(int cx, int cy, int dx[], int dy[], int width, int height, int grid[][10], Point end) {
    int i;
    for (i = 0; i < 4; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        // Pula se for posição inválida ou já visitada
        if (!is_valid(nx, ny, width, height, grid)) continue;
        if (nodes[ny][nx].in_closed) continue;

        int tentative_g = nodes[cy][cx].g + 1; // custo de andar para vizinho

        // Se for melhor que o valor anterior ou não tiver sido visitado ainda
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

/// Escolhe o nó da lista aberta que tem o menor f (mais promissor)
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

/// Essa é a função principal do A*
/// Ela percorre o mapa e busca o menor caminho do início ao fim
int a_star(int grid[][10], int width, int height, Point start, Point end, char visual[][10]) {
    initialize_nodes(width, height, grid, visual, start, end);
    int dx[4] = {0, -1, 1, 0}; // deslocamentos em x (esquerda/direita)
    int dy[4] = {-1, 0, 0, 1}; // deslocamentos em y (cima/baixo)

    while (1) {
        int cx, cy;
        int min_f = get_lowest_f(width, height, &cx, &cy);
        if (cx == -1) return 0; // Se não tem mais nó aberto, não achou caminho

        // Marca o nó atual como fechado (já foi visitado)
        nodes[cy][cx].in_open = 0;
        nodes[cy][cx].in_closed = 1;

        // Se chegou ao destino, desenha o caminho final e termina
        if (cx == end.x && cy == end.y) {
            reconstruct_path(end, visual, start);
            return 1;
        }

        // Atualiza vizinhos do nó atual
        update_neighbors(cx, cy, dx, dy, width, height, grid, end);
    }
}
