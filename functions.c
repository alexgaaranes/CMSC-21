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
	printf("---------------------\nEnter: ");	

	scanf("%i", opt);
}

char * strLower(char *str){
	// Lower case all letters in the string
	for(int i=0; i<strlen(str); i++){
		str[i] = tolower(str[i]);
	}
	
	return str;
}

void dealloc(Nodeptr *hptr){
	Nodeptr temp = NULL;	// This will free the nodes
	while((*hptr)!=NULL){
		temp = *hptr;		// Follow the head
		*hptr = (*hptr)->next;	// Move the head to the next
		free(temp);		// Free node
	}
}

int validStudnum(char *id){
	if(strlen(id)!=10){
		printf("Invalid Student Number\n");
		return 0;
	}

	for(int i=0; i<10; i++){
		if (i!=4){
			if (!isdigit(id[i])){
				printf("Invalid Student Number\n");
				return 0;
			}
		} else if (id[4] != '-'){
			printf("Invalid Student Number\n");
			return 0;
		}
	}

	return 1;	// Return 1 if valid, 0 otherwise
}

int availStudnum(Nodeptr temp, char *id){
	while(temp!=NULL){
		if(!strcmp(id, temp->studnum)){
			printf("Student Number Exists\n");
			return 0;
		}
		temp = temp->next;
	}

	return 1;	// Retrun 1 if available, 0 otherwise
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
	printf("\nSaving Successful\n");
	return;
}

void loadData(FILE * src, Nodeptr *hptr, int *entries){
	// Check for file
	if ((src = fopen("data.txt", "r")) == NULL){
		printf("\nCannot Load: No save file\n");
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
	printf("\nLoading Successful\n");
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

	// Add information to the new student node
	printf("Enter name <first name> <last name>: ");
	scanf("%s %s", new->name.firstname, new->name.lastname);
	printf("Enter student number: ");	
	scanf("%s", new->studnum);
	// Check student number if available and valid
	if (!validStudnum(new->studnum) || !availStudnum(*hptr, new->studnum)){return;}

	printf("Enter number of absences: ");
	scanf("%i", &new->absences);

	// Check number of absences
	if (new->absences < 0){printf("Invalid Number of Absences\n"); return;}

	// Initialize to NULL
	new->next = NULL;

	// Start from the first entry
	temp = *hptr;

	// Check if linked list is empty
	if (temp==NULL){
		// Make the new node the first element
		(*hptr) = new;
	} else {
		// Compare Last Names
		char newLastName[20], tempLastName[20];
			
		/*	Create a copy of the string
			to avoid modification of the
			original string */
		strcpy(newLastName,new->name.lastname);
		strcpy(tempLastName, temp->name.lastname);
		
		// Check on the first entry
		if(strcmp(strLower(newLastName),strLower(tempLastName)) < 0){
			new->next = *hptr;
			*hptr = new;
		}else if(strcmp(strLower(newLastName),strLower(tempLastName))==0){
			// If same last name, compare firstnames
			char newFirstName[20], tempFirstName[20];

			strcpy(newFirstName, new->name.firstname);
			strcpy(tempFirstName, temp->name.firstname);

			if (strcmp(strLower(newFirstName),strlower(tempFirstName))<=0){
				new->next = *hptr;
				*hptr = new;
			} else {
				// do something
			}
		} else { // Check the rest
			if(temp->next == NULL){	// If one element only
				temp->next = new;
			} else {
				// get the last name of the next entry
				strcpy(tempLastName, temp->next->name.lastname);
				
				// Iterate through the rest of the linked list
				// Stop when position is found
				while(temp->next != NULL && strcmp(strLower(newLastName), strLower(tempLastName)) > 0){
					// get the last name of the next entry
					//strcpy(tempLastName, temp->next->name.lastname);
					temp = temp->next;
					// get the last name of the next entry
					if (temp->next != NULL){
						strcpy(tempLastName, temp->next->name.lastname);
					}
				}
				
				// Insert (works in both middle and tail)
				new->next = temp->next;
				temp->next = new;
			}
		}
	}
	(*entriesPtr) += 1;	// update num of entries
	printf("New Record Added!\n");
	return;
}

void showRec(Nodeptr temp){
	// Check if the linked list is empty
	if (temp == NULL){
		printf("There is no record to show.\n");
		return;
	}

	// Iterate through all entries
	printf("\n\n-------------------------------------Records------------------------------------\n\n");
	printf("Name\t\t\t\t\t\tStudent No.\tAbsences\n");
	printf("First Name\t     Last Name\n");
	printf("--------------------------------------------------------------------------------\n");
	while(temp != NULL){
		printf("%-20s %-20s\t", temp->name.firstname, temp->name.lastname);
		printf("%-10s\t", temp->studnum);
		printf("%-3i\n", temp->absences);

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

	// Check student number if available and valid
	if (!validStudnum(reqnum)){return;}

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

	// Check student number if available and valid
	if (!validStudnum(reqnum)){return;}
	
	Nodeptr temp = (*hptr), delptr = NULL;	// Make a pointer that points at the start and a trailing pointer
	
	// Check the first element
	if(strcmp(reqnum, temp->studnum) == 0){
		(*hptr) = (*hptr)->next;	// Move the head to the next record
		free(temp);			// Delete the first element
	} else {	// Check for the record after the pointed record
		// loop and stop if found a match or no existing match
		while(temp->next != NULL && strcmp(temp->next->studnum, reqnum) != 0){
			temp = temp->next;
		}

		if (temp->next != NULL){
			delptr = temp->next;	// assign the delptr to the matched node
			temp->next = delptr->next;	// skip over the node to be deleted
			free(delptr);
		} else {
			printf("No matched student number\n");	
			return;
		}
	}
	(*entries) -= 1;	// updates no. of entries
	printf("Record Deleted\n");
	return;
}

