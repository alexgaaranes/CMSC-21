#include<stdio.h>

void check(int);

int main()
{
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	check(num);

	return 0;

}// end of main

void check(int x)
{
	switch(x%2)
	{
		case 0:
			printf("The entered number is even.\n");
			break;
		case 1:
			printf("The entered number is odd.\n");
	}// end of switch
}//end of check