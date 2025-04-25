#ifndef LISTA_ENCADEADA_EM_ARQUIVO_H
#define LISTA_ENCADEADA_EM_ARQUIVO_H

#include <stdlib.h> // malloc, free
#include <stdio.h> // printf

 typedef int TipoItem;
 
 // cabecalho do arquivo
 typedef struct {
 	int pos_cabeca; //posic~ao do incio da lista
 	int pos_topo; // 1a posic~ao n~ao usada no fim do arquivo
 	int pos_livre; // posic~ao do incio da lista de nos livres
 } cabecalho;
 
 // estrutura de no para lista encadeada
 typedef struct {
 	TipoItem info;
 	int prox;
 } no;
 
void cria_lista_vazia(FILE* arq);
cabecalho* le_cabecalho(FILE * arq);
void escreve_cabecalho(FILE* arq, cabecalho* cab);
no* le_no(FILE* arq, int pos);
void escreve_no(FILE* arq, no* x, int pos);
void escreve_no(FILE* arq, no* x, int pos);
void retira(FILE* arq, TipoItem x);

#endif
