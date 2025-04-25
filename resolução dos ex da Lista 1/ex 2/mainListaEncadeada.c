#include "listaEncadeada.c"

int main() {
    Lista* lista1 = cria_lista_vazia();
    Lista* lista2 = cria_lista_vazia();

    // Inserir_Inicio
    lista1 = inserir_inicio(lista1, 30);
    lista1 = inserir_inicio(lista1, 20);
    lista1 = inserir_inicio(lista1, 10);
    printf("\nLista apos inserir no inicio:\n");
    imprime(lista1);

    // Inserir_Fim
    lista1 = inserir_fim(lista1, 40);
    lista1 = inserir_fim(lista1, 50);
    printf("\nLista apos inserir no fim:\n");
    imprime(lista1);

    // Inserep
    lista1 = inserep(lista1, 2, 25);
    printf("\nLista apos inserir 25 na posicao 2:\n");
    imprime(lista1);

    // Busca
    int pos = busca(lista1, 25);
    printf("\nPosicao do elemento 25: %d\n", pos);

    // Retira por posição
    TipoItem removido;
    lista1 = retira_pos(lista1, 2, &removido);
    printf("\nElemento retirado da posicao 2: %d\n", removido);
    imprime(lista1);

    // Ordenar
    ordenar(&lista1);
    printf("\nLista ordenada:\n");
    imprime(lista1);

    // Concatenar
    lista2 = inserir_fim(lista2, 100);
    lista2 = inserir_fim(lista2, 200);
    printf("\nLista 2 antes da concatenacao:\n");
    imprime(lista2);
    concatenar(&lista1, lista2);
    printf("\nLista 1 apos concatenacao com lista 2:\n");
    imprime(lista1);

    // Remover item
    lista1 = retira(lista1, 100);
    printf("\nLista apos remover 100:\n");
    imprime(lista1);

    // FLVazia e vazia
    printf("\nEsvaziando lista...\n");
    FLVazia(&lista1);
    printf("Lista vazia? %s\n", vazia(lista1) ? "Sim" : "Não");
    imprime(lista1);

    return 0;
}

