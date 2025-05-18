
#ifndef ASTAR_H
#define ASTAR_H

// Estrutura que representa uma coordenada (x, y)
typedef struct {
    int x, y;
} Point;

// Estrutura de cada nó da grade (grafo implícito)
typedef struct {
    Point pt;             // Coordenada atual
    int g, h, f;          // Custos: g (real), h (estimado), f = g + h
    int parent_x, parent_y; // Coordenadas do nó "pai", usado para reconstruir o caminho
    int in_open, in_closed; // Flags que indicam se o nó está na lista aberta ou fechada
} Node;

// Matriz global com os nós do mapa
extern Node nodes[10][10];

// Função principal do A*
int a_star(int grid[][10], int width, int height, Point start, Point end, char visual[][10]);

#endif
