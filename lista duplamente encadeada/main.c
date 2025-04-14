#include "listaDuplamenteEncadeada.c"

int main() {
    Lista* minhaLista = cria_lista_vazia();

    minhaLista = insere(minhaLista, 10);
    minhaLista = insere(minhaLista, 20);
    minhaLista = insere(minhaLista, 30);

    printf("Lista apos insercoes:\n");
    imprime(minhaLista); // Esperado: [30 20 10]

    minhaLista = retira(minhaLista, 20);
    printf("Lista apos remover 20:\n");
    imprime(minhaLista); // Esperado: [30 10]

    minhaLista = retira(minhaLista, 30);
    minhaLista = retira(minhaLista, 10);

    printf("Lista apos remover todos:\n");
    imprime(minhaLista); // Esperado: Lista vazia

    return 0;
}
