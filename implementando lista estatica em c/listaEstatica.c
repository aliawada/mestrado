#include "listaEstatica.h"

//Cria uma lista vazia
//Pr�-condi��o: nenhuma
//P�s-condi��o: lista criada
Lista *cria_lista_vazia()
{
    Lista *nova_lista = (Lista*) malloc(sizeof(Lista));
    if(nova_lista == NULL) {
    	printf("Erro: falha ao alocar mem�ria para a lista.\n");
        return NULL;
	}
    nova_lista->pos_livre = 0;
    return nova_lista;
}
// Testa se uma lista vazia
//Pr�-condi��o: ponteiro n�o nulo para estrutura lista
//P�s-condi��o: retorna 1 se a lista � vazia ou 0 caso contr�rio
int vazia(Lista *l)
{
    return (l->pos_livre == 0);
}

//Insere um item na lista
//Pr�-condi��o: ponteiro n�o nulo para estrutura lista
//P�s-condi��o: item � inserido na lista
void insere(Lista *l, TipoItem x)
{
    if(l->pos_livre >= TAM_MAX) {
        printf("Lista cheia");
    } else {
        l->item[l->pos_livre++] = x;
    }
}

//Retira o item da lista
//Pr�-condi��o: ponteiro n�o nulo para estrutura lista
//P�s-condi��o: item � removido da lista
void retira(Lista *l, TipoItem x)
{
    if(vazia(l)) {
        printf("Lista vazia: sem os elementos para retirar");
    } else {
        int pos = 0;
        while(pos < l->pos_livre && x != l->item[pos]) {
            pos++;
        }
        if(pos == l->pos_livre) {
            printf("Elemento n�o encontrado");
        } else {
            int i;
            for(i = pos; i < l->pos_livre; i++) {
                l->item[i] = l->item[i+1];
            }
        }
        l->pos_livre--;
    }
}

void imprime(Lista *l)
{
    if(vazia(l)) {
        printf("Lista vazia");
    } else { 
        int i;
        printf("[");
        for(i = 0; i < l->pos_livre; i++ ) {
            printf("%d ", l->item[i]);
        }
        printf("]\n");
    }
}

