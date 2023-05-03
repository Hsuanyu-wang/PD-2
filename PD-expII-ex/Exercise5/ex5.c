#include "myDS.h"
#include "basic.h"
// HEAD is point to FOODPAPA (id: 0)
void my_insert(struct node* HEAD, int ID, char *Name, int node_id){
	// Please insert a new node(store Name & node_id)
	// after the node which id is ID
	// If it doesn't exit such ID, print "INVALID OPERATION"
	struct node *new_node, *temp;
	//initialize
	new_node = NULL;
	new_node = malloc(sizeof(struct node));
	for(int i=0;i<strlen(Name);i++){
		new_node->name[i] = *(Name+i);
	}
	new_node->id = node_id;
	new_node->next=NULL;
	temp=HEAD;
	//find and insert
    while (temp != NULL) {
        //find if id = ID
		if (temp->id == ID) {
		    //at tail(last one)
			if (temp->next == NULL) {
				temp->next = new_node;
				break;
			}
            //at body or head
			else {
				new_node->next = temp->next;
				temp->next = new_node;
				break;
			}
		}
		temp = temp->next;
	}
	//didn't find
	if (temp == NULL) {
		printf("INVALID OPERATION\n");
	}
}
void my_delete(struct node* HEAD, char *Name){
	// Delete the node which store the Name.
	// If it doesn’t exit such Name, print “INVALID OPERATION”.
	struct node *cur, *prev;
    //stop when meet terminal or name found
	for (cur = HEAD, prev = NULL;
		 cur != NULL && strcmp(cur->name, Name);
		 prev = cur, cur = cur->next);
    //current at terminal
	if (cur == NULL) {
		printf("INVALID OPERATION\n");
		free(cur);
		return;
	}
	//name found
	//head is the target name
	if (prev == NULL){
		HEAD = HEAD->next;
	}
	//avoid target name
	else{
		prev->next = cur->next;
	}
	free(cur);
}
void my_swap(struct node *HEAD, char *Name1, char *Name2){
	// Swap the node which store Name1 and Name2
	// If either of the node doesn’t exit, print “INVALID OPERATION”
	// NOTICE: don't just swap the node's value
	// You need to break the link and recombine it
    //x=Name1,y=Name2
    // Nothing to do if x and y are same
    if (strcmp(Name1, Name2) == 0){
	        return;
	}
    // Search for x (keep track of prevX and CurrX
    struct node *prevX = NULL, *currX = HEAD;
    while (currX && strcmp(currX->name, Name1)) {
        prevX = currX;
        currX = currX->next;
    }
 	if(currX==NULL){
		printf("INVALID OPERATION\n");
			return;
	}
    // Search for y (keep track of prevY and CurrY
    struct node *prevY = NULL, *currY = HEAD;
    while (currY && strcmp(currY->name, Name2)) {
        prevY = currY;
        currY = currY->next;
    }
	if(currY==NULL){
		printf("INVALID OPERATION\n");
			return;
	}
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        HEAD = currY;
    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        HEAD = currX;
    // Swap next pointers
    struct node* temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
}
void my_print_id(struct node *HEAD, char *Name){
	// Print the id of the corresponding Name.
	// If Name doesn’t exit, print “INVALID OPERATION”
	while(1){
        if(strcmp(HEAD->name, Name) == 0){
            printf("%d\n", HEAD->id);
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

