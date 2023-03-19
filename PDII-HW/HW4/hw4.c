#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short swap_bytes(unsigned short i){
    unsigned short il=0x00, ir=0x00;
    il |= (i << 8);
    ir |= (i >> 8);
    fprintf(stderr,"Number with bytes swapped: ");
    printf("%hx", il+ir);
}

int main(void)
{
    unsigned short hd=0x00;
    fprintf(stderr,"Enter a hexadecimal number (up to four digits): ");
    scanf("%hx", &hd);
    swap_bytes(hd);
    return 0;
}
