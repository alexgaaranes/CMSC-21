#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct nd{
	int data;
	struct nd* right;
	struct nd* left;
} Node;

/* 
	To construct binary tree, every input
	of number will either go left or right.
	
	First number will always be the root
	If less the number is less than the parent node
		it will become the left child node
	else
		it will become the right child node
*/

Node * compareData(Node *parent, int num){
	// RECURSIVE CASE
	if (num >= parent->data){
		if (parent->right == NULL){	// RIGHT BASE CASE
			parent->right = (Node *)malloc(sizeof(Node));
			return parent->right;
		}
		return compareData(parent->right, num);
	} else {
		if (parent->left == NULL){	// LEFT BASE CASE
			parent->left = (Node *)malloc(sizeof(Node));
			return parent->left;	
		}
		return compareData(parent->left, num);
	}
}

void showTree(Node *parent){
	if (parent == NULL){
		return;
	}

	//printf("%i", parent->data);
	showTree(parent->left);
	printf("%i\t", parent->data);
	showTree(parent->right);
}

void searchTree(Node *parent, int num){
	if(parent==NULL){
		return;
	}
	
	searchTree(parent->left, num);
	if (parent->data == num){
		printf("[%i]\t", parent->data);
	} else {
		printf("%i\t", parent->data);
	}
	searchTree(parent->right, num);
}



// Main
int main(){
	Node root, *new_node;
	int size, entry;

	// Get size
	printf("Enter amount of num: ");
	scanf("%i", &size);
	
	// Make the Binary Tree
	for (int i=0; i<size; i++){
		printf("Enter num: ");
		scanf("%i", &entry);
		
		// Make the first number the root
		if (i==0){
			root.data = entry;
			root.right = NULL;
			root.left = NULL;
		} else {
			// Compare and Add to the Binary Tree
			new_node = compareData(&root, entry);
			new_node->data = entry;
			new_node->right = NULL;
			new_node->left = NULL;
		}
	}
	
	int choice, num;

	do{
		printf("[1] Search number\n");
		printf("[2] Show Tree\n");
		printf("[0] Exit\n");
		printf("Enter: ");
		scanf("%i", &choice);

		switch(choice){
			case 1:
				printf("Search num: ");
				scanf("%i", &num);
				searchTree(&root, num);
				printf("\n");
				break;
			case 2:
				showTree(&root);
				printf("\n");
				break;
			case 0:
				printf("Exit...\n");
				break;
			default:
				printf("Invalid Input\n");
		}

	}while(choice!=0);
	// Show tree
	//showTree(&root);
	//printf("\n");
	return 0;
}
