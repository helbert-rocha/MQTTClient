#include <stdio.h>
#include <string.h>

/*Converte os elementos vindos do payload que contem a mensagem
 * para char
*/
static char *ConvertToChar(const void *payload){
    char buf[256];
    memset(buf, 0, 51*sizeof(char));
    memcpy(buf, payload, 255*sizeof(char));
    return buf;
}

