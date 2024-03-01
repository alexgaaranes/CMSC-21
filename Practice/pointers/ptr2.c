#include <stdio.h>

void input(int *num){
	scanf("%d", num);
}

void add(int *num1, int *num2, int *answer){
	*answer = *num1 + *num2;
}

int main(){
	int num1, num2, result;

	// input
	printf("Input the first number: ");
	input(&num1);

	printf("Input the second number: ");
	input(&num2);

	// add
	add(&num1, &num2, &result);

	printf("The sum of the entered numbers is: %d\n", result);

	return 0;
}