#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int month, day, year;
	int is_valid = 0;
	while (!is_valid) {
		printf("nhap ngay: ");
		scanf("%d", &day);
		printf("nhap thang: ");
		scanf("%d", &month);
		printf("nhap nam: ");
		scanf("%d", &year);


		is_valid = (31 >= day && day >= 1) &&
		           (12 >= month && month >= 1) &&
		           (year >= 1);

		if (is_valid) {
			int is_leap;
			int day_max;

			/* check is a leap year */
			if (year % 4 == 0) {
				is_leap = 1;
				if (year % 100 == 0) {
					is_leap = year % 400 == 0;
				}
			}

			/* check is the day valid */
			switch (month) {
			case 2:
				if (is_leap)
					day_max = 29;
				else
					day_max = 28;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				day_max = 30;
				break;
			default:
				day_max = 31;
			}

			is_valid = day <= day_max;
		}

		if (is_valid)
			printf("\n-> %d/%d/%d ", day, month, year);
		else
			printf("khong hop le\n");
	}

	getch();
	return 0;
}
