#include "myDS.h"
#include "basic.h"

// HEAD is point to FOODPAPA (id: 0)
void my_insert(struct node* HEAD, int ID, char *Name, int node_id){
	// Please insert a new node(store Name & node_id)
	char *store;
	store = ;

	// after the node which id is ID

	// If it doesn't exit such ID, print "INVALID OPERATION"
        printf("INVALID OPERATION\n");
}
void my_delete(struct node* HEAD, char *Name){
	// Delete the node which store the Name.
	HEAD = Head->next;
	// If it doesn’t exit such Name, print “INVALID OPERATION”.
        printf("INVALID OPERATION\n");
}
void my_swap(struct node *HEAD, char *Name1, char *Name2){
	// Swap the node which store Name1 and Name2

	// If either of the node doesn’t exit, print “INVALID OPERATION”
        printf("INVALID OPERATION\n");
	// NOTICE: don't just swap the node's value

	// You need to break the link and recombine it

}
void my_print_id(struct node *HEAD, char *Name){
	// Print the id of the corresponding Name.

	// If Name doesn’t exit, print “INVALID OPERATION”
        printf("INVALID OPERATION\n");
}
void my_print_name(struct node *HEAD, int ID){
	// Print the name of the corresponding ID

	// If ID doesn’t exit, print “INVALID OPERATION”
        printf("INVALID OPERATION\n");
}
void my_result(struct node* HEAD){
	// Print out all the information in the linked list orderly

	// in the format “ID NAME”. (start from HEAD)

}

