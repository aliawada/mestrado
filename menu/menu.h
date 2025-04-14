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

// Aguarda ENTER do usu�rio
void pausa() {
    printf("\nPressione ENTER para continuar...");
    fflush(stdin); // Windows (em alguns casos)
    while (getchar() != '\n'); // garante que o ENTER � lido corretamente
    system(LIMPA_TELA);
}

// Verifica se uma string representa um n�mero inteiro v�lido
int entrada_e_inteiro(const char* entrada) {
    int i;
	for (i = 0; entrada[i] != '\0'; i++) {
    	if (!isdigit(entrada[i]) && !(i == 0 && entrada[i] == '-')) {
        	return 0;
    	}
	}
    return 1;
}


