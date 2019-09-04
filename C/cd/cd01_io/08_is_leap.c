#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int year;
	int is_leap = 0;
	printf("nhap nam ");
	scanf("%d", &year);
	printf("\n");

	if (year % 4 == 0) {
		is_leap = 1;
		if (year % 100 == 0) {
			is_leap = year % 400 == 0;
		}
	}
	if (is_leap)
		printf("nam nhuan\n");
	else
		printf("nam khong nhuan\n");

	getch();
	return 0;
}
