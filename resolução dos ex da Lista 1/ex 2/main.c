#include "listaEstatica.c"

int main() {
    Lista* lista1 = cria_lista_vazia();
    Lista* lista2 = cria_lista_vazia();

    if (!lista1 || !lista2) return 1;

    // Teste: Inserir_Inicio
    inserir_inicio(lista1, 30);
    inserir_inicio(lista1, 20);
    inserir_inicio(lista1, 10);
    printf("\nLista apos inserir no inicio:\n");
    imprime(lista1);

    // Teste: Inserir_Fim (insere)
    insere(lista1, 40);
    insere(lista1, 50);
    printf("\nLista apos inserir no fim:\n");
    imprime(lista1);

    // Teste: Inserep
    inserep(lista1, 2, 25); // inserir 25 na posicao 2
    printf("\nLista apos inserir 25 na posicao 2:\n");
    imprime(lista1);

    // Teste: Busca
    int pos = busca(lista1, 25);
    printf("\nPosicao do elemento 25: %d\n", pos);

    // Teste: Retira por posicao
    TipoItem removido = retira_pos(lista1, 2);
    printf("\nElemento retirado da posicao 2: %d\n", removido);
    imprime(lista1);

    // Teste: Ordenar
    ordenar(lista1);
    printf("\nLista ordenada:\n");
    imprime(lista1);

    // Teste: Concatenar
    insere(lista2, 100);
    insere(lista2, 200);
    printf("\nLista 2 antes da concatenacao:\n");
    imprime(lista2);
    concatenar(lista1, lista2);
    printf("\nLista 1 apos concatenar com lista 2:\n");
    imprime(lista1);

    // Teste: Remover item (retira)
    retira(lista1, 100);
    printf("\nLista apos remover 100:\n");
    imprime(lista1);

    // Teste: Vazia e FLVazia
    printf("\nEsvaziando lista...\n");
    FLVazia(lista1);
    printf("Lista vazia? %s\n", vazia(lista1) ? "Sim" : "Nao");
    imprime(lista1);

    // Liberando memoria
    free(lista1);
    free(lista2);

    return 0;
}

