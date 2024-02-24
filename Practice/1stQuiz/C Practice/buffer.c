#include <stdio.h>

int main()
{
	int choice;
	char confirm;

	printf("Input: ");
	scanf("%d", &choice);

	switch (choice){
		case 1:
			printf("Case 1\n");
			break;
		case 2:
			printf("confirm y/n: ");
			scanf("%c", &confirm);

			if(confirm=='y')
			{
				printf("Confirmed\n");
			} else if (confirm=='n'){
				printf("Not confirmed\n");
			} else {
				printf("Invalid\n");
			}

	}// end of switch
	return 0;
}// end of main