/* I_HUFFMAN.C
 *-----------------------------------------------------------------------------
 * 
 * DESCRIÇÃO:
 * 
 *  Coração do programa. Gera, conta e ordena os caracteres. Eles são
 *  armazenados dinâmicamente em um vetor de tamanho 256 dependendo do valor
 *  ASCII do caractere. A letra 'a' por exemplo, é a posição 97 do vetor. E
 *  o valor armazenado na posição 97 é a frequência de letras 'a' no texto.
 * 
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "f_arqs.h"

#include <stdint.h>

// Máximo de caracteres armazenáveis
// (Toda a tabela ASCII estendida)
#define MAX_CHARACTERS 256

typedef struct {
    // Nó da árvore huffman
    char caractere;
    int frequencia;
    uint16_t codigo;
    uint8_t  codigoTam;
} HuffmanNode;

// Conta quantos de cada caractere tem em texto.txt
uint8_t* I_ContaCaracteres() {

    // Abre arquivo lista.txt (contém as letras que queremos contar)
    FILE* lista = F_AbrirArquivo("../runtime/lista.txt", "r");
    if( !lista ) return NULL; // Erro abrindo arquivo, sai da função

    // Abre arquivo texto.txt (contém o texto que queremos contar)
    FILE* arq = F_AbrirArquivo("../runtime/texto.txt", "r");
    if( !arq ){
        fclose(lista);
        return NULL; // Erro abrindo arquivo, sai da função
    }

    // Vetor que armazena a frequência de cada caractere
    static uint8_t char_cont[256] = {0};

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

            //printf("Caractere '%c' encontrado %d vezes\n", c, cont);
        }
    }

    // Fecha arquivos
    fclose(lista);
    fclose(arq);
    return char_cont;
}

// Função de comparação pro qsort (ordem ascendente de frequência)
int I_ComparaNodes( const void *a, const void *b ) {

    HuffmanNode *nodeA = (HuffmanNode *)a;
    HuffmanNode *nodeB = (HuffmanNode *)b;
    return nodeA->frequencia - nodeB->frequencia;  // Ordem ascendente
}

// Função que preenche o vetor de Nodes e ordena por frequência
void I_FSort( uint8_t *char_cont ) {

    HuffmanNode nodes[MAX_CHARACTERS];
    int node_cont = 0;

    // Preenche o vetor HuffmanNode com caracteres e suas frequências
    for ( int i = 0; i < MAX_CHARACTERS; i++ ) {
        if (char_cont[i] > 0) {
            nodes[node_cont].caractere  = (char)i;
            nodes[node_cont].frequencia = char_cont[i];
            node_cont++;
        }
    }

    // Ordena por frequência usando qsort (stdlib.h)
    qsort(nodes, node_cont, sizeof(HuffmanNode), I_ComparaNodes);

    // Imprime para Debug
    printf("Nodes ordenados (por frequência):\n");
    for ( int i = 0; i < node_cont; i++ ) {
        printf("Char: '%c', Frequencia: %d\n", nodes[i].caractere, nodes[i].frequencia);
    }
}