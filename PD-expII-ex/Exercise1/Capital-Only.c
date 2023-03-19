#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int count=0,i=0,j=0,XG=0,XG1=0,flag;
    char C1[100],C2[100],C3[5];
    char text[4095];
    char *chk, *chk1, *ptr;

    scanf("%s",C1);
    scanf("%s",C2);
    fgets(C3,5,stdin);

    char CB[strlen(C1)+1];
    for(int k=0; k<=strlen(C1); k++)
    {
        CB[k]=C1[k];
    }
    CB[0]=toupper(C1[0]);


    while((fgets(text,4095,stdin) != NULL))
    {
        if(C3[2] != 'i' && C3[0] != '\n')
        {
            printf("The input format: string1 string2 [parameter]\n");
            exit(0);
        }
        ptr=text;
        for(i=0; i<strlen(text); i++)
        {
            if(isalnum(text[i]) != 0 || text[i] == '-')
            {
                count++;
            }
            else
            {
                chk=strstr(ptr,C1);
                chk1=strstr(ptr,CB);
                XG1=abs(chk1-ptr);
                XG=abs(chk-ptr);

                if(C3[2] == 'i')
                {
                    if(chk==NULL)
                    {
                        chk=chk1;
                        XG=XG1;
                    }
                    else if(chk1!=NULL && chk1<chk)
                    {
                        chk=chk1;
                        XG=XG1;
                    }
                }

                if(chk==NULL || XG>=count)
                {
                    ;
                }
                else
                {
                    flag=0;
                    for(j=0; j<count; j++)
                    {
                        if(j==XG && flag==0)
                        {
                            printf("%s",C2);
                            flag=1;
                            j+=(strlen(C1)-1);
                        }
                        else
                        {
                            printf("%c",ptr[j]);
                        }
                    }
                    printf("\n");
                }
                ptr+=(count+1);
                count=0;
            }
        }
    }
    return 0;
}
