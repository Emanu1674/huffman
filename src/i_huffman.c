#include <stdio.h>
#include <stdlib.h>
#include "f_arqs.h"

typedef struct {
    // Nó da árvore huffman
    char caractere;
    int frequencia;
    int codigo[8];
} HuffmanNode;

// Conta quantos de cada caractere tem em texto.txt
FILE* I_ContaCaracteres() {

    FILE* lista = F_AbrirArquivo("../runtime/lista.txt", "r");
    FILE* arq = F_AbrirArquivo("../runtime/texto.txt", "r");

    printf("Hello World!");
    fclose(arq);
    return 0;
}