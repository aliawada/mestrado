#include "listaEncadeadaComCabecaECauda.c"

#include <ctype.h>
#include <string.h>

#ifdef _WIN32
    #define LIMPA_TELA "cls"
#else
    #define LIMPA_TELA "clear"
#endif

// Exibe o menu principal
void menu() {
    printf("==== MENU ====\n");
    printf("1. Inserir elemento\n");
    printf("2. Remover elemento\n");
    printf("3. Imprimir lista\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

// Aguarda ENTER do usuário
void pausa() {
    printf("\nPressione ENTER para continuar...");
    fflush(stdin); // Windows (em alguns casos)
    while (getchar() != '\n'); // garante que o ENTER é lido corretamente
    system(LIMPA_TELA);
}

// Verifica se uma string representa um número inteiro válido
int entrada_e_inteiro(const char* entrada) {
    int i;
	for (i = 0; entrada[i] != '\0'; i++) {
    	if (!isdigit(entrada[i]) && !(i == 0 && entrada[i] == '-')) {
        	return 0;
    	}
	}
    return 1;
}

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
