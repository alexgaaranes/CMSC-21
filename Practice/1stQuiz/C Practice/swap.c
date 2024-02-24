#include <stdio.h>

void swap(int *, int *);

int main()
{
	int first, second;

	printf("Enter first number: ");
	scanf("%d", &first);

	printf("Enter second number: ");
	scanf("%d", &second);

	printf("Order before swap:\nFirst: %d\nSecond: %d\n", first, second);

	swap(&first, &second);

	printf("Order after swap:\nFirst: %d\nSecond: %d\n", first, second);

	return 0;

}// end of main

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

}//end of swap
