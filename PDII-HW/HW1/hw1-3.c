#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int sen=0,word=0,count=0,flag=0;
    scanf("%d",&sen);
    scanf("%d",&word);
    char array[word][99],common[99]={"0"};

    for(int j=0;j<word;j++)
            scanf("%s",array[j]);

    for(int i=0;i<99;i++)
    {
        char c=array[0][i];
        for(int j=0;j<word;j++)
        {
            if(sen==1)
            {
                if(array[j][i]==c)
                {
                    count++;
                    flag=1;
                }
            }
            else if(sen==2)
            {
                if(array[j][i]==toupper(c) || array[j][i]==tolower(c))
                {
                    count++;
                    flag=1;
                }
            }
        }
        if(count==word && flag==1)
        {
            if(sen==1)
                common[i]=c;
            else if(sen==2)
                common[i]=tolower(c);
        }
        count=0;
        flag=0;
    }
    if(common[0]!='0')
        printf("%s\n",common);
    else
        printf("No longest common prefix\n");
    return 0;
}
