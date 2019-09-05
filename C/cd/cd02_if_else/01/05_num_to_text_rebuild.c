#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

#define DEMICAL_BASE 10
#define DEMICAL_PERIOD 1000

int main(int argc, char const *argv[])
{
	int num;
	int is_valid = 0;
	int len = 4;
	int max = pow(DEMICAL_BASE, len);
	while (!is_valid) {
		printf("nhap so nguyen co %d chu so: ", len);
		scanf("%d", &num);

		is_valid = num < max && num >  max * -1;
		if (!is_valid) {
			printf("%d khong hop le\n", num);
		}
	}

	if (num < 0) {
		printf("am ");
		num *= -1;
	}

	int period_factor  = 1000;
	int period_num = num;

	int demical_factor;
	int is_hundreds = 1;
	for (demical_factor = 100; demical_factor >= 1; demical_factor /= DEMICAL_BASE) {
		int demical_val = period_num / demical_factor;
		int is_zero = period_num == 0;

		switch (demical_val) {
		case 0:
			if (demical_factor == 1 && !is_zero) { /* units specified */
				printf("muoi ");
			} else if (demical_factor == 10 && !is_zero) { /* dozens specified */
				printf("le ");
			} else if (demical_factor == 100 && !is_zero) { /* hundreds specified */
				printf("khong ");
			}
			break;
		case 1:
			if (demical_factor == 10) { /* dozens specified */
				printf("muoi ");
			} else {
				printf("mot ");
			}
			break;
		case 2:
			printf("hai ");
			break;
		case 3:
			printf("ba ");
			break;
		case 4:
			printf("bon ");
			break;
		case 5:
			printf("nam ");
			break;
		case 6:
			printf("sau ");
			break;
		case 7:
			printf("bay ");
			break;
		case 8:
			printf("tam ");
			break;
		case 9:
			printf("chin ");
			break;
		}
		/*
		* specified for units
		* should not print if dozens <= 1 (number left < 20)
		*/
		if (demical_factor == 10 && period_num >= 20) { printf("muoi "); }
		if (demical_factor == 100 && !is_zero) { printf("tram "); }
		period_num = period_num % demical_factor;
	}

	getch();
	return 0;
}
