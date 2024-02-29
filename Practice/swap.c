#include <stdio.h>

void swap(int *, int *);

int main(){
	int x, y;

	// INPUT
	printf("Enter x: ");
	scanf("%d", &x);

	printf("Enter y: ");
	scanf("%d", &y);

	// SHOW BEFORE
	printf("Before swap:\nx: %d\ny: %d\n", x, y);

	// SWAP
	swap(&x, &y); // pass the address

	// SHOW AFTER
	printf("\nAfter swap:\nx: %d\ny: %d\n", x, y);


	return 0;
}


void swap(int *ptr1, int *ptr2){
	int temp;
	// swap
	temp = *ptr1; // point to x address, get the value, assign to temp
	*ptr1 = *ptr2; //point to y address, get value, put value to the address of x
	*ptr2 = temp; // put value of temp to address of y
}