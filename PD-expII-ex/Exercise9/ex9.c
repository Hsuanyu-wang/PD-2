#include <stdio.h>
#include <stdlib.h>

struct tNode{
	int data;
	struct tNode *Lchild, *Rchild;
};

struct tNode *insert(struct tNode *curNode, int data){
	//insert
	if (curNode == NULL){
		//create new node
		struct tNode *newData = (struct tNode *) malloc(sizeof (struct tNode));
		newData->data = data;
		newData->Lchild = NULL;
		newData ->Rchild = NULL;
		return newData;
	}
	else{	//find proper position
		if (data < curNode -> data) curNode -> Lchild = insert(curNode -> Lchild, data);
		else curNode ->Rchild = insert(curNode -> Rchild, data);
	}
	return curNode;
}

void traverse(struct tNode *curNode){
//************************* You should write ***********************//
// if the current node is NULL means it goes to one of the branch end
    if(curNode == NULL)
        return;
// in-order means goes to all the node on left side until there's no other nodes,
    else{
        traverse(curNode->Lchild);
// then print the current Node
        printf("%d ", curNode->data);
// after printing, then goes to the right node
        traverse(curNode->Rchild);
    }
//hint: recursive is a good idea
//*************************** Don't forget *************************//
}

int find(struct tNode *curNode, int target){
	//************************* You should write ***********************//
	// if find the target, return the sum of data contains in its Lchild and Rchild
	// NULL is seen as 0
	if(curNode==NULL){
        printf("Not in tree\n");
        return -1;
	}
    if (curNode->data < target){
        return find(curNode->Rchild, target);
    }
    else if (curNode->data > target){
        return find(curNode->Lchild, target);
    }
    else if (curNode->data == target){
        int a=0,b=0;
        if(curNode->Lchild != NULL)
        a=curNode->Lchild->data;
        if(curNode->Rchild !=NULL)
        b=curNode->Rchild->data;
        return (a+b);
    }
	// if not, return "Not in tree\n"
	//*************************** Don't forget *************************//
}

void delete_tree(struct tNode* curNode){
	if (curNode == NULL) return;
	delete_tree(curNode->Lchild);
	delete_tree(curNode->Rchild);
	free(curNode);
}

int main(){
	int numData = 0;
	int tmpNum;
	scanf("%d", &numData);

	struct tNode *root = NULL;

	//insert every data, all data > 0
	for (int i = 0; i < numData; i++){
		scanf("%d", &tmpNum);
		root = insert(root, tmpNum);
	}

	//traverse
	traverse(root);
	puts("");

	//find
	while(scanf("%d", &tmpNum)!=EOF){
		int sum = find(root, tmpNum);
		if (sum != -1) printf("%d\n", sum);
	}

	//free memory
	delete_tree(root);
	return 0;
}
