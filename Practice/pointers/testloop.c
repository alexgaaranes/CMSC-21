#include <stdio.h>

int main(){

	// ++i
	for (int i=0; i<5; ++i){
		printf("%d", i);
	}

	printf("\n");

	// i++
	for (int i=0; i<5; i++){
		printf("%d", i);
	}

	printf("\n");
	return 0;
}