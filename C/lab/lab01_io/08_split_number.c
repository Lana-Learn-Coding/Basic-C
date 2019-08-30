#include <stdio.h>
#include <conio.h>


int main(int argc, char const *argv[])
{
	int threeDigitsNumber;
	int unit, dozens, hundreds;

	printf("nhap so nguyen duong can tach\n");
	scanf("%d", &threeDigitsNumber);

	// note: this can be replaced with a loop.
	// unfoturnately we haven't learned that part yet
	hundreds = threeDigitsNumber / 100;
	threeDigitsNumber -= hundreds * 100;
	dozens = threeDigitsNumber / 10;
	unit = threeDigitsNumber - dozens * 10;

	printf("hang tram %d\n", hundreds);
	printf("hang chuc %d\n", dozens);
	printf("hang don vi %d\n", unit);

	getch();
	return 0;
}
