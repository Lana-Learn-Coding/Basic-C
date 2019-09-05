#include <stdio.h>
#include <conio.h>
#include <math.h>

#define DEMICAL_BASE 10

int main(int argc, char const *argv[])
{
	int num;
	int dproduct = 1, dsum = 0, even_dsum = 0, odd_dsum = 0;
	int odd_dmax = 0, even_dmax = 0;
	int cnt = 0;
	printf("nhap so nguyen duong: ");
	scanf("%d", &num);

	int i;
	for (i = 1; i <= num; i++) {
		int divisor = i;
		int is_odd = divisor % 2 != 0;
		if ( num % i != 0) { continue; }

		if (is_odd) {
			odd_dsum += divisor;
			if (odd_dmax < divisor) { odd_dmax = divisor; }
		} else {
			even_dsum += divisor;
			if (even_dmax < divisor) { even_dmax = divisor; }
		}
		dproduct *= divisor;
		dsum += divisor;
		cnt++;
	}

	printf("so uoc: %d\n", cnt);
	printf("tong cac uoc: %d\n", dsum);
	printf("tich cac uoc: %d\n", dproduct);
	printf("tong cac uoc le: %d\n", odd_dsum);
	printf("tong cac uoc chan: %d\n", even_dsum);
	printf("uoc le lon nhat: %d\n", odd_dmax);
	printf("uoc chan lon nhat: %d\n", even_dmax);


	printf("cac uoc cua uoc le lon nhat: ");
	for (i = 1; i <= odd_dmax; i++) {
		if (odd_dmax % i == 0) {
			printf("%d ", i);
		}
	}

	printf("\n");
	printf("cac uoc cua uoc chan lon nhat: ");
	for (i = 1; i <= even_dmax; i++) {
		if (even_dmax % i == 0) {
			printf("%d ", i);
		}
	}

	getch();
	return 0;
}
