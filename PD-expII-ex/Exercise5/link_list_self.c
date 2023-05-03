#include "myDS.h"
#include "basic.h"
// HEAD is point to FOODPAPA (id: 0)
void my_insert(struct node* HEAD, int ID, char *Name, int node_id){
	// Please insert a new node(store Name & node_id)
	// after the node which id is ID
	// If it doesn't exit such ID, print "INVALID OPERATION"
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	for(int i=0;i<strlen(Name);i++){
		new_node->name[i] = *(Name+i);
	}
	new_node->id = node_id;

        while(1){
            if(HEAD == NULL){
			printf("INVALID OPERATION\n");
			break;
            }
		if(HEAD->id == ID){
        		struct node *store;
			store = malloc(sizeof(struct node));
			store = HEAD->next;
			HEAD->next = new_node;
			new_node->next = store;
			store = NULL;
			break;
		}
		else{
			HEAD = HEAD->next;
		}

	}
}
void my_delete(struct node* HEAD, char *Name){
	// Delete the node which store the Name.
	// If it doesn’t exit such Name, print “INVALID OPERATION”.
	int flag=0;
	while(1){
		for(int i=0;i<strlen(Name);i++){
			if(HEAD->next->name[i] == *(Name+i));
				flag++;
		}
		if(flag == strlen(Name)){
			flag=0;
			free(HEAD->next);
			HEAD->next = NULL;
			break;
		}
		else{
			HEAD = HEAD->next;
		}
		if(HEAD == NULL){
			printf("INVALID OPERATION\n");
			break;
		}
	}

}
void my_swap(struct node *HEAD, char *Name1, char *Name2){
	// Swap the node which store Name1 and Name2
	// If either of the node doesn’t exit, print “INVALID OPERATION”
	// NOTICE: don't just swap the node's value
	// You need to break the link and recombine it
/*	int flag1=0,flag2=0;
	struct node *dum,*cur,*pre,*p1,*p2;
	dum = malloc(sizeof(struct node));
	dum->next = HEAD;
	cur=dum; pre=dum; p1=NULL; p2=NULL;
	while(1){
		//printf("in1\n");
		for(int i=0; i<strlen(Name1); i++){
			if(cur->next->name[i] == *(Name1+i));
				flag1++;
		}
		//printf("in2\n");
		for(int i=0; i<strlen(Name2); i++){
			if(cur->next->name[i] == *(Name2+i));
				flag2++;
		}
		//printf("in3\n");
		if(flag1==strlen(Name1) || flag2==strlen(Name2)){
			//printf("in4\n");
			if(!p1){
				//printf("in5\n");
				p1=cur->next;
				pre=cur;
				flag1=0;flag2=0;
			}
			else{
				printf("in6\n");
				struct node *temp;
				temp=cur->next->next;
				p2=cur->next;
				pre->next=p2;
				if(p1==cur){
					printf("in7\n");
					p2->next=p1;
					p1->next=temp;
				}
				else{
					printf("in8\n");
					p2->next=p1->next;
					cur->next=p1;
					p1->next=temp;
				}
				printf("in9\n");
				//pre->next=p2;
				flag1=0;flag2=0;
				break;
			}
		}
		else{
			cur=cur->next;
			if(cur==NULL){
				printf("INVALID OPERATION\n");
				break;
			}
		}
	}*/
}
//
void my_print_id(struct node *HEAD, char *Name){
	// Print the id of the corresponding Name.
	// If Name doesn’t exit, print “INVALID OPERATION”
	int flag=0;
	while(1){
        if(HEAD == NULL){
			printf("INVALID OPERATION\n");
			break;
		}
        if(strcmp(HEAD->name, Name) != 0)
        {
            printf("%d\n", HEAD->id);
			break;
        }
		else
			HEAD = HEAD->next;
	}
}
void my_print_name(struct node *HEAD, int ID){
	// Print the name of the corresponding ID
	// If ID doesn’t exit, print “INVALID OPERATION”
	while(1){
		if(HEAD->id == ID){
			printf("%s\n", HEAD->name);
			break;
		}
		else
			HEAD = HEAD->next;
		if(HEAD == NULL){
			printf("INVALID OPERATION\n");
			break;
		}
	}
}
void my_result(struct node* HEAD){
	// Print out all the information in the linked list orderly
	// in the format “ID NAME”. (start from HEAD)
	while(1){
		printf("%d %s\n", HEAD->id, HEAD->name);
		HEAD=HEAD->next;
		if(HEAD == NULL)
			break;
	}
}
