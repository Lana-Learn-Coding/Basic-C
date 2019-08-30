/**
* Check whether a number is odd and if is a common-multiple of 3 and 5
*/
#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int number;
	int isOdd, isCommonMultipleOf3And5;

	printf("nhap so nguyen\n");
	scanf("%d", &number);

	isOdd = (number % 2) != 0;
	isCommonMultipleOf3And5 = (number % 3) == 0 && (number % 5) == 0;


	if (isOdd) {
		printf("day la so le\n");
	} else {
		printf("day la so chan\n");
	}

	if (isCommonMultipleOf3And5) {
		printf("chia het cho 3 va 5\n");
	} else {
		printf("khong chia het cho 3 va 5\n");
	}

	getch();
	return 0;
}
