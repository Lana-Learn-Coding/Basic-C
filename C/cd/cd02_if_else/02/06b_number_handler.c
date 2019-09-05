#include <stdio.h>
#include <conio.h>
#include <math.h>

#define DEMICAL_BASE 10

int main(int argc, char const *argv[])
{
	int num;
	int product, sum;
	int biggest, smallest;
	int len;
	printf("nhap so nguyen: ");
	scanf("%d", &num);

	printf("so dao nguoc: ");
	if (num < 0) {
		num *= -1;
		printf(" -");
	}

	int power;
	for (power = 0; 1; power++) {
		int demical_factor = floor(pow(DEMICAL_BASE, power));
		int mod = num % (10 * demical_factor);
		int demical_val = mod  / demical_factor;
		if (demical_factor > num) {
			len = power;
			break;
		}
		num -= mod;

		/* fist iter */
		if (power == 0) {
			biggest = demical_val;
			smallest = demical_val;
			sum = demical_val;
			product = demical_val;
		} else {
			if (smallest > demical_val) {
				smallest = demical_val;
			}
			if (biggest < demical_val) {
				biggest = demical_val;
			}
			product *= demical_val;
			sum += demical_val;
		}
		printf("%d", demical_val);
	}

	printf("\n");
	printf("so lon nhat: %d\n", biggest);
	printf("so nho nhat: %d\n", smallest);
	printf("tong cac chu so: %d\n", sum);
	printf("tich cac chu so: %d\n", product);
	printf("chieu dai cua so: %d", len);

	getch();
	return 0;
}
