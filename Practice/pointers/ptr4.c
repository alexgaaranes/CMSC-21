#include <stdio.h>
#include <stdlib.h>


// DAV
int main(){
	// initialize
	int *ptr;

	ptr = (int *) malloc(sizeof(int));

	printf("%p\n", ptr);

	free(ptr);

	return 0;
}// end of main