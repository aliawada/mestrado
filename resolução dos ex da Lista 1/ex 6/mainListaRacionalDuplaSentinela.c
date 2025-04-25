#include "listaRacionalDuplaSentinela.c"
#include "racional.c"

int main() {
    ListaRacional* lista = cria_lista();

    // Inserções
    inserir_fim(lista, criar(1, 2));
    inserir_fim(lista, criar(2, 3));
    inserir_inicio(lista, criar(3, 4));
    inserep(lista, 1, criar(5, 6)); // insere 5/6 na posição 1

    printf("\nLista apos insercoes:\n");
    imprime_lista(lista);

    // Busca
    RACIONAL* alvo = criar(2, 3);
    int pos = busca(lista, alvo);
    printf("\nPosicao do elemento 2/3: %d\n", pos);
    limpar(alvo);

    // Soma de elementos nas posições 0 e 1
    RACIONAL* soma = soma_elementos(lista, 0, 1);
    printf("\nSoma dos elementos nas posicoes 0 e 1: ");
    imprimir(soma);
    limpar(soma);

    // Multiplicação dos elementos nas posições 1 e 2
    RACIONAL* mult = multiplica_elementos(lista, 1, 2);
    printf("\nMultiplicacao dos elementos nas posicoes 1 e 2: ");
    imprimir(mult);
    limpar(mult);

    // Remoção por valor
    RACIONAL* rrem = criar(3, 4);
    retira(lista, rrem);
    printf("\nLista apos remover 3/4:\n");
    imprime_lista(lista);
    limpar(rrem);

    // Remoção por posição
    RACIONAL* retirado = NULL;
    retira_pos(lista, 1, &retirado);
    printf("\nElemento removido da posicao 1: ");
    imprimir(retirado);
    limpar(retirado);
    imprime_lista(lista);

    // Limpeza
    FLVazia(lista);
    printf("\nLista apos esvaziar:\n");
    imprime_lista(lista);

    // Liberação da sentinela e da lista
    free(lista->sentinela);
    free(lista);

    return 0;
}

