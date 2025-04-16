#ifndef MENU_H
#define MENU_H

#include <ctype.h>
#include <string.h>

#ifdef _WIN32
    #define LIMPA_TELA "cls"
#else
    #define LIMPA_TELA "clear"
#endif

void menu();
void pausa();
int entrada_e_inteiro(const char* entrada);

#endif
