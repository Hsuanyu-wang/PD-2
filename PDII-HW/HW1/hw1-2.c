#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int func_num=0;
    char ori[99999],chg[99999];
    scanf("%s",ori);
    //printf("%s\n",ori);

    strcpy(chg,ori);

    //printf("chg1 %s\n",chg);
    scanf("%d",&func_num);
    if(func_num==1)//小換大
    {
        for(int i=0; i<strlen(ori); i++)
            if(ori[i]>=65 && ori[i]<=90)
                chg[i]=ori[i]+32;
    }
    else if(func_num==2)//大換小
    {
        for(int i=0; i<strlen(ori); i++)
            if(ori[i]>=97 && ori[i]<=122)
                chg[i]=ori[i]-32;
    }
    else if(func_num==3)//波浪
    {
        for(int i=0; i<strlen(ori); i++)
        {
            if(i%2==0)
            {
                if(ori[i]>=97 && ori[i]<=122)
                {
                    chg[i]=ori[i]-32;
                }
            }
            else if(i%2!=0)
            {

                if(ori[i]>=65 && ori[i]<=90)
                {
                    chg[i]=ori[i]+32;
                }

            }
        }
    }
    else
    {
        printf("error\n");
        exit(0);
    }

    printf("%s\n",chg);
    return 0;
}
