/* F_ARQS.C
 *-----------------------------------------------------------------------------
 * 
 * DESCRIÇÃO:
 * 
 *  Módulo principal para lidar com arquivos
 * 
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

FILE* F_AbrirArquivo( const char* filename, const char* modo ) {
    FILE* file = fopen(filename, modo);
    if( file == NULL ) {
        perror("ERRO: Arquivo não existe ou está corrompido!");
        exit(EXIT_FAILURE);
    }
    return file;
}