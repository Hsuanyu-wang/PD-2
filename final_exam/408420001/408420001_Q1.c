//Prime Factorization
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int num=0,i=2,count=0;
    scanf("%d",&num);
    while(num!=1 && i<100000)
    {
        if(num%i==0 && num/i>0)
        {
            count++;
            if(num==i && count==1)
            {
                num/=i;
                printf("%d ",i);
            }
            else
            {
                num/=i;
                printf("%d ",i);
            }

        }
        else
            i++;
    }
    return 0;
}
