#include <stdio.h>
#include <stdlib.h>

int main(){
	char * text;
	int key;

	// ALLOCATE
	text = (char *) malloc(sizeof(char *)*100);

	// INPUTS
	printf("Enter your text: ");
	scanf("%s", text);
	printf("Enter key: ");
	scanf("%d", &key);


	printf("%s\n - Key: %d", text, key);

	free(text);
	return 0;
}