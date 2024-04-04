#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Prototype
int isPalindrome(char *);
int isExit(char*);
void upperStr(char*);
void showPalindromes(char **, int);
void freeAll(char **, int);

// Main
int main(){
	char **wordArr;		// Array of words
	int wordCount = 0;	// Counts the amount of palindromes in the wordArr

	// Allocate memory for the array
	wordArr = (char **)malloc(sizeof(char *));

	// Check if memory allocation failed
	if (wordArr == NULL){
		printf("Memory allocation for wordArr failed.\n");
		return 0;
	}

	while(1){	// Loop until "EXIT" is used as an input
		wordArr[wordCount] = (char*)malloc(sizeof(char *)*20);	// Allocate for the word

		// Check if memory allocation failed
		if (wordArr[wordCount] == NULL){
			printf("Memory allocation for the word failed.\n");
			return 0;
		} 

		char **wordPtr = &wordArr[wordCount];	// Point on the address the word will be placed (avoids long copypaste)

		// INPUT
		printf("Enter the word: ");
		scanf("%s", *wordPtr);

		// Check if the word is "EXIT"
		if(isExit(*wordPtr)==0){
			showPalindromes(wordArr,wordCount);
			freeAll(wordArr, wordCount);
			return 0;
		}

		// Uppercase all letters in the word to check properly
		upperStr(*wordPtr);

		// Check if the word is a palindrome or not
		if(isPalindrome(*wordPtr)){
			printf("%s is a palindrome.\n", *wordPtr);
			wordCount++;
			wordArr = realloc(wordArr, sizeof(char *)*(wordCount+1)); // Create space for the next word
		} else {
			printf("%s is not a palindrome.\n", *wordPtr);
			free(wordArr[wordCount]); // Free the address
		}		
	}
}

// Implementation
int isPalindrome(char * word){
	int i, length = strlen(word);
	for(i=0;i<(length/2);++i){
		if (word[i] != word[length-i-1]){
			return 0;
		}
	}
	return 1;
}

int isExit(char *word){
	char exit[] = "EXIT";
	return strcmp(word,exit);
}

void upperStr(char* word){
	int i, length = strlen(word);
	for(i=0; i<length; ++i){
		word[i] = toupper(word[i]);
	}
}

void showPalindromes(char** wordArr, int wordCount){
	printf("Palindromes:\n");
	for(int i=0; i<wordCount; ++i){
		printf("%s\n", wordArr[i]);
	}
}

void freeAll(char ** wordArr, int wordCount){
	for(int i=0; i<wordCount; ++i){
		free(wordArr[i]);
	}
	free(wordArr);
}