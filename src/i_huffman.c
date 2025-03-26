#include <stdio.h>
#include <stdlib.h>
#include "f_arqs.h"

#include <stdint.h>

typedef struct {
    // Nó da árvore huffman
    char caractere;
    int frequencia;
    int codigo[8];
} HuffmanNode;

// Conta quantos de cada caractere tem em texto.txt
void I_ContaCaracteres() {

    // Abre arquivo lista.txt (contém as letras que queremos contar)
    FILE* lista = F_AbrirArquivo("../runtime/lista.txt", "r");
    if( !lista ) return; // Erro abrindo arquivo, sai da função

    // Abre arquivo texto.txt (contém o texto que queremos contar)
    FILE* arq = F_AbrirArquivo("../runtime/texto.txt", "r");
    if( !arq ){
        fclose(lista);
        return; // Erro abrindo arquivo, sai da função
    }

    // Vetor que armazena a frequência de cada caractere
    uint8_t char_cont[256] = {0};

    // Lê cada caractere de lista.txt e conta as ocorrências em texto.txt
    char c;
    while( (c = fgetc(lista)) != EOF ) {
        // Verifica se o caractere é válido (é imprimível)
        // Alcance pode ser alterado dependendo da necessidade
        if( c >= 32 && c <= 126 ) {
            // Pra cada caractere na lista.txt, conta as ocorrência em texto.txt
            fseek(arq, 0, SEEK_SET); // Reseta o ponteiro pro começo de texto.txt
            uint32_t  cont = 0;
            char      t;

            while( (t = fgetc(arq)) != EOF) {
                if( t == c )
                cont++;
            }
            // Armazena o cont do caractere no vetor
            char_cont[(unsigned char)c] = cont;

            printf("Caractere '%c' encontrado %d vezes\n", c, cont);
        }
    }

    // Fecha arquivos
    fclose(lista);
    fclose(arq);
}