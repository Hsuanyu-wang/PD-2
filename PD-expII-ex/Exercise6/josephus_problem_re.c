#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
        char name[100];
        struct node *next;
};
void josephus(int, struct node *);
struct node *head=NULL,*h=NULL;
struct node *tail=NULL,*turn=NULL,*temp=NULL,*cur=NULL;
int main()
{
        char dir[100];
        char *CW="CLOCKWISE",*CCW="COUNTERCLOCKWISE";
        int count=0,n=0,m=0;
        struct node *new_node;
        //fprintf(stderr,"enter the value of n:\n");   //total number of elements in list
        scanf("%d",&n);
        //set circle
        //fprintf(stderr,"enter the name:\n");
        while(count<n)
        {
                new_node=(struct node*)malloc(sizeof(struct node));
                scanf("%s", new_node->name);
                count++;
                //set first node
                if(head==NULL)
                {
                        head=new_node;
                        new_node->next=head;
                }
                //insert in first node left
                else
                {
                        h=head;
                        while(h->next!=head)
                                h=h->next;
                        h->next=new_node;
                        new_node->next=head;
                }
        }
        //
        //fprintf(stderr,"enter the value of m:\n");  //m-th element will be removed every time
        scanf("%d",&m);
        //
        //fprintf(stderr,"enter the direction:\n");
        scanf("%s",dir);
        //fprintf(stderr,"direction : %s\n", dir);

        //printf("%d %d\n", strcmp(dir,CW) , *dir=="COUNTERCLOCKWISE");
        while(strcmp(dir,CW) && strcmp(dir,CCW)){
            //fprintf(stderr,"input direction again\n");
            scanf("%s",dir);
        }
        ////counterclockwise
        if(strcmp(dir,CCW)==0){
            //fprintf(stderr,"ccw\n");
            //find tail
            h=head;
            //fprintf(stderr,"h:%s\n",h->name);
            while(h->next!=head)
                h=h->next;
            tail=h;
            //fprintf(stderr,"tail:%s\n",tail->name);
            //circle -> line
            turn=tail;
            //fprintf(stderr,"turn:%s\n",turn->name);
            tail->next=NULL;
            //fprintf(stderr,"head:%s\n",head->name);
            //reverse
            cur=head;
            //fprintf(stderr,"cur:%s\n",cur->name);
            while(turn!=head){
                if(cur->next==turn){
                    temp=cur;
                    //fprintf(stderr,"if:\n");
                    //fprintf(stderr,"temp:%s\n",temp->name);
                    //fprintf(stderr,"turn:%s\n",turn->name);
                    temp->next=NULL;
                    turn->next=temp;
                    //fprintf(stderr,"turn.next:%s\n",turn->next->name);
                    turn=temp;
                    //fprintf(stderr,"turn2:%s\n",turn->name);
                    cur=head;
                }
                else{
                    //fprintf(stderr,"find pre turn:%s\n",cur->name);
                    cur=cur->next;
                }
            }
            turn->next=tail;
            //fprintf(stderr,"ori-head:%s\n",turn->name);
            //fprintf(stderr,"ori-head.next:%s\n",turn->next->name);
        }
        ////print
        //fprintf(stderr,"circular linklist is:\n");
        h=head;
        while(h->next!=head){
         //fprintf(stderr,"%s->",h->name);
                h=h->next;
        }
        //
        //fprintf(stderr,"%s\n",h->name);
        josephus(m,head);
}
void josephus(int m,struct node *front)
{
        struct node *f=NULL;
        int c=0;
        while(front->next!=front)
        {
                c=0;
                while(c!=m)
                {
                        f=front;
                        front=front->next;
                        c++;
                }
                f->next=front->next;
                printf("%s KILLED\n",front->name); //sequence in which nodes getting deleted
                front=f->next;
        }
        printf("%s SURVIVE\n",front->name);
        return;
}
