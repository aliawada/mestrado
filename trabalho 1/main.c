#include <stdio.h>
#include <string.h>
#include "vestuario.c"
#include "provador.c"
#include "pilha.c"
#include "fila.c"

int main() {
    int opcao;
    char cpf[15];
    Cliente cliente;
    Item item;
    int codigo;
    int escolha;

    inicializarEstoque();
    inicializarProvadores();

    do {
        printf("\n--- Menu ---\n");
        printf("1. Carregar Arquivo Inicial\n");
        printf("2. Inserir Item\n");
        printf("3. Remover Item\n");
        printf("4. Buscar Endereço do Item\n");
        printf("5. Locar Provador\n");
        printf("6. Liberar Provador\n");
        printf("7. Provar Item\n");
        printf("8. Imprimir Mapa de Provadores\n");
        printf("9. Imprimir Fila de Espera\n");
        printf("0. Sair\n> ");
        if (scanf("%d", &opcao) != 1) break;
        getchar();

        switch(opcao) {
            case 1:
                carregarArquivoTexto("estoque.txt");
                break;
            case 2:
                printf("Codigo: "); scanf("%d", &item.codigo); getchar();
                printf("Tipo: "); fgets(item.tipo, 50, stdin); item.tipo[strcspn(item.tipo, "\n")] = '\0';
                printf("Marca: "); fgets(item.marca, 50, stdin); item.marca[strcspn(item.marca, "\n")] = '\0';
                printf("Cor: "); fgets(item.cor, 30, stdin); item.cor[strcspn(item.cor, "\n")] = '\0';
                printf("Tamanho: "); scanf("%d", &item.tamanho);
                printf("Setor: "); scanf("%d", &item.setor);
                printf("Arara: "); scanf("%d", &item.arara);
                item.disponivel = 1;
                inserirItem(item);
                break;
            case 3:
                printf("Codigo do item a remover: ");
                scanf("%d", &codigo);
                removerItem(codigo);
                break;
            case 4:
                printf("Codigo do item: ");
                scanf("%d", &codigo);
                Item* encontrado = buscarItem(codigo);
                if (encontrado && encontrado->disponivel)
                    printf("Setor %d - Arara %d\n", encontrado->setor, encontrado->arara);
                else
                    printf("Item indisponível ou inexistente.\n");
                break;
            case 5:
                printf("CPF: "); fgets(cpf, 15, stdin); cpf[strcspn(cpf, "\n")] = '\0';
                strcpy(cliente.cpf, cpf);
                alocarProvador(cliente);
                break;
            case 6:
                printf("CPF: "); fgets(cpf, 15, stdin); cpf[strcspn(cpf, "\n")] = '\0';
                int id = encontrarProvadorPorCPF(cpf);
                if (id != -1) {
                    while (!pilhaVazia(&provadores[id].provando)) {
                        Item item = desempilhar(&provadores[id].provando);
                        printf("Item %d (%s - %s)\n", item.codigo, item.tipo, item.marca);
                        printf("Deseja COMPRAR (1) ou DEVOLVER (2)? ");
                        if (scanf("%d", &escolha) != 1 || (escolha != 1 && escolha != 2)) {
                            printf("Entrada inválida. Item será DEVOLVIDO por padrão.\n");
                            escolha = 2;
                            while (getchar() != '\n');
                        } else {
                            getchar();
                        }
                        if (escolha == 1) {
                            empilhar(&provadores[id].compra, item);
                        } else {
                            empilhar(&provadores[id].devolucao, item);
                        }
                    }
                    liberarProvador(id);
                } else {
                    printf("Cliente não está em provador.\n");
                }
                break;
            case 7:
                printf("CPF: "); fgets(cpf, 15, stdin); cpf[strcspn(cpf, "\n")] = '\0';
                printf("Codigo do item: "); scanf("%d", &codigo);
                Item* p = buscarItem(codigo);
                if (p && p->disponivel) {
                    if (adicionarItemParaProvar(cpf, p))
                        printf("Item %d adicionado ao provador para o cliente %s.\n", codigo, cpf);
                    else
                        printf("Cliente %s não está em provador.\n", cpf);
                } else {
                    printf("Item não encontrado ou indisponível.\n");
                }
                break;
            case 8:
                imprimirMapaProvadores();
                break;
            case 9:
                printf("\n-- Fila de Espera --\n");
                imprimirFilaEspera();
                break;
        }

    } while(opcao != 0);

    salvarEstoque();
    return 0;
}

