#ifndef F_HUFFMAN
#define F_HUFFMAN

#include <stdio.h>

// Conta os Caracteres no arquivo
uint8_t* I_ContaCaracteres();
// Função de Comparação, usada para implementar qsort
int I_ComparaNodes( const void *a, const void *b );
// Preenche e ordena um vetor de tipo "HuffmanNode"
void I_FSort( uint8_t *char_cont );

#endif