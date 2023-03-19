#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define print_err printf("The number must be greater than zero!\n");
//定義結構
struct item
{
    int cof;
    int ept;
};
int main()
{
    long int ans=0;
    int num=0,cal=0,x=0;
    //輸入要幾項
    while(1)
    {
        fprintf(stderr,"Enter the number of terms:");
        scanf("%d",&num);
        if(num==0)
            print_err
        else
            break;
    }
    //宣告結構
    struct item func[num];
    //輸入各項係數
    fprintf(stderr,"Enter each term with cof and exp:\n");
    for(int i=0;i<num;i++)
    {
        scanf("%d %d",&func[i].cof,&func[i].ept);
    }
    //輸出方程式
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
    //輸入要帶入x的次數
    while(1)
    {
        fprintf(stderr,"How many times to calculate:");
        scanf("%d",&cal);
        if(cal==0)
            print_err
        else
            break;
    }
    //輸入x值
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
