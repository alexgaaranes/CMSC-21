#include <stdio.h>
#include <stdlib.h>

int main(){
	int size = 4;
	int *ages;

	ages = (int *) malloc(size*sizeof(int));

	if (ages==NULL){
		printf("Memory Allocation Failed\n");
		return 0;
	}

	// Input values in the array
	printf("Enter values:\n");
	for (int i=0; i<size; ++i){
		scanf("%d", ages+i);
	}// end of for-loop

	// Print the elements
	printf("Array elements: ");
	for (int i=0; i<size; ++i){
		printf("%d ", *(ages+i));
	}// end of for-loop
	printf("\n");

	// Reallocate additional 2 bytes
	size += 2;
	ages = realloc(ages, size*sizeof(int));
	printf("Array length + 2\n");

	// assign new values
	ages[4] = 32;
	ages[5] = 59;

	// Print all the elements
	printf("Updated Array elements: ");
	for (int i=0; i<size; ++i){
		printf("%d ", *(ages+i));
	}// end of for-loop
	printf("\n");

	free(ages);
	return 0;
}// end of main