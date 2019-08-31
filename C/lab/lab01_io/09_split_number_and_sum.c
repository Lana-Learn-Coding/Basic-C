#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int num_4digits;
	int units, dozens, hundreds, thounsands;

	printf("nhap so nguyen duong can tach\n");
	scanf("%d", &num_4digits);

	/*
	* note: this can be replaced with a loop.
	* unfoturnately we haven't learned that part yet
	*/
	thounsands = num_4digits / 1000;
	num_4digits -= thounsands * 1000;
	hundreds = num_4digits / 100;
	num_4digits -= hundreds * 100;
	dozens = num_4digits / 10;
	units = num_4digits - dozens * 10;

	printf("hang tram %d\n", hundreds);
	printf("hang chuc %d\n", dozens);
	printf("hang don vi %d\n", units);

	getch();
	return 0;
}
