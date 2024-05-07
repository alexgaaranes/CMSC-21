#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void addStud(Nodeptr *hptr, int *entriesPtr);
void showRec(Nodeptr start);

// MAIN
int main(){
	// Declare the head
	Nodeptr head = NULL;
	int choice, entries = 0;

	// MAIN LOOP
	do{
		// get choice
		menu(&choice);
		switch(choice){
			case 1:
				addStud(&head, &entries);
				break;
			case 2:
				showRec(head);
				break;
			case 3:
				break;
			case 4:
				break;
			case 0:
				printf("Bye...\n");
				break;
			default:
				printf("Invalid Input\n\n");
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

void addStud(Nodeptr *hptr, int *entriesPtr){
	// Check if there is still space to add a new record
	if (*entriesPtr == 10){
		printf("Cannot Add Record: System Full\n");
		return;
	}

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
			if (strcmp(new->name.lastname,temp->name.lastname)<=0){
				// Check if to be inserted at the front
				if (trail == NULL && *entriesPtr == 1){
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
		temp->next = new;
		(*entriesPtr) += 1;
		return;
	}
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



// typedef struct stud_name{
// 	// Members that will compose the name
// 	char firstname[20], lastname[20];
// } Stud_name;

// typedef struct stud_node{
// 	// Student record data
// 	Stud_name name;
// 	char stud_num[10];
// 	int absences;
	
// 	// Self referencing pointer;
// 	struct stud_node* next_stud;
// } Student;

// // Typedef the Stud_Node pointer
// typedef Student* Stud_ptr;

// // Function Protoytpes
// void showMenu();
// int add(Stud_ptr* start_ptr, int* size);
// int showRecord(Stud_ptr Start);

// // MAIN
// int main(){
// 	Stud_ptr start = NULL;
// 	int size = 0, choice;
		
// 	// Main Program loop
// 	do {
// 		printf("[1] Add Student Record\n");
// 		printf("[2] Print All Student Records\n");
// 		printf("[3] Add Absence\n");
// 		printf("[4] Delete Student\n");
// 		printf("[0] Exit\n");
// 		scanf("%i", &choice);
		
// 		switch(choice){
// 			case 1:
// 				add(&start, &size);
// 				break;
// 			case 2:
// 				showRecord(start);
// 				break;
// 			case 3:
// 				break;
// 			case 4:
// 				break;
// 			case 0:
// 				printf("Bye!...\n");
// 				break;
// 			default:
// 				printf("Invalid Input\n");
	
// 		}
// 	} while(choice != 0);
// 	return 0;
// }

// // Function Implementation
// int add(Stud_ptr* start_ptr, int* size){
// 	if ((*size) == 10){
// 		printf("Cannot add: System Full (Max: 10)\n");
// 		return 0;
// 	}
// 	// Create a temp student pointer
// 	Stud_ptr temp;
// 	// Create a new Student Node
// 	temp = (Stud_ptr) malloc(sizeof(Student));
	
// 	// Get student data
// 	printf("Enter first name: ");
// 	scanf("%s", temp->name.firstname);
// 	printf("Enter last name: ");
// 	scanf("%s", temp->name.lastname);
// 	printf("Enter student number: ");
// 	scanf("%s", temp->stud_num);
// 	printf("Enter number of absences: ");
// 	scanf("%i", &(temp->absences));

// 	// Point to the current first element
// 	temp->next_stud = (*start_ptr);	
// 	*start_ptr = temp; // Become the first element
	
// 	*size += 1;
// 	return 1;
// }

// int showRecord(Stud_ptr start){
// 	Stud_ptr temp;
	
// 	// Start form first element
// 	temp = start;
	
// 	// If no record
// 	if(temp == NULL){
// 		printf("No record to show\n");
// 		return 0;
// 	}
// 	while(temp!=NULL){
// 		printf("Name: %s %s\n", temp->name.firstname, temp->name.lastname);
// 		printf("Student Number: %s\n", temp->stud_num);
// 		printf("Absences: %i\n", temp->absences);
// 		// Move to the next record
// 		temp = temp->next_stud;
// 	}

// 	return 1;
// }	




