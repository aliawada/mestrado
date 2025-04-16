#include "listaEncadeadaComCabecaECauda.c"
#include "menu.c"

int main() {
    Lista* minhaLista = cria_lista_vazia();
    if (minhaLista == NULL) return 1;

    char entrada[100];
    int opcao = -1, valor;

    system(LIMPA_TELA);

    do {
        menu();
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0'; // remove newline

        if (!entrada_e_inteiro(entrada)) {
            printf("Entrada invalida! Digite um numero.\n");
            pausa();
            continue;
        }

        opcao = atoi(entrada);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Valor invalido.\n");
                    while (getchar() != '\n'); // limpa buffer
                    pausa();
                    break;
                }
                while (getchar() != '\n'); // limpa o \n do buffer
                minhaLista = insere(minhaLista, valor);
                pausa();
                break;

            case 2:
                printf("Digite o valor a ser removido: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Valor invalido.\n");
                    while (getchar() != '\n'); // limpa o \n do buffer	
                    while (getchar() != '\n');
                    pausa();
                    break;
                }
                while (getchar() != '\n'); // limpa o \n do buffer
                minhaLista = retira(minhaLista, valor);
                pausa();
                break;

            case 3:
                printf("Lista atual:\n");
                imprime(minhaLista);
                pausa();
                break;

            case 4:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                pausa();
                break;
        }

    } while (opcao != 4);

    libera(minhaLista);
    return 0;
}
