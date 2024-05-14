#include <stdio.h>
#include "functions.h"


// MAIN
int main(){
	// Declare the head
	Nodeptr head = NULL;
	int choice, entries = 0;
	FILE *source;

	// LOAD AT INITIAL STATE
	loadData(source, &head, &entries);

	// MAIN LOOP
	do{
		// get choice
		menu(&choice);
		switch(choice){
			case 1:
				addStud(&head, &entries);	// Add a record
				break;
			case 2:
				showRec(head);				// Show records
				break;
			case 3:
				addAbs(head, entries);		// Add absent
				break;
			case 4:
				delStud(&head, &entries);	// Delete a record
				break;
			case 0:
				saveData(source, head, entries);
				printf("\n...Program Closed...\n");			// Exit
				break;
			default:
				printf("Invalid Input\n\n");// Invalid Input
		}

	}while (choice != 0);
	
	// dealloc
	dealloc(&head);
	return 0;
}






