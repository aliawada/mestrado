#include "arvoreBinaria.c"

int main() {
    arvore* r = cria_arvore_vazia();

    *r = insere_arvore_binaria(*r, 50);
    *r = insere_arvore_binaria(*r, 30);
    *r = insere_arvore_binaria(*r, 70);
    *r = insere_arvore_binaria(*r, 20);
    *r = insere_arvore_binaria(*r, 40);
    *r = insere_arvore_binaria(*r, 60);
    *r = insere_arvore_binaria(*r, 80);

    printf("Percurso in-ordem: ");
    in_ordem(*r);
    printf("\nPercurso pre-ordem: ");
    pre_ordem(*r);
    printf("\nPercurso pos-ordem: ");
    pos_ordem(*r);

    printf("\n\nQuantidade de elementos: %d", contar_elementos(*r));
    printf("\nSoma dos elementos: %d", soma_elementos(*r));
    printf("\nMaior elemento: %d", maximo(*r));
    printf("\nMenor elemento: %d", minimo(*r));

    printf("\n\nBuscando valor 60... ");
    arvore encontrado = busca_arvore_binaria(*r, 60);
    if (encontrado != NULL)
        printf("Encontrado: %d\n", encontrado->info);
    else
        printf("Nao encontrado.\n");

    printf("Removendo 70...\n");
    *r = remove_arvore_binaria(*r, 70);

    printf("Nova in-ordem: ");
    in_ordem(*r);

    libera_arvore(*r);
    free(r);

    return 0;
}

