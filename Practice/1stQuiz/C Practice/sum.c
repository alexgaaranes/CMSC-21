#include <stdio.h>

int getSum(int, int);

int main()
{
	int x, y, total;
	printf("Enter first number: ");
	scanf("%d", &x);

	printf("Enter second number: ");
	scanf("%d", &y);

	total = getSum(x,y);

	printf("The sum of %d and %d is %d\n", x, y, total);
	return 0;
} // end of main

int getSum(int a, int b)
{
	int sum;
	sum = a + b;
	return sum;
}