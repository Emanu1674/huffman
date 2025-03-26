/* I_MAIN.C
 *-----------------------------------------------------------------------------
 * 
 * DESCRIÇÃO:
 * 
 *  Função main principal, tudo que ela faz é chamar o resto do programa
 * 
 * -----------------------------------------------------------------------------
 */

#include <stdint.h>
#include "i_huffman.h"

int main( [[maybe_unused]]int argc, [[maybe_unused]]char** argv ) {

    uint8_t* char_cont = I_ContaCaracteres();

    I_FSort(char_cont);
    //printf("%d, %d, %d", char_cont['a'], char_cont['b'], char_cont['c']);

    getchar();
    return 0;
}