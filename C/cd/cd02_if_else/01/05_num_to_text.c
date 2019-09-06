#include <stdio.h>
#include <conio.h>
#include <math.h>

#define DEMICAL_BASE 10
#define DEMICAL_PERIOD 1000

int main(int argc, char const *argv[])
{
	int num;
	int period_size;
	int len;
	int i;
	printf("nhap so nguyen: ");
	scanf("%d", &num);

	/* find len */
	int temp = 1;
	for (len = 1; temp <= num; len++) {
		temp *= DEMICAL_BASE;
	}
	len--;
	printf("so co %d chu so.\n\n", len);

	/* round up len */
	for (i = 1; 1; i++) {
		if (len <= i * 3) {
			len = i * 3;
			break;
		}
	}

	for (i = 0; len > 0; i++) {
		int period_len = (len / 3) - 1;
		int period_factor = floor(pow(DEMICAL_PERIOD, period_len));
		int period_num = num / period_factor;
		int is_hundreds = 1;
		/* first iter */
		if ( i == 0 && period_num <= 100) {
			is_hundreds = 0;
		}

		int demical_factor;
		for (demical_factor = 100; demical_factor >= 1; demical_factor /= DEMICAL_BASE) {
			int demical_val = period_num / demical_factor;
			int is_zero = period_num == 0;

			switch (demical_val) {
			case 0:
				if (demical_factor == 1 && !is_zero) { /* units specified */
					printf("muoi ");
				} else if (demical_factor == 10 && !is_zero && is_hundreds) { /* dozens specified */
					printf("le ");
				} else if (demical_factor == 100 && !is_zero && is_hundreds) { /* hundreds specified */
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
			if (demical_factor == 100 && !is_zero && is_hundreds) { printf("tram "); }
			period_num = period_num % demical_factor;
		}

		switch (len) {
		case 3:
			break;
		case 6:
			printf("nghin ");
			break;
		case 9:
			printf("trieu ");
			break;
		case 12:
			printf("ty ");
		}

		len -= 3;
		num = num % period_factor;
	}

	getch();
	return 0;
}
