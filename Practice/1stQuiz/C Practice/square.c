#include<stdio.h>

int square(int);

int main()
{
	int num;
	printf("Enter a number to square: ");
	scanf("%d", &num);

	printf("The square of %d is %d.\n", num, square(num));
	return 0;
}// end of main

int square(int a)
{
	return a*a;
}// end of square