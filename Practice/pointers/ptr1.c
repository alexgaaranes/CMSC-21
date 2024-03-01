#include <stdio.h>

int main(){
	printf("Pointer : Demonstrate the use of & and * operator: \n");

	// INITIALIZE
	int m = 300, *ptrm;
	float fx = 300.600006, *ptrfx;
	char cht = 'z', *ptrcht;

	printf("\nUsing & operator :\n_____________________\n");
	printf("address of m = %p\n", &m);
	printf("address of fx = %p\n", &fx);
	printf("address of cht = %p\n", &cht);

	printf("\nUsing & and * opertor:\n_______________________\n");
	printf("value at address of m = %d\n", *(&m));
	printf("value at address of fx = %f\n", *(&fx));
	printf("value at address of cht = %c\n", *(&cht));

	// pointers point to corresponding variable addresses
	ptrm = &m;
	ptrfx = &fx;
	ptrcht = &cht;

	printf("\nUsing only pointer variable:\n_____________________________\n");
	printf("address of m = %p\n", ptrm);
	printf("adderss of fx = %p\n", ptrfx);
	printf("address of cht = %p\n", ptrcht);

	printf("\nUsing only pointer operator:\n_____________________________\n");
	printf("value at address of m = %d\n", *ptrm);
	printf("value at address of fx = %f\n", *ptrfx);
	printf("value at address of cht = %c\n", *ptrcht);

	return 0;
}// end of main