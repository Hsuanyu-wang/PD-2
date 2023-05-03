#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    unsigned short int a,temp=0,L,R;
    int p;
    scanf("%hu", &a);
    scanf("%d", &p);
    L=a;
    R=a;

    L = L>>p;
    R = R<<(16-p);

    temp = L+R;
    printf("%hu", temp);

    return 0;
}
