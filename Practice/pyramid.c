#include <stdio.h>

int main()
{
	int rows, i, j, k;
	printf("Enter rows: ");
	scanf("%d", &rows);

	 for (i; i<rows; i++){
	 	for (k=0; k<(rows-i)-1; k++){
	 		printf(" ");
	 	} // end of k for-loop
	 	for (j=0; j<=i*2; j++){
	 		printf("*");
	 	} // end of j for-loop

	 	printf("\n");
	 } // end of i for-loop

}// end of main