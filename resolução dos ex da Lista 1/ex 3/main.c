#include "listaEncadeadaComNo.c"

int main() {
    Lista* lista1 = cria_lista_vazia();
    Lista* lista2 = cria_lista_vazia();

    // Inserir no início
    inserir_inicio(lista1, 30);
    inserir_inicio(lista1, 20);
    inserir_inicio(lista1, 10);
    printf("\nLista apos insercoes no inicio:\n");
    imprime(lista1);

    // Inserir no fim
    inserir_fim(lista1, 40);
    inserir_fim(lista1, 50);
    printf("\nLista apos insercoes no fim:\n");
    imprime(lista1);

    // Inserir em posição específica
    inserep(lista1, 2, 25); // entre 20 e 30
    printf("\nLista apos inserir 25 na posicao 2:\n");
    imprime(lista1);

    // Busca
    int pos = busca(lista1, 25);
    printf("\nPosicao do elemento 25: %d\n", pos);

    // Remover por posição
    TipoItem removido;
    retira_pos(lista1, 2, &removido);
    printf("\nElemento removido da posicao 2: %d\n", removido);
    imprime(lista1);

    // Ordenar
    ordenar(lista1);
    printf("\nLista ordenada:\n");
    imprime(lista1);

    // Concatenar
    inserir_fim(lista2, 100);
    inserir_fim(lista2, 200);
    printf("\nLista 2 antes da concatenacao:\n");
    imprime(lista2);

    concatenar(lista1, lista2);
    printf("\nLista 1 apos concatenar com Lista 2:\n");
    imprime(lista1);

    // Remover item
    retira(lista1, 100);
    printf("\nLista apos remover 100:\n");
    imprime(lista1);

    // Esvaziar lista
    printf("\nEsvaziando Lista 1...\n");
    FLVazia(lista1);
    printf("Lista 1 esta vazia? %s\n", vazia(lista1) ? "Sim" : "Não");
    imprime(lista1);

    // Liberar memória
    free(lista1->sentinela);
    free(lista1);

    return 0;
}

