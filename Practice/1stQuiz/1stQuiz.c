// Answer to the first quiz in CMSC21

// Problem: Given a whole number N
// 	    If N is odd, print all odd numbers from N to 1
// 	    If N is even, print all even numbers from N to 0

#include <stdio.h>

int main(){
	
	int N;

	printf("Give a whole number: ");
	scanf("%d", &N);
	
	while (N>=0){
		printf("%d\n",N);
		N -= 2;
	}
	return 0;
}

