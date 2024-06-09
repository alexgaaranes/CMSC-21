#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
	int val;
	struct nd *next, *prev;
}node;

typedef node* nptr;


// Creates a new node
nptr createNode(){
	nptr new = (nptr) malloc(sizeof(node));

	if (new == NULL){printf("Memory Alloc Failed\n");exit(1);}

	printf("Enter value: ");
	scanf("%i", &(new->val));
	new->next = NULL;
	new->prev = NULL;

	return new;
}

// Add a new node
nptr addNode(nptr *hptr, nptr *tptr){
	nptr new = createNode();


	// empty case
	if (*hptr == NULL){
		*hptr = new;
		new->next = new;
		new->prev = new;
		*tptr = new;
	} else if ((*hptr)->next == *tptr && new->val < (*hptr)->val){	// one or two element
		new->next = *hptr;
		new->prev = *tptr;
		(*hptr)->prev = new;
		(*tptr)->next = new;
		*hptr = new;
	} else {	// more than one element
		nptr temp = *hptr;

		while(temp!=*tptr && new->val >= temp->next->val){
			temp = temp->next;
		}

		if (temp==*tptr){	// temp at tail	(append)
			new->prev = *tptr;
			new->next = *hptr;
			(*tptr)->next = new;
			*tptr = new;
		} else {	// middle (insert)
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
		}

	}
	return new;

}

void showCurr(nptr curr){
	if (curr != NULL){
		printf("\nValue: %i\n\n", curr->val);
	} else {
		printf("\nEmpty list\n\n");
	}
}

nptr delNode(nptr *hptr, nptr *tptr, nptr curr){
	nptr temp = *hptr;

	if (curr->val == (*hptr)->val){	// if first element
		*hptr = (*hptr)->next;
		(*tptr)->next = *hptr;
		free(temp);		
	}
}

void dealloc(nptr *hptr, nptr *tptr){
	if (*hptr == NULL){
		return;
	}

	nptr temp = *hptr;
	// disconnect first
	(*tptr)->next = NULL;

	while(*hptr!=NULL){
		temp = *hptr;
		*hptr = (*hptr)->next;
		free(temp);
	}
}


int main(){
	nptr head = NULL, tail = NULL, current = NULL;
	int choice;

	do{
		showCurr(current);
		printf("[1] Add\t\t[2] Del\n[3] Next\t[4] Prev\n------------------------\nChoice: ");
		scanf("%i", &choice);

		switch(choice){
			case 1:
				current = addNode(&head, &tail);
				break;
			case 2:
				break;
			case 3:
				current = current->next;
				break;
			case 4:
				current = current->prev;
				break;
			case 0:
				printf("Exit Successful\n");
				break;
			default:
				printf("\nInvalid Input\n");

		}

	}while(choice!=0);

	dealloc(&head, &tail);
	return 0;
}