#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int count=0,XG=0,flag;
    char C1[100],C2[100],C3[5],CS[100]={"0"};
    char text[4095],dupl[4095];
    char *chk=NULL, *ptr=NULL, *ptrS=NULL;
    scanf("%s",C1);
    //printf("C1 %s\n",C1);
    scanf("%s",C2);
    //printf("C2 %s\n",C2);
    fgets(C3,5,stdin);
    //printf("C3 %s\n",C3);
    for(int i=0;i<strlen(C1);i++)
        CS[i]=C1[i];
    //printf("CS %s\n",CS);

    while((fgets(text,4095,stdin) != NULL))
    {
        //printf("text %s\n",text);
        strcpy(dupl,text);
        if(C3[2] != 'i' && C3[0] != '\n')
        {
            printf("The input format: string1 string2 [parameter]\n");
            exit(0);
        }
        int k=strlen(text);
        ptr=text;
        //printf("ptr %s\n",ptr);
        if(C3[2]=='i')
        {
            ptrS=dupl;
            //printf("ptrS %s\n",ptrS);
        }
        for(int i=0; i<k; i++)
        {
            if(isalnum(text[i]) != 0 || text[i] == '-')
            {
                count++;
            }
            else
            {
                if(C3[2] == 'i')
                {
                    for(int n=0; n<strlen(ptrS); n++)
                        ptrS[n]=tolower(ptr[n]);
                    //printf("un ptr %s\n",ptr);
                    for(int n=0; n<strlen(CS); n++)
                        CS[n]=tolower(C1[n]);
                    //printf("un C1 %s\n",C1);

                    chk=strstr(ptrS,CS);
                    XG=abs(chk-ptrS);

                    if(chk==NULL || XG>=count)
                    {
                        ;
                    }
                    else
                    {
                        //printf("ptr %s\n",ptr);
                        flag=0;
                        for(int j=0; j<count; j++)
                        {
                            if(j==XG && flag==0)
                            {
                                printf("%s",C2);
                                flag=1;
                                j+=((strlen(CS))-1);
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
                        for(int j=0; j<count; j++)
                        {
                            if(j==XG && flag==0)
                            {
                                printf("%s",C2);
                                flag=1;
                                j+=((strlen(CS))-1);
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
