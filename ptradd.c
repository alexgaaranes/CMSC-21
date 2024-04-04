#include <stdio.h>

int strLen(char *s){
	char *p = s;

	while(*p != '\0'){
		p++;
	}
	return p - s;
}

int main(){
	char arr[] = "Hello";
	char *p = &(arr[0]);
	char *q = &(arr[4]);

	printf("%p\n%p\n%ld\n", p, q, q-p+1);

	printf("%d\n", strLen(arr));
}