#include <stdio.h>
#include "func.c"

// Main
int main()
{
	// initialize variables
	int choice, n, k, answer;


	// main program loop
	do
	{
		banner();
		printf("[0] Proceed\n[1] Exit\nEnter choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				banner();
				// get inputs
				printf("Amount of objects/cells N: ");
				scanf("%d", &n);

				printf("Amount of sample/distribution of K: ");
				scanf("%d", &k);
				

				if (checkSize(n, k))
				{
					answer = evalMode(getMode(isExclu(), isDist()), n, k);
					showAnswer(n, k, answer);

				} else { // N is less than K, automatically non-exclusive
					answer = evalMode(getMode(0, isDist()), n, k);
					showAnswer(n, k, answer);
				}

				break; // end of case 0

			case 1:
				printf("\nGoodbye...\n");
				break;
			default:
				printf("\nInvalid Input\n");
		}// end of switch

	}while (choice!=1); // end of while

	return 0;
}// end of main






