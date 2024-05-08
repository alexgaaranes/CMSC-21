#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for the name of the Student
struct stud_name{
	char firstname[20], lastname[20];
};

// Structure for the Student Record
typedef struct stud_record{
	struct stud_name name;
	char studnum[20];
	int absences;

	// Self referencing pointer
	struct stud_record* next;

} Node;

// type define the Node pointer
typedef Node* Nodeptr;

// Function Declarations
void menu(int *opt);
char * strLower(char *str);

void addStud(Nodeptr *hptr, int *entriesPtr);
void showRec(Nodeptr start);
void addAbs(Nodeptr temp, int entries);
void delStud(Nodeptr *hptr,  int *entries);

void saveData(FILE * src, Nodeptr temp, int entries);
void loadData(FILE * src, Nodeptr *hptr, int *entries);

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
				printf("Bye...\n");			// Exit
				break;
			default:
				printf("Invalid Input\n\n");// Invalid Input
		}
	}while (choice != 0);

	return 0;
}

// Function Implementation
void menu(int *opt){
	int choice;
	// UI
	printf("\n---Student Records---\n");
	printf("[1] Add Record\n");
	printf("[2] View Records\n");
	printf("[3] Add Absence\n");
	printf("[4] Delete Record\n");
	printf("[0] Exit\n");

	scanf("%i", opt);
}

char * strLower(char *str){
	char * temp = str;
	while(*temp!='\0'){
		*temp = tolower(*temp);
		*temp++;
	}
	
	return str;
}

void saveData(FILE * src, Nodeptr temp, int entries){
	// Check for file
	if ((src = fopen("data.txt", "w")) == NULL){
		printf("Unable to open file: File does not exist\n");
		return;
	}

	// If no entries yet
	if (entries == 0){
		printf("No records to save\n");
		fputc('0', src);
		fclose(src);
		return;
	}

	// Save data
	fprintf(src, "%i\n", entries);
	for (int i=0; i<entries; i++){
		fprintf(src, "%s %s\n", temp->name.firstname, temp->name.lastname);
		fprintf(src, "%s\n", temp->studnum);
		fprintf(src, "%i\n", temp->absences);
		temp = temp->next;
	}
	fclose(src);
	printf("Saving Successful\n");
	return;
}

void loadData(FILE * src, Nodeptr *hptr, int *entries){
	// Check for file
	if ((src = fopen("data.txt", "r")) == NULL){
		printf("Unable to open file: File does not exist\n");
		return;
	}

	// Load num of entries
	fscanf(src, "%i", entries);

	// If no entries yet
	if (*entries == 0){
		printf("No records to load\n");
		fclose(src);
		return;
	}

	// Load data and allocate memory for each entry
	Nodeptr temp = NULL, new = NULL;
	for (int i=0; i<(*entries); i++){
		new = (Nodeptr) malloc(sizeof(Node));	// Allocate for new node

		// Get the data
		fscanf(src, "%s %s\n", new->name.firstname, new->name.lastname);
		fscanf(src, "%s\n", new->studnum);
		fscanf(src, "%i\n", &new->absences);

		if (i==0){
			(*hptr) = new;
			temp = (*hptr);
		} else {
			temp->next = new;
			temp = temp->next;
		}

		new = NULL;
	}

	fclose(src);
	printf("Loading Successful\n");
	return;
}

void addStud(Nodeptr *hptr, int *entriesPtr){
	// Check if there is still space to add a new record
	if (*entriesPtr == 10){
		printf("Cannot Add Record: System Full\n");
		return;
	}
	
	printf("\n-- Adding a Record --\n");
	// New node and pointers
	Nodeptr new, temp, trail = NULL;
	new = (Nodeptr) malloc(sizeof(Node));

	// Check if allocation fails
	if (new == NULL){
		printf("Cannot Add Record: Memory Allocation Failed\n");
		return;
	}

	// Add information to the new student node (PLS MAKE A CHECKER)
	printf("Enter name (format: <first name> <last name>): ");
	scanf("%s %s", new->name.firstname, new->name.lastname);
	printf("Enter student number (e.g. 2000-12345): ");
	scanf("%s", new->studnum);
	printf("Enter number of absences: ");
	scanf("%i", &new->absences);
	// Initialize to NULL
	new->next = NULL;

	// Start from the first entry
	temp = *hptr;

	// Check if linked list is empty
	if (temp==NULL){
		// Make the new node the first element
		(*hptr) = new;

	} else {
		// Iterate through the list
		while(temp!=NULL){
			// Compare Last Name (negative == should come earlier)
			char newLastName[20], tempLastName[20];
			strcpy(newLastName,new->name.lastname);
			strcpy(tempLastName,temp->name.lastname);

			if (strcmp(strLower(newLastName),strLower(tempLastName))<=0){
				// Check if to be inserted at the front
				if (trail == NULL){
					new->next = (*hptr);
					(*hptr) = new;
				} else {
					new->next = temp;
					trail->next = new;
				}
				(*entriesPtr) += 1;
				return;
				
			}
			trail = temp;	// point to the node before
			temp = temp->next;	// Move to the next node
		}
		// If exhausted the whole linked list (Adding to tail)
		trail->next = new;
	}

	(*entriesPtr) += 1;
	return;
}

void showRec(Nodeptr temp){
	if (temp == NULL){
		printf("There is no record to show.\n");
		return;
	}

	// Iterate through all entries
	printf("\n-- Records --\n");
	while(temp != NULL){
		printf("Name: %s %s\n", temp->name.firstname, temp->name.lastname);
		printf("Student Number: %s\n", temp->studnum);
		printf("Absences: %i\n", temp->absences);

		// Move to the next student node
		temp = temp->next;
	}

	return;
}

void addAbs(Nodeptr temp, int entries){
	// Check if there entries to update absences
	if (entries == 0){
		printf("Cannot add: System is empty\n");
		return;
	}
	
	printf("\n-- Adding Absent--\n");
	
	// Request for the student number to edit
	char reqnum[20];

	printf("Enter the student number: ");
	scanf("%s", reqnum);

	while(temp!=NULL){
		// Check for matching student number
		if(strcmp(reqnum,temp->studnum) == 0){
			temp->absences += 1;
			printf("Added an absent to %s's record.\n", temp->name.lastname);
			return;
		}
		temp = temp->next;
	}
	// Exhausted the linked list
	printf("No matched student number.\n");
	return;
}


void delStud(Nodeptr *hptr, int *entries){
	if (*entries == 0){
		printf("Cannot Delete: System is empty\n");
		return;
	}
	
	printf("\n-- Deleting a Record --\n");
	// Request for the student number that corresponds to the record to be deleted
	char reqnum[20];
	
	printf("Enter the student number: ");
	scanf("%s", reqnum);
	
	Nodeptr temp = (*hptr), trail = NULL;	// Make a pointer that points at the start and a trailing pointer
	while(temp!=NULL){
		// Check for matched student number
		if (strcmp(reqnum, temp->studnum) == 0){
			// Check if deleting first record
			if (trail == NULL){
				(*hptr) = (*hptr)->next;	// Move the head to the next record
				free(temp); // Delete the first record
			} else {
				trail->next = temp->next; // Make the trailing pointer's record skip the record being pointed at by temp
				free(temp); // Delete the record
			}
			(*entries) -= 1;
			return;
		}
		// Move the trailing pointer and the temp
		trail = temp;
		temp = temp->next;
	}
	// If the linked list is exhausted
	printf("No matched student number.\n");
	return;
}





