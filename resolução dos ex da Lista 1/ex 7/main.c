#include "pilhaEstatica.c"
#include "pilhaEncadeada.c"

void testar_pilha_estatica() {
    printf("\n===== TESTE: PILHA ESTATICA =====\n");

    PilhaEstatica* p = criar_pilha_estatica();

    printf("Empilhando elementos: 5, 10, 15\n");
    push_estatica(p, 5);
    push_estatica(p, 10);
    push_estatica(p, 15);

    TipoItem* topoItem = topo_estatica(p);
    if (topoItem != NULL) {
        printf("Topo da pilha estatica: %d\n", *topoItem);
        free(topoItem);
    }

    printf("Tamanho da pilha estatica: %d\n", tamanho_estatica(p));

    printf("Desempilhando todos os elementos:\n");
    while (!vazia_estatica(p)) {
        TipoItem* removido = pop_estatica(p);
        if (removido != NULL) {
            printf("Desempilhado: %d\n", *removido);
            free(removido);
        }
    }

    printf("Pilha estatica vazia? %s\n", vazia_estatica(p) ? "Sim" : "Não");

    printf("Empilhando novamente: 20, 25\n");
    push_estatica(p, 20);
    push_estatica(p, 25);

    printf("Tamanho atual da pilha estatica: %d\n", tamanho_estatica(p));

    FPVazia_estatica(p);
    printf("Apos FPVazia, pilha estatica vazia? %s\n", vazia_estatica(p) ? "Sim" : "Nao");

    free(p);
}

void testar_pilha_encadeada() {
    printf("\n===== TESTE: PILHA ENCADEADA =====\n");

    PilhaEncadeada* p = criar_pilha_encadeada();

    printf("Empilhando elementos: 100, 200, 300\n");
    push_encadeada(p, 100);
    push_encadeada(p, 200);
    push_encadeada(p, 300);

    TipoItem* topoItem = topo_encadeada(p);
    if (topoItem != NULL) {
        printf("Topo da pilha encadeada: %d\n", *topoItem);
        free(topoItem);
    }

    printf("Tamanho da pilha encadeada: %d\n", tamanho_encadeada(p));

    printf("Desempilhando todos os elementos:\n");
    while (!vazia_encadeada(p)) {
        TipoItem* removido = pop_encadeada(p);
        if (removido != NULL) {
            printf("Desempilhado: %d\n", *removido);
            free(removido);
        }
    }

    printf("Pilha encadeada vazia? %s\n", vazia_encadeada(p) ? "Sim" : "Nao");

    printf("Empilhando novamente: 400, 500\n");
    push_encadeada(p, 400);
    push_encadeada(p, 500);

    printf("Tamanho atual da pilha encadeada: %d\n", tamanho_encadeada(p));

    FPVazia_encadeada(p);
    printf("Apos FPVazia, pilha encadeada vazia? %s\n", vazia_encadeada(p) ? "Sim" : "Nao");

    free(p);
}

int main() {
    testar_pilha_estatica();
    testar_pilha_encadeada();
    return 0;
}

