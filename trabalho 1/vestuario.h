#ifndef VESTUARIO_H
#define VESTUARIO_H

typedef struct {
    int codigo;
    char tipo[50];
    char marca[50];
    char cor[30];
    int tamanho;
    int setor;
    int arara;
    int disponivel;
} Item;

void inicializarEstoque();
void carregarArquivoTexto(const char* nomeArquivo);
void inserirItem(Item novo);
int removerItem(int codigo);
Item* buscarItem(int codigo);
void salvarEstoque();
void imprimirEstoque();

#endif
