#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#define MAX_LINE_LEN 60
//§ï¦¨°}¦CÅª¨ú¦r¦ê
struct node{
    char name[22];
    struct node *next;
};

struct node *head;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    struct node *first;
    first = malloc(sizeof(struct node));
    first->next=NULL;
    first->name[0] = '\0';
    head=first;
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    //printf("10\n");
    if (num_words > 0)
        line_len++;
    struct node *new_node;
    new_node=NULL;
    new_node=malloc(sizeof(struct node));
    strcpy(new_node->name,word);
    new_node->next = NULL;
    struct node *cur;
    cur=head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next = new_node;
    //printf("%s\n",new_node->name);

    line_len += strlen(cur->name);
    num_words++;
    //printf("10'\n");
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    struct node *temp;
    temp=head->next;
//  int extra_spaces, spaces_to_insert, i, j;
//  extra_spaces = MAX_LINE_LEN - line_len;
//  for (i = 0; i < line_len; i++) {
//    if (*(temp->name+i) != ' ')
//      putchar(*(temp->name+i));
//    else {
//      spaces_to_insert = extra_spaces / (num_words - 1);
//      for (j = 1; j <= spaces_to_insert + 1; j++)
//        putchar(' ');
//      extra_spaces -= spaces_to_insert;
//      num_words--;
//    }
//  }
    while(temp->next!=NULL){
        printf("%s ",temp->name);
        temp=temp->next;
    }
    printf("%s",temp->name);
  putchar('\n');
}

void flush_line(void)
{
    struct node *cur;
    cur = head->next;
    //if(line_len > 0){
        while(cur != NULL){
//            for(int i=0;i<strlen(cur->name);i++)
//                printf("%c", cur->name[i]);
            printf("%s",cur->name);
            cur=cur->next;
            if(cur != NULL)
                printf(" ");
        }
    //}
}
