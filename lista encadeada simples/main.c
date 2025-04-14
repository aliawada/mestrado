#include "listaEncadeadaSimples.c"

int main() {
    Lista* minhaLista = cria_lista_vazia();

    // Inserções
    minhaLista = insere(minhaLista, 10);
    minhaLista = insere(minhaLista, 20);
    minhaLista = insere(minhaLista, 30);

    printf("Lista apos insercoes:\n");
    imprime(minhaLista);

    // Remoção
    minhaLista = retira(minhaLista, 20);

    printf("Lista apos remocao de 20:\n");
    imprime(minhaLista);

    // Teste de esvaziamento
    while (!vazia(minhaLista)) {
        minhaLista = retira(minhaLista, minhaLista->info);
    }

    printf("Lista apos remover todos os elementos:\n");
    imprime(minhaLista);

    return 0;
}

