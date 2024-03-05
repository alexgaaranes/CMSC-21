#include <stdio.h>

int main(){
	int i = 5, j =7, *ptr1, *ptr2, **ptr3;

	ptr1 = &i;
	ptr2 = &j;

	printf("    i==%d    &i==%p\n", i, &i);
	printf("*ptr1==%d  ptr1==%p\n", *ptr1, ptr1);
	printf("    j==%d    &j==%p\n", j, &j);
	printf("*ptr2==%d  ptr2==%p\n", *ptr2, ptr2);

	ptr3 = &ptr1;
	printf("\nptr3==%p  *ptr3==%p **ptr3==%d\n", ptr3, *ptr3, **ptr3);

	ptr3 = &ptr2;
	printf("\nptr3==%p  *ptr3==%p **ptr3==%d\n", ptr3, *ptr3, **ptr3);

	ptr2 = *ptr3;
	printf("\nptr2==%p  *ptr2==%d\n", ptr2, *ptr2);

	return 0;
}