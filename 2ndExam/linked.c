#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
	int data;
	struct nd * next;
} node;

typedef node* nptr;

nptr createNode(){
	nptr new = (nptr) malloc(sizeof(node));\

	if (new==NULL){printf("Memory Alloc Failed\n");exit(1);}

	printf("Enter value: ");
	scanf("%i", &new->data);

	return new;
}


void addAtHead(nptr* hptr){
	nptr new = createNode();

	new->next = *hptr;
	*hptr = new;
}

void append(nptr* hptr){
	nptr temp = *hptr, new = createNode();

	if (temp==NULL){
		new->next = *hptr;
		*hptr = new;
	} else {
		while(temp->next!=NULL){
			temp = temp->next;
		}

		temp->next = new;
		new->next = NULL;
	}

}

void showList(nptr temp){
	while(temp!=NULL){
		printf("%i\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	nptr head=NULL;
	int choice;

	do {
		printf("[1] Add at head\n[2] Append\n[3] Show Linked List\n[0] Exit\n----------\nEnter choice: ");
		scanf("%i", &choice);

		switch(choice){
			case 1:
				addAtHead(&head);
				break;
			case 2:
				append(&head);
				break;
			case 3:
				showList(head);
				break;
			case 0:
				printf("Exit successful\n");
				break;
			default:
				printf("\nInvalid Input\n");

		}		

	}while(choice != 0);

	return 0;
}