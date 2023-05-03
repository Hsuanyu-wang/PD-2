#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c, m, temp, r;
    scanf("%d %d %d %d", &a, &b, &c, &m);
    if(c<0)
        temp = c-m*((c/m)-1);
    else if(c>=0)
        temp = c%m;
    for(int i=a;i<=b;i++)
    {
        if(i<0)
        {
            r = i-m*((i/m)-1);
            if(r%m == temp)
                printf("%d ", i);
        }
        else if(i%m == temp)
            printf("%d ", i);
    }
    return 0;
}
