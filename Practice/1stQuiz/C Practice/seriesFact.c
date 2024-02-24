#include<stdio.h>

// WIP
int factorial(int);

int main()
{
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	printf("The sum of the series is: %d\n", factorial(num));

	return 0;
}// end of main

int factorial(int n)
{
	int f=1,x=0;
	while (x<=n-1)
	{
		f = f+f*x;
		x++;
	}
	return f;
}// end of factorial