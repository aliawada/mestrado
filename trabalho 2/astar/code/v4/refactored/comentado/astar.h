
#ifndef ASTAR_H
#define ASTAR_H

// Define um ponto no grid com coordenadas x e y
typedef struct {
    int x, y;
} Point;

// Estrutura de um nó usado no algoritmo A*
typedef struct {
    Point pt;             // posição no grid
    int g, h, f;          // custos: g (real), h (estimado), f (g + h)
    int parent_x, parent_y; // coordenadas do nó pai
    int in_open, in_closed; // flags para lista aberta e fechada
} Node;

// Matriz global de nós
extern Node nodes[10][10];

// Função principal do algoritmo A*
int a_star(int grid[][10], int width, int height, Point start, Point end, char visual[][10]);

// Imprime os valores g, h, f dos nós visitados
void print_g_f_h_table(int width, int height);

#endif
