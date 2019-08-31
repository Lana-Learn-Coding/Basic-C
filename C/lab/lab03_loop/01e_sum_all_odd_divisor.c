#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	unsigned int num;
	unsigned int sum_odd_divisor = 0;

	printf("nhap 1 so nguyen duong n\n");
	scanf("%u", &num);

	int i;
	for (int i = 1; i <= num; i++) {
		int is_odd = i % 2 != 0;
		int is_divisor = num % i == 0;

		if (is_divisor && is_odd) {
			sum_odd_divisor += i;
		}
	}

	printf("tong cac uoc le cua %u la %u", num, sum_odd_divisor);

	getch();
	return 0;
}
