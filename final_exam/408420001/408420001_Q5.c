#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define DEBUG_input_string 0
#define case0 strlen(cin[2])==0
#define case1 cin[2][0]=='-' && cin[2][1]=='i'
#define while_condition (ch=getchar())!='\n' && ch!='\r' && num<3 && ori<100 && tlim<=200
#define DEBUG 0
int main()
{
    int count=0,XG=0,flag=0,ori=0,num=0,blank=0,tlim=0;
    char cin[3][100]={""},CS[100]= {""},ch=0;
    char text[4095],dupl[4095];
    char *chk=NULL, *ptr=NULL, *ptrS=NULL;
    //fprintf(stderr,"Enter pattern, replacement, and at most one parameter:\n");

    while(while_condition)
    {

        //printf("ch %c\n",ch);
        if(isalnum(ch) || ch=='-')
        {
            cin[num][ori]=ch;
            ori++;
            blank=0;
        }
        else if(isalnum(ch)==0 && ch!='-')
        {
            cin[num][ori]='\0';
            if(blank==0)
            {
                blank=1;
                ori=0;
                num++;
            }
        }
        tlim++;
    }
    #if DEBUG_input_string
    printf("cin[0] #%s#",cin[0]);
    printf("cin[1] #%s#",cin[1]);
    printf("cin[2] #%s#",cin[2]);
    #endif // DEBUG
    #if DEBUG
    if(!(case1 || case0) || strlen(cin[1])==0 || strlen(cin[0])==0)
        {
            printf("The input format: string1 string2 [parameter]\n");
            exit(0);
        }
    else if(case0)
            printf("this is case 0\n");
    else if(case1)
            printf("this is case 1\n");
    #endif
    //fprintf(stderr,"Enter the article:\n");

    while((fgets(text,4095,stdin) != NULL))
    {
        strcpy(dupl,text);
        ptr=text;
        ptrS=dupl;
        for(int i=0; i<strlen(cin[0]); i++)
            CS[i]=cin[0][i];
        for(int i=0; i<strlen(text); i++)
        {
            if(isalnum(text[i]) != 0 || text[i] == '-')
            {
                count++;
            }
            else
            {
                #if DEBUG
                if(isalnum(ptr[0]) || ptr[0]=='-')
                {
                    printf("the word is: ");
                    for(int j=0; j<count; j++)
                    {
                        printf("%c",ptr[j]);
                    }
                    printf("\n");
                }
                #endif
                if(cin[2][0]=='-' && cin[2][1]=='i')
                {
                    for(int n=0; n<strlen(ptr); n++)
                        ptrS[n]=tolower(ptrS[n]);
                    for(int n=0; n<strlen(cin[0]); n++)
                        CS[n]=tolower(CS[n]);
                    chk=strstr(ptrS,CS);
                    XG=abs(chk-ptrS);
                }
                else if(strlen(cin[2])==0)
                {
                    chk=strstr(ptr,cin[0]);
                    XG=abs(chk-ptr);
                }
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
                            printf("%s",cin[1]);
                            flag=1;
                            j+=((strlen(cin[1]))-1);
                        }
                        else
                        {
                                printf("%c",ptr[j]);
                        }
                    }
                    printf("\n");
                }
                ptrS+=(count+1);
                ptr+=(count+1);
                count=0;
            }
        }
    }
    return 0;
}
