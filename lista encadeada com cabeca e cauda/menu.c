#include "menu.h"

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


