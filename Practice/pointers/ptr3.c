#include <stdio.h>

int main(){
	int len, *ptr;

	printf("Input the number of elements to store in the array: ");
	scanf("%d", &len);

	int numArr[len];

	for (int i=0; i<len; i++){
		printf("element - %d: ", i);
		scanf("%d", &numArr[i]);
	}

	printf("The elements you entered are: \n");
	for (int i=0; i<len; i++){
		ptr = &numArr[i];
		printf("element - %d: %d\n", i, *ptr);
	}

	return 0;
}