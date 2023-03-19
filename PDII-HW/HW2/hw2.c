#include<stdio.h>
#include<stdlib.h>
#define NAME_LENGTH 50
//structure
struct course
{
    char name[NAME_LENGTH];
    struct course *next;
    struct course *prior;
};
struct ID_list
{
    int cID,nID,pID;
};
//function
void sort(struct course *node,struct ID_list *list,int max)
{
    int i,j;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            if(list[i].cID == list[j].nID)
            {
                node[j].next=&node[i];
            }
            if(list[i].cID == list[j].pID)
            {
                node[j].prior=&node[i];
            }
        }
    }
}
int main()
{
    //input course number
    int course_num;
    char option='0';
    scanf("%d",&course_num);
    //head
    struct course *node,*current;
    struct ID_list *list;
    node=malloc(course_num * sizeof(struct course));
    list=malloc(course_num * sizeof(struct ID_list));
    for(int i=0; i<course_num; i++)
    {
        scanf("%d %d %d %s", &list[i].cID, &list[i].nID, &list[i].pID, node[i].name);
    }
    for (int i = 0;i<course_num;i++)
    {
        node[i].next = NULL;
        node[i].prior = NULL;
    }
    sort(node,list,course_num);
    current = &node[0];
    while (1)
    {
        getchar();
        printf("Current Course: %s\n[n] Next course. [p] Prior course [q] Quit:", current->name);
        option=getchar();
        if(option == 'q')
                break;
        else if (option == 'n')
        {
            if (current->next == NULL)
                printf("There is no next course.\n");
            else
                current=current->next;
        }
        else if (option == 'p')
        {
            if (current->prior == NULL)
                printf("There is no previous course.\n");
            else
                current=current->prior;
        }
        else
            continue;
    }
    return 0;
}
