#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int number;
	int unitPosition, tensPosition;

	printf("nhap so co 2 chu so can dao nguoc\n");
	scanf("%d", &number);

	unitPosition = number % 10;
	tensPosition = number / 10;

	printf("so da dao nguoc la %d%d", unitPosition, tensPosition);

	getch();
	return 0;
}
