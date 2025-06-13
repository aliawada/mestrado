# Estruturas de Dados em C

Este repositório reúne código-fonte e materiais de apoio utilizados em estudos de Estruturas de Dados utilizando a linguagem **C**. O conteúdo é composto por implementações de filas, pilhas, listas, árvores e outros exemplos que servem como base para experimentações e trabalhos acadêmicos.

## Principais diretórios

- **fila encadeada** – implementação de fila com ponteiros.
- **fila estatica** e **fila circular (vetor)** – variações que usam vetores para armazenar os elementos.
- **pilha encadeada** e **pilha estatica** – exemplos de pilhas dinâmica e estática.
- **lista duplamente encadeada**, **lista encadeada simples** e demais variações de listas.
- **árvore AVL** e **árvore binária** – estruturas de árvores balanceadas e básicas.
- **recursividade** – programas com funções recursivas clássicas.
- **trabalho 1** e **trabalho 2** – resoluções de exercícios práticos e projetos maiores.
- **arvores** – exemplos adicionais de manipulação de árvores.

Outras pastas incluem menus de exemplo e soluções de listas de exercícios.

## Compilação

Cada pasta possui um `main.c` que demonstra o uso das estruturas. Para compilar, utilize o `gcc`:

```bash
gcc main.c -o main
```

Em alguns casos é necessário incluir arquivos adicionais na linha de compilação:

```bash
gcc main.c filaEncadeada.c -o main
```

Execute o binário gerado (`./main`) para testar.

## Materiais extras

Alguns diretórios contêm slides e documentos de apoio (`*.pdf`, `*.pptx`) além de exemplos de uso prontos.

## Autor

Código mantido por Ali Awada para fins educacionais.
