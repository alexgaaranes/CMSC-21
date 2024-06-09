#include <stdio.h>

#define MAXLEN 1000

int len(char *text){
	int i = 0;
	while(text[i] != '\0'){
		i++;
	}
	return i;
}

int kisame(float num1, float num2){
	float quo = num1/num2;
	if (quo > (int) quo){
		return (int) quo + 1;
	} else {
		return (int) quo;
	}
}

void transpose(char* text, int rows, int key, char mat[rows][key], int length){
	// populate
	for (int i=0; i<rows; i++){
		for (int j=0; j<key; j++){
			if (length > j+(i*key)){
				mat[i][j] = text[j+(i*key)];
			} else {
				mat[i][j] = ' ';
			}
		}
	}

	// show transposed populated matrix
	for (int k=0; k<key; k++){
		for (int l=0; l<rows; l++){
			printf("%c", mat[l][k]);
		}
		//printf("\n");
	}

	printf("\n");
}

int main(){

	char text[100];
	int key;

	// input
	printf("Enter text: ");
	scanf("%[^\n]%*c", text);

	printf("Enter key: ");
	scanf("%i", &key);

	int length = len(text);
	int rows = kisame(length, key);

	char mat[rows][key];

	transpose(text, rows, key, mat, length);

	return 0;
}