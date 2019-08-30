#include <stdio.h>
#include <conio.h>


int main(int argc, char const *argv[])
{
	int fourDigitsNumber;
	int unit, dozens, hundreds, thounsands;

	printf("nhap so nguyen duong can tach\n");
	scanf("%d", &fourDigitsNumber);

	// note: this can be replaced with a loop.
	// unfoturnately we haven't learned that part yet
	thounsands = fourDigitsNumber / 1000;
	fourDigitsNumber -= thounsands * 1000;
	hundreds = fourDigitsNumber / 100;
	fourDigitsNumber -= hundreds * 100;
	dozens = fourDigitsNumber / 10;
	unit = fourDigitsNumber - dozens * 10;

	printf("hang tram %d\n", hundreds);
	printf("hang chuc %d\n", dozens);
	printf("hang don vi %d\n", unit);

	getch();
	return 0;
}
