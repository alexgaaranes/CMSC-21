#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 4, choice;
	int *ptr;

	ptr = (int *) malloc(n * sizeof(int));

	// If memory allocation failed
	if (ptr == NULL){
		printf("Memory Allocation Failed\n");
		return 0;
	}

	// Enter Values
	printf("Enter the values:\n");
	for (int i = 0; i < n; ++i){
		scanf("%d", ptr+i);		// add the values to each memory address
	}// end of for-loop

	// Print Values
	printf("i   val  address\n-----------------------\n");
	for (int i = 0; i < n; ++i){
		printf("%d - ", i);
		printf("%d - %p\n", *(ptr+i), ptr+i);
	}

	// Access values in Dynamically Allocated Variable
	do {
		printf("Enter 1-4 to access value: ");
		scanf("%d", &choice);

		printf("%d\n", *(ptr+choice));
	}while(1);// end of while

	free(ptr);

	return 0;
}// end of main