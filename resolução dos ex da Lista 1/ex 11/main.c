#include "pilhaEncadeada.c"
#include <string.h>
#include <ctype.h>

// Funcoes auxiliares para pilha de char

void push_char(Pilha* p, char c) {
    push(p, (int)c);
}

char pop_char(Pilha* p) {
    TipoItem* x = pop(p);
    char c = (x) ? (char)(*x) : '\0';
    if (x) free(x);
    return c;
}

char topo_char(Pilha* p) {
    TipoItem* x = topo(p);
    char c = (x) ? (char)(*x) : '\0';
    if (x) free(x);
    return c;
}

int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// b) Converter infix para posfix
void converter_infix_para_posfix(char* infix, char* posfix_saida) {
    Pilha* p = criar_pilha_vazia();
    int k = 0;
    int i;
    for (i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if (isdigit(c)) {
            posfix_saida[k++] = c;
        } else if (c == '(') {
            push_char(p, c);
        } else if (c == ')') {
            while (!vazia(p) && topo_char(p) != '(')
                posfix_saida[k++] = pop_char(p);
            pop_char(p);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!vazia(p) && precedencia(topo_char(p)) >= precedencia(c))
                posfix_saida[k++] = pop_char(p);
            push_char(p, c);
        }
    }
    while (!vazia(p))
        posfix_saida[k++] = pop_char(p);
    posfix_saida[k] = '\0';
    free(p);
}


// a) Avaliar se posfixa esta correta comparando com conversao
void avaliar_posfix_corretamente(char* infix, char* posfix) {
    char gerado[100];
    converter_infix_para_posfix(infix, gerado);
    if (strcmp(gerado, posfix) == 0)
        printf("Posfixa esta correta em relacao a infixa!\n");
    else {
        printf("Posfixa NAO esta correta!\n");
        printf("Esperado: %s\n", gerado);
    }
}


// c) Avaliar expressao posfix
int avaliar_posfix(char* posfix) {
    Pilha* p = criar_pilha_vazia();
    int i;
    for (i = 0; i < strlen(posfix); i++) {
        char c = posfix[i];
        if (isdigit(c)) {
            push(p, c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (vazia(p)) { free(p); return 0; }
            int b = *(pop(p));
            if (vazia(p)) { free(p); return 0; }
            int a = *(pop(p));
            int r;
            switch(c) {
                case '+': r = a + b; break;
                case '-': r = a - b; break;
                case '*': r = a * b; break;
                case '/': r = a / b; break;
            }
            push(p, r);
        }
    }
    int resultado = *(pop(p));
    free(p);
    return resultado;
}

// d) Validar expressao (parenteses)
int validar_expressao(char* expr) {
    Pilha* p = criar_pilha_vazia();
    int i;
    for (i = 0; i < strlen(expr); i++) {
        char c = expr[i];
        if (c == '(') push_char(p, c);
        else if (c == ')') {
            if (vazia(p)) { free(p); return 0; }
            pop_char(p);
        }
    }
    int ok = vazia(p);
    free(p);
    return ok;
}

void testar_expressao(char* infix) {
    char posfix[100];
    printf("\nTestando expressao: %s\n", infix);
    if (!validar_expressao(infix)) {
        printf("Expressao invalida!\n");
        return;
    }
    converter_infix_para_posfix(infix, posfix);
    printf("Posfix: %s\n", posfix);
    printf("Resultado: %d\n", avaliar_posfix(posfix));
    avaliar_posfix_corretamente(infix, posfix);
}

int main() {
    printf("\n--- Exercicio Pilhas ---\n");

    testar_expressao("2+(3*4)");
    testar_expressao("(2+3)*5");
    testar_expressao("((1+2)*(3-4))/5");
    testar_expressao("((7+(3*5))/(2+1))");

    return 0;
}

