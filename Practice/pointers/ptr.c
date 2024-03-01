#include <stdio.h>
#include <stdlib.h>

// Prototype


int main(){
	int m = 29, *ab;

	printf("Address of m: %p\n", &m);
	printf("Value of m: %d\n", m);

	ab = &m; // ab points to m's address
	printf("Now ab is assigned with the address of m.\n");
	printf("Address of pointer ab: %p\n", ab);
	printf("Content of pointer ab: %d\n", *ab);

	m = 34; // assign 34 to m
	printf("The value of m assigned to 34 now.\n");
	printf("Address of the pointer ab: %p\n", ab);
	printf("Content of pointer ab: %d\n", *ab);

	*ab = 7; // assign 7 to the address ab is pointing to
	printf("The pointer variable ab is assigned with the value of 7 now.\n");
	printf("Address of m: %p\n", &m);
	printf("Value of m: %d\n", m);

	return 0;
}// end of main

// Implementation