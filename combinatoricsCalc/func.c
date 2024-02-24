#include "func.h"

int checkSize(int N, int K)
{
	if (N>=K){
		return 1;
	}
	return 0;
}// end of checkSize
// Function Implementation

void banner()
{
	printf("\n*******************\n                     \nCounting Calculator\n                     \n*******************\n");
}// end of banner


int isExclu()
{
	int exclu;

	do 
	{
		banner();
		printf("[0] Non-exclusive\n[1] Exclusive\nEnter choice: ");
		scanf("%d", &exclu);

	}while((exclu!=0)&&(exclu!=1));// end of while

	return exclu;
}// end of isExclu

int isDist()
{
	int distinct;

	do 
	{
		banner();
		printf("[0] Identical\n[1] Distinct\nEnter choice: ");
		scanf("%d", &distinct);

	}while((distinct!=0)&&(distinct!=1));// end of while

	return distinct;

}// end of isDistinct

int getMode(int E, int D)
{
	/*	
		1 - S
		2 - MS
		3 - P
		4 - C
	*/
	if((D==1)&&(E==0))
	{
		return 1;
	} else if ((D==0)&&(E==0)){
		return 2;
	} else if ((D==1)&&(E==1)){
		return 3;
	} else {
		return 4;
	}
}// end of getMode

int factorial(int num)
{
	if (num==1||num==0){
		return 1;
	} else {
		return num*factorial(num-1);
	}
}// end of factorial

int exponent(int base, int exp)
{
	if (exp==0)
	{
		return 1;
	} else {
		return base*exponent(base, exp-1);
	}
}// end of exponent

int multiSets(int n, int k)
{
	return (factorial(n-1+k)/(factorial(k)*factorial(n-1)));
}// end of multiSets

int permutation(int n, int k)
{
	return (factorial(n)/factorial(n-k));
}// end of permutation

int combination(int n, int k)
{
	return (factorial(n)/(factorial(k)*factorial(n-k)));
}// end of combination

int evalMode(int mode, int n, int k)
{
	switch(mode)
	{
		case 1:
			return exponent(n, k);
		case 2:	
			return multiSets(n, k);
		case 3:
			return permutation(n, k);
		case 4:
			return combination(n, k);

	}// end of switch
}// end of evalMode


void showAnswer(int n, int k, int answer)
{
	banner();
	printf("\nThere are %d ways from %d taken %d\n.", answer, n, k);
}// end of showAnswer