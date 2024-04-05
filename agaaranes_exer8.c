#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototype
void transpose(char **, char ***, int, int, int);

// Main
int main(){
	char * plainText;	// Array
	char ** cipherText;	// 2D Array
	int key, row, length;

	plainText = (char *) malloc(sizeof(char *)*100); // Allocate for 100 characters

	// INPUT
	printf("Enter the plaintext: ");
	scanf("%[^\n]", plainText);
	printf("Enter the key (number of columns): ");
	scanf("%d", &key);

	// Get the length of teh string and row number
	length = strlen(plainText);
	row = length/key;
	if (row*key < length){	// Add 1 to the row if the length exceeds the amount of space
		row++;
	}

	// Allocate the rows
	cipherText = (char **) malloc(sizeof(char *)*row);

	// Cipher the plainText
	transpose(&plainText, &cipherText, key, length, row);

	// Deallocate rows, row pointer, and plainText
	for(int i=0; i<row; i++){
		free(cipherText[i]);
	}
	free(cipherText);
	free(plainText);

	return 0;
}

// Function Implementation
void transpose(char ** plainPtr, char *** cipherPtr, int key, int length, int row){
	// *cipherPtr = cipherText (main)
	// *plainPtr  =  plainText (main)

	// Iterate through each row and populate the grid
	for(int i=0; i<row; ++i){
		(*cipherPtr)[i] = (char *) malloc(sizeof(char *)*key); // Allocate columns (cell)

		for(int j=0; j<key; ++j){
			if (j+(key*i) > length-1){
				(*cipherPtr)[i][j] = ' ';	// Put a space on empty cells
			} else {
				(*cipherPtr)[i][j] = (*plainPtr)[j+(key*i)];	// Put the character into the grid
			}
			// (*cipherPtr)[i][j] = (*plainPtr)[j+(key*i)];
		}
	}

	// Read and print the array row-wise
	printf("Ciphertext: ");
	for(int i=0; i<key; ++i){
		for(int j=0; j<row; ++j){
			printf("%c", (*cipherPtr)[j][i]);
		}
	}
	printf("\n");
}