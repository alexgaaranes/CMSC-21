#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
void transpose(char **, char ***, int);

// Main
int main(){
	char * plainText;
	char ** cipherText;	// 2D Array
	int key;

	// Allocate memory for the text and 2D array
	plainText = (char *) malloc(sizeof(char *)*100);

	// INPUT
	printf("Enter the plaintext: ");
	scanf("%[^\n]", plainText);
	printf("Enter the key (number of columns): ");
	scanf("%d", &key);

	// Cipher the text
	transpose(&plainText, &cipherText, key);

	free(plainText);
	return 0;
}

// Implementations
void transpose(char ** plainPtr, char *** cipherPtr, int key){
	int length = strlen(*plainPtr);
	int row = length/key;
	if (key*row < length){
		++row;
	}

	*cipherPtr = (char **)malloc(sizeof(char *)*row);	// Allocate Rows

	// Populate the grid with characters
	for(int i=0; i<row; ++i){
		(*cipherPtr)[i] = (char *) malloc(sizeof(char*)*key);	// Allocate memory for the row

		for(int j=0; j<key; ++j){
			(*cipherPtr)[i][j] = (*plainPtr)[j+(key*i)];	// Put the character

		}
	}

	// Read the Array row-wise
	for(int i=0; i<key; ++i){
		for(int j=0; j<row; ++j){
			printf("%c", (*cipherPtr)[j][i]);
		}
	}
	printf("\n");
	

	// Deallocate 2D array
	for(int k=0; k<row; ++k){
		free((*cipherPtr)[k]);
	}
	free(*cipherPtr);
}