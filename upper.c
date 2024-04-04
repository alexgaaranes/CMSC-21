#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * toupperStr(char *s){
	int i, n = strlen(s);

	for(i=0;i<n;i++){
		s[i]=toupper(s[i]);
	}
	return(s);
}
int main(){
	char name[10];
	printf("What is your name: ");
	scanf("%s",name);
	printf("Your name is %s\n",toupperStr(name));
}