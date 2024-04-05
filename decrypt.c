#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt(char **, char ***, int, int, int);

int main(){
	char * encrypted;
	char ** decrypted;
	int key, length, row;

	// Allocate the number of characters
	encrypted = (char *) malloc(sizeof(char *)*100);
	

	// INPUT
	printf("Enter the encrypted text: ");
	scanf("%[^\n]", encrypted);
	printf("Enter the key: ");
	scanf("%d", &key);

	// Get integers
	length = strlen(encrypted);
	row = length/key;
	if (row*key < length){
		row++;
	}

	// Allocate the rows (in this case is the key)
	decrypted = (char **) malloc(sizeof(char *)*key);

	// Decrypt the text
	decrypt(&encrypted, &decrypted, key, length, row);

	// Deallocate
	for(int i=0; i<key; ++i){
		free(decrypted[i]);
	}
	free(decrypted);
	free(encrypted);

	return 0;
}

void decrypt(char ** encryptPtr, char *** decryptPtr, int key, int length, int row){
	// *encryptPtr = encyrpted	(main)
	// *decryptPtr = decrypted	(main)

	// Iterate through each row (key)
	for(int i=0; i<key; ++i){
		(*decryptPtr)[i] = (char *) malloc(sizeof(char *)*row); // Allocate for the column (row)

		for(int j=0; j<row; ++j){
			(*decryptPtr)[i][j] = (*encryptPtr)[j+(row*i)];	// Put the character into the grid
		}

	}

	// Read the array row-wise
	printf("Decrypted Text: ");
	for(int i=0; i<row; ++i){
		for(int j=0; j<key; ++j){
			printf("%c", (*decryptPtr)[j][i]);
		}
	}
	printf("\n");
}