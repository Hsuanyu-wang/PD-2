//Remainder
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long int m,a,b;
    scanf("%ld", &m);
    scanf("%ld", &a);
    scanf("%ld", &b);
    if(1 <= m && m <= 100 && 1 <= a && a <= pow(10,100) && 1 <= b && b <= (pow(2,31)-1))
        printf("%ld", a%b);
    return 0;
}
