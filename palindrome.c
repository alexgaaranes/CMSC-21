#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Functions Prototypes
int isPalindrome(char *);
void upperStr(char *);
int isExit(char *);
void showPalindromes(char **, int);

int main(){
	int palCount=0;
	char ** palArr;

	palArr = (char **)malloc(sizeof(char *));

	while(1){
		// GET INPUT
		*(palArr+palCount) = (char *)malloc(sizeof(char *)*20);
		printf("Enter word: ");
		scanf("%s", *(palArr+palCount));

		// If word is "EXIT", show all palindromes and terminate
		if(isExit(*(palArr+palCount))){
			showPalindromes(palArr, palCount);
			free(palArr);
			return 0;
		}

		// Uppercase the letters to check properly
		upperStr(*(palArr+palCount));

		// Check if palindrome
		if (isPalindrome(*(palArr+palCount))){
			printf("%s is a palindrome.\n", *(palArr+palCount));
			palCount++;
			palArr = realloc(palArr, sizeof(char *)*palCount);
		} else {
			printf("%s is not a palindrome.\n", *(palArr+palCount));
		}
	}
	// free(palArr[i]);
	// return 0;
}

// Function Implementation
int isPalindrome(char* wordPtr){
	char* endPtr;
	int len;

	// Point to the end
	for(int i=0; i<20; ++i){
		if(wordPtr[i]==0){
			endPtr = &(wordPtr[i-1]);
			len = i;
			break;
		}
	}

	// Iterate from both sides
	for(int i=0; i<(len/2); ++i){
		printf("%c == %c\n", wordPtr[i], *endPtr);
		if(wordPtr[i] != *endPtr){
			return 0;
		} else {
			endPtr -= 1;
		}
	}

	return 1;
}

int isExit(char* word){
	if(word[0] == 'E' &&
	word[1] == 'X' &&
	word[2] == 'I' &&
	word[3] == 'T' &&
	word[4] == '\0'){
		return 1;
	}
	return 0;
}

void upperStr(char * word){
	for(int i=0; i<20; ++i){
		if(word[i]=='\0'){break;}
		word[i] = toupper(word[i]);
	}
}

void showPalindromes(char ** palArr, int palCount){
	printf("Palindromes:\n");
	for(int i=0; i<palCount; ++i){
		printf("%s\n", *(palArr+i));
	}
}