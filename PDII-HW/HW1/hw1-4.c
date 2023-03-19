#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int same_alph=0,word_length=0,count=0,loop=0,c=0;
    char sent[99999]= {""},word[99999]= {""};
    char *ptrs=NULL,*ptrw=NULL;
    //input sentence
    fgets(sent,99999,stdin);

    //input word
    scanf("%s",word);
    word[strlen(word)]='\0';

    //set ptr position
    for(int i=0;i<strlen(sent);i++)
    {
        if(isalnum(sent[i]) != 0)
        {
            ptrs=sent+i;
            break;
        }
    }
    ptrw=word;
    //
    while(strlen(ptrs)!=0)
    {
        //printf("ptrs : %s\n",ptrs);
        if(isalnum(ptrs[loop]) != 0)
        {
            word_length++;
        }
        else
        {
            //printf("w_l : %d\n",word_length);

            for(int j=0; j<word_length; j++)
            {
                if(ptrs[j]==ptrw[j])
                    same_alph++;
            }
            //printf("s_a : %d\n",same_alph);
            if(same_alph==word_length && word_length!=0 && !isalnum(ptrs[word_length]))
            {
                //printf("same_alph %d, word_length %d\n",same_alph,word_length);
                count++;
            }
            //printf("count : %d\n",count);
            ptrs+=(word_length+1);
            printf("ptrs : %c\n",ptrs[0]);
            loop=-1;
            same_alph=0;
            word_length=0;
        }
        loop++;
    }
    printf("%d\n",count);
    return 0;
}
