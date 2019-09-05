#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int month, day, year;
	int is_leap;

	printf("nhap thang nam theo dinh dang mm/yyyy: ");
	scanf("%d/%d", &month, &year);

	/* check is a leap year */
	if (year % 4 == 0) {
		is_leap = 1;
		if (year % 100 == 0) {
			is_leap = year % 400 == 0;
		}
	}

	switch (month) {
	case 2:
		if (is_leap)
			day = 29;
		else
			day = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = 30;
		break;
	default:
		day = 31;
	}

	printf("thang %d nam %d co %d ngay\n", month, year, day);

	getch();
	return 0;
}
