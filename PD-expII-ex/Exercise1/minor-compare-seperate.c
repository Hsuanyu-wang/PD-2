#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int count=0,i=0,j=0,XG=0,flag;
    char C1[100],C2[100],C3[5],CS[100];
    char text[4095];
    char *chk, *ptr, *ptrS;

    scanf("%s",C1);
    scanf("%s",C2);
    fgets(C3,5,stdin);

    while((fgets(text,4095,stdin) != NULL))
    {
        if(C3[2] != 'i' && C3[0] != '\n')
        {
            printf("The input format: string1 string2 [parameter]\n");
            exit(0);
        }
        ptr=text;
        //ptrS=text;
        strcpy(ptrS,ptr);
        for(i=0; i<strlen(text); i++)
        {
            if(isalnum(text[i]) != 0 || text[i] == '-')
            {
                count++;
            }
            else
            {
                if(C3[2] == 'i')
                {
                    strcpy(ptrS,ptr);
                    //printf("ptrS %s\n",ptrS);
                    for(int k=0; k<strlen(ptrS); k++)
                        ptrS[k]=tolower(ptrS[k]);
                    strcpy(CS,C1);
                    for(int k=0; k<strlen(CS); k++)
                        CS[k]=tolower(CS[k]);
                    chk=strstr(ptrS,CS);
                    XG=abs(chk-ptrS);

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
                                j+=(strlen(CS)-1);
                            }
                            else
                            {
                                printf("%c",ptr[j]);
                            }
                        }
                        printf("\n");
                    }
                    ptrS+=(count+1);
                }

                else
                {
                    chk=strstr(ptr,C1);
                    XG=abs(chk-ptr);
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

                }
                ptr+=(count+1);
                count=0;
            }
        }
    }
    return 0;
}
