// Day checker
// Uses the user input date and returns what day of the week it is

#include <stdio.h>

int leap(int year);

int main(){
	// variables
	int day;
	int month;
	int year;
	int dayDiff;

	int isLeap;

	// reference date 01/01/2024
	int refDay = 1;
	int refMon = 1;
	int refYear = 2024;	// a leap year
	int refAns = 1;

	// Input of the date
	printf("day: ");
	scanf("%d", &day);

	printf("month: ");
	scanf("%d", &month);

	printf("year: ");
	scanf("%d", &year);

	// Check if leap year
	switch(leap(year)){
		case 0:
			isLeap = 0;
			break;
		case 1:
			isLeap = 1;
			break;
	}

	// Calculate Days
	if (year>refYear){	// future
		if (month>refMon){
			if (isLeap){
				if (month==2){
					
				}
			}
		}

	} else if (year<refYear){
		
	} else {
		
	}





	switch(){
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
	}


	return 0;
}

int leap(int year){
	if (year%400==0){
		return 1;
	} else if (year%4==0){
		return 1;
	} else {
		return 0;
	}
}