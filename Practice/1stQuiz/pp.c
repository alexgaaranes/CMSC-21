#include <stdio.h>

int main(){
	int num, *ptr, **pptr, ***ppptr;

	num = 5;

	printf("Number is: %d\n", num);

	ptr = &num;
	printf("*ptr is: %d\n", *ptr);

	pptr = &ptr;
	printf("**ptr is: %d\n", **pptr);

	ppptr = &pptr;
	printf("***ppptr is: %d\n", ***ppptr);


	return 0;
}