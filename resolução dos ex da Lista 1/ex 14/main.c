#include <stdio.h>
#include <stdlib.h>

// ------------------------ Estrutura Lista Generalizada ------------------------

typedef enum {ATOMO, SUBLISTA} TipoTAG;

typedef struct ListaGen {
    TipoTAG tag;
    union {
        char atomo;
        struct ListaGen* sublista;
    } ca;
    struct ListaGen* cd;
} ListaGen;

ListaGen* cria_atomo(char valor) {
    ListaGen* novo = (ListaGen*)malloc(sizeof(ListaGen));
    novo->tag = ATOMO;
    novo->ca.atomo = valor;
    novo->cd = NULL;
    return novo;
}

ListaGen* cria_sublista(ListaGen* sublista) {
    ListaGen* novo = (ListaGen*)malloc(sizeof(ListaGen));
    novo->tag = SUBLISTA;
    novo->ca.sublista = sublista;
    novo->cd = NULL;
    return novo;
}

void imprimir_lista(ListaGen* l) {
    if (l == NULL) return;
    printf("(");
    while (l != NULL) {
        if (l->tag == ATOMO) {
            printf("%c", l->ca.atomo);
        } else {
            imprimir_lista(l->ca.sublista);
        }
        if (l->cd != NULL) printf(", ");
        l = l->cd;
    }
    printf(")");
}

void liberar_lista(ListaGen* l) {
    while (l != NULL) {
        ListaGen* temp = l;
        if (l->tag == SUBLISTA) {
            liberar_lista(l->ca.sublista);
        }
        l = l->cd;
        free(temp);
    }
}

// ------------------------ Exemplo de Uso ------------------------

int main() {
    printf("\n--- Representacao de Listas Generalizadas ---\n");

    // Exemplo a) X = ( (A, B), ( (C, D), E ) )
    ListaGen* A = cria_atomo('A');
    ListaGen* B = cria_atomo('B');
    A->cd = B;

    ListaGen* sub1 = cria_sublista(A);

    ListaGen* C = cria_atomo('C');
    ListaGen* D = cria_atomo('D');
    C->cd = D;

    ListaGen* sub2_interno = cria_sublista(C);

    ListaGen* E = cria_atomo('E');
    sub2_interno->cd = E;

    ListaGen* sub2 = cria_sublista(sub2_interno);

    sub1->cd = sub2;

    printf("\nExemplo (a) : ");
    imprimir_lista(sub1);
    printf("\n");

    liberar_lista(sub1);

    // Exemplo b) X = ( D, ( E, ( F ) ), ( G, ( H, ( I ) ), ( J, ( K ), ( L ) ), ( M ) ) )

    ListaGen* Dd = cria_atomo('D');

    ListaGen* E2 = cria_atomo('E');
    ListaGen* F = cria_atomo('F');
    ListaGen* subF = cria_sublista(F);
    E2->cd = subF;

    ListaGen* subE = cria_sublista(E2);

    ListaGen* G = cria_atomo('G');

    ListaGen* H = cria_atomo('H');
    ListaGen* I = cria_atomo('I');
    H->cd = cria_sublista(I);

    ListaGen* subH = cria_sublista(H);

    ListaGen* J = cria_atomo('J');
    ListaGen* K = cria_atomo('K');
    ListaGen* subK = cria_sublista(K);
    J->cd = subK;

    ListaGen* L = cria_atomo('L');
    subK->cd = cria_sublista(L);

    ListaGen* subJ = cria_sublista(J);

    ListaGen* M = cria_atomo('M');
    ListaGen* subM = cria_sublista(M);

    G->cd = subH;
    subH->cd = subJ;
    subJ->cd = subM;

    ListaGen* subG = cria_sublista(G);

    Dd->cd = subE;
    subE->cd = subG;

    printf("\nExemplo (b) : ");
    imprimir_lista(Dd);
    printf("\n");

    liberar_lista(Dd);

    return 0;
}

