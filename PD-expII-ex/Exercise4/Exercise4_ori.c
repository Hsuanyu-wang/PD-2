#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define print_err printf("The number must be greater than zero!\n");
//�w�q���c
struct item
{
    int cof;
    int ept;
};
int main()
{
    long int ans=0;
    int num=0,cal=0,x=0;
    //��J�n�X��
    while(1)
    {
        fprintf(stderr,"Enter the number of terms:");
        scanf("%d",&num);
        if(num==0)
            print_err
        else
            break;
    }
    //�ŧi���c
    struct item func[num];
    //��J�U���Y��
    fprintf(stderr,"Enter each term with cof and exp:\n");
    for(int i=0;i<num;i++)
    {
        scanf("%d %d",&func[i].cof,&func[i].ept);
    }
    //��X��{��
    for(int i=0;i<num;i++)
    {
        printf("%dx^%d",func[i].cof,func[i].ept);
        if(i==(num-1))
        {
            printf(" =\n");
        }
        else
        {
            printf(" + ");
        }
    }
    //��J�n�a�Jx������
    while(1)
    {
        fprintf(stderr,"How many times to calculate:");
        scanf("%d",&cal);
        if(cal==0)
            print_err
        else
            break;
    }
    //��Jx��
    for(int i=0;i<cal;i++)
    {
        fprintf(stderr,"The unknown number x is:");
        scanf("%d",&x);
        if(x==0)
        {
            print_err
            i--;
        }
        else
        {
           for(int j=0;j<num;j++)
            {
                ans+=((long int)pow(x,func[j].ept) * (long int)func[j].cof);
            }
            printf("%ld\n",ans);
            ans=0;
        }
    }
    return 0;
}
