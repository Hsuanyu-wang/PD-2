#include "myDS.h"
#include "basic.h"

// HEAD is point to FOODPAPA (id: 0)
void my_insert(struct node* HEAD, int ID, char *Name, int node_id){
	// Please insert a new node(store Name & node_id)
	// after the node which id is ID
	// If it doesn't exit such ID, print "INVALID OPERATION"
	struct node *new_node = NULL, *temp = HEAD;

	new_node = malloc(sizeof(struct node));
	strcpy(new_node->name, Name);
	new_node->id = node_id;
	new_node->next = NULL;

	while (temp != NULL) {

		if (temp->id == ID) {

			if (temp->next == NULL) {

				temp->next = new_node;
				break;

			} else {

				new_node->next = temp->next;
				temp->next = new_node;
				break;

			}
		}
		temp = temp->next;
	}

	if (temp == NULL) {
		printf("INVALID OPERATION\n");
	}
}
void my_delete(struct node* HEAD, char *Name){
	// Delete the node which store the Name.
	// If it doesn’t exit such Name, print “INVALID OPERATION”.

	struct node *cur, *prev;

	for (cur = HEAD, prev = NULL;
		 cur != NULL && strcmp(cur->name, Name);
		 prev = cur, cur = cur->next);

	if (cur == NULL) {
		printf("INVALID OPERATION\n");
		free(cur);
		return;
	}

	if (prev == NULL) {
		HEAD = HEAD->next;
	} else {
		prev->next = cur->next;
	}

	free(cur);
}
void my_swap(struct node *HEAD, char *Name1, char *Name2){
	// Swap the node which store Name1 and Name2
	// If either of the node doesn’t exit, print “INVALID OPERATION”
	// NOTICE: don't just swap the node's value
	// You need to break the link and recombine it

	struct node *temp, *head_1, *head_2, *pre_1, *pre_2;

	temp = NULL, pre_1 = NULL, pre_2 = NULL;
	head_1 = HEAD, head_2 = HEAD;

	while (head_1 != NULL && strcmp(head_1->name, Name1)) {
		pre_1 = head_1;
		head_1 = head_1->next;
	}
	while (head_2 != NULL && strcmp(head_2->name, Name2)) {
		pre_2 = head_2;
		head_2 = head_2->next;
	}

	if (head_1 == NULL || head_2 == NULL) {

		printf("INVALID OPERATION\n");
		return;

	} else {

		if (pre_1 != NULL) {
			pre_1->next = head_2;
		} else {
			HEAD = head_2;
		}

		if (pre_2 != NULL) {
			pre_2->next = head_1;
		} else {
			HEAD = head_1;
		}

		temp = head_1->next;
		head_1->next = head_2->next;
		head_2->next = temp;
	}
}
void my_print_id(struct node *HEAD, char *Name){
	// Print the id of the corresponding Name.
	// If Name doesn’t exit, print “INVALID OPERATION”

	while (HEAD != NULL && strcmp(HEAD->name, Name)) {
		HEAD = HEAD->next;
	}

	if (HEAD == NULL) {
		printf("INVALID OPERATION\n");
	} else {
		printf("%d\n", HEAD->id);
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

