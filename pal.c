#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function Prototypes
int isPalindrome(char*);
int isExit(char*);
void upperStr(char*);
void showPalindromes(char **, int);
void freeAll(char **, int);

int main(){
	char** palArr; // Array of words that are palindrome
	int palCount = 0; // Counter of amount of palindromes

	// Allocate memory for the array
	palArr = (char **)malloc(sizeof(char*));

	while(1){
		*(palArr+palCount) = (char*) malloc(sizeof(char *)*20); // Allocate memory to each element (word)
		char** wordPtr = palArr+palCount; // Points on the last index the word will be placed in the array

		// Get input
		printf("Enter the word: ");
		scanf("%s", *wordPtr);

		if(isExit(*wordPtr)){	// Terminate if the word is "EXIT"
			showPalindromes(palArr, palCount);	// Show all Palindromes
			freeAll(palArr, palCount);	// Free all pointers including each word
			return 0;
		}

		// Uppercase all letters in the word to check properly
		upperStr(*wordPtr);

		// Check if the word is Palindrome
		if(isPalindrome(*wordPtr)){
			printf("%s is a palindrome.\n", *wordPtr);
			palCount++;
			palArr = realloc(palArr, sizeof(palArr)+sizeof(char*));	// Update the size of the array
		} else {
			printf("%s is NOT a palindrome.\n", *wordPtr);
		}
	}

}

// Functions Implementation
int isPalindrome(char* startPtr){	// The passed char* has the first letter of the string
	char* endPtr;
	int len;

	// Iterate through each letter
	for(int i=0; i<20; ++i){
		if(startPtr[i]=='\0'){
			endPtr = &(startPtr[i-1]); // Point on the last letter before '\0'
			len = i; // Length of the string
			break;
		}
	}

	// Iterate and compare from the start and end
	for(int i=0; i<(len/2); ++i){
		if(startPtr[i] != *endPtr){	// Compare letters
			return 0;
		}
		endPtr--;	// Move end-pointer 1 letter to the left
	}

	return 1;
}


int isExit(char* word){
	if(
		word[0] == 'E' &&
		word[1] == 'X' &&
		word[2] == 'I' &&
		word[3] == 'T' &&
		word[4] == '\0' 
		){return 1;}
	return 0;
}

void upperStr(char* word){
	for(int i=0; i<20; ++i){
		if(word[i]=='\0'){break;}
		word[i] = toupper(word[i]);
	}
}

void showPalindromes(char** palArr, int palCount){
	printf("Palindromes:\n");
	for(int i=0; i<palCount; ++i){
		printf("%s\n", *(palArr+i));
	}
}

// ERROR HERE
void freeAll(char ** palArr, int palCount){
	for(int i=0; i<palCount; ++i){
		free(*(palArr+i));
	}
	free(palArr);
}