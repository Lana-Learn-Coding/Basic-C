#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int num_3digits;
	int units, dozens, hundreds;

	printf("nhap so nguyen duong can tach\n");
	scanf("%d", &num_3digits);

	/*
	* note: this can be replaced with a loop.
	* unfoturnately we haven't learned that part yet
	*/
	hundreds = num_3digits / 100;
	num_3digits -= hundreds * 100;
	dozens = num_3digits / 10;
	units = num_3digits - dozens * 10;

	printf("hang tram %d\n", hundreds);
	printf("hang chuc %d\n", dozens);
	printf("hang don vi %d\n", units);

	getch();
	return 0;
}
