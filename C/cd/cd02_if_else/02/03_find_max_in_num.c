#include <stdio.h>
#include <conio.h>
#include <math.h>

#define DEMICAL_BASE 10

int main(int argc, char const *argv[])
{
	int biggest = 0, smallest = 9;
	int num;
	printf("nhap 1 so nguyen: ");
	scanf("%d", &num);

	if (num < 0) {
		num *= -1;
	}

	int power;
	for (power = 0; 1; power++) {
		int demical_factor = floor(pow(DEMICAL_BASE, power));
		int mod = num % (10 * demical_factor);
		int demical_val = mod  / demical_factor;
		if (demical_factor > num) { break; }
		num -= mod;

		if (smallest > demical_val) {
			smallest = demical_val;
		}
		if (biggest < demical_val) {
			biggest = demical_val;
		}
	}

	printf("so lon nhat: %d\n", biggest);
	printf("so nho nhat: %d\n", smallest);

	getch();
	return 0;
}
