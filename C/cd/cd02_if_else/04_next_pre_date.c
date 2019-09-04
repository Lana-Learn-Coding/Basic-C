#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int month, day, year;
	int is_leap;
	int day_max;
	int is_valid = 0;
	/*
	* This variable store the previous month max day.
	* Because we havent learned function yet, so we must hard-coded
	* all the case, which make the source code bloated and hard to
	* maintain.
	*
	* See swicth (month) { ... } below.
	*/
	int pre_day_max;

	/*
	* Valid the date.
	* This block also check if is_leap_year
	* and the maximum day of that month, which
	* can be used to cover special case later
	*/
	while (!is_valid) {
		printf("nhap ngay thang nam theo dinh dang dd/mm/yyyy: ");
		scanf("%d/%d/%d", &day, &month, &year);

		is_valid = (31 >= day && day >= 1) &&
		           (12 >= month && month >= 1) &&
		           (year >= 1);

		if (is_valid) {
			/* check is a leap year */
			if (year % 4 == 0) {
				is_leap = 1;
				if (year % 100 == 0) {
					is_leap = year % 400 == 0;
				}
			}

			/*
			* check is the day valid
			* also calculate the max day of this month
			* and max day of previous month.
			*/
			switch (month) {
			case 2:
				if (is_leap) {
					day_max = 29;
				} else {
					day_max = 28;
				}
				pre_day_max = 31;
				break;
			case 3:
				if (is_leap) {
					pre_day_max = 29;
				} else {
					pre_day_max = 28;
				}
				day_max = 31;
				break;
			case 1:
			case 8:
				day_max = 31;
				pre_day_max = 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				day_max = 30;
				pre_day_max = 31;
				break;
			default: /* 5 7 10 12 */
				day_max = 31;
				pre_day_max = 30;
			}

			is_valid = day <= day_max;
		}
		if (!is_valid) {
			printf("ngay %d/%d/%d khong hop le!\n", day, month, year);
			printf("\n");
		} else {
			printf("\nngay vua nhap %d/%d/%d\n", day, month, year);
		}
	}

	/* next day */
	int next_day = day + 1;
	int next_month = month;
	int next_year = year;

	if (next_day > day_max) {
		next_day = 1;
		next_month++;
	}
	if (next_month > 12) {
		next_month = 1;
		next_year++;
	}
	printf("ngay tiep theo %d/%d/%d\n", next_day, next_month, next_year);

	/* previous day */
	int pre_day = day - 1;
	int pre_month = month;
	int pre_year = year;

	if (pre_day < 1) {
		pre_day = pre_day_max;
		pre_month--;
	}
	if (pre_month < 1) {
		pre_month = 12;
		pre_year--;
	}
	printf("ngay truoc do %d/%d/%d\n", pre_day, pre_month, pre_year);

	getch();
	return 0;
}
