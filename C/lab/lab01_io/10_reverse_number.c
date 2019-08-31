#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int num_2digits;
	int units_pos, dozens_pos;

	printf("nhap so co 2 chu so can dao nguoc\n");
	scanf("%d", &num_2digits);

	units_pos = num_2digits % 10;
	dozens_pos = num_2digits / 10;

	printf("so da dao nguoc la %d%d", units_pos, dozens_pos);

	getch();
	return 0;
}
