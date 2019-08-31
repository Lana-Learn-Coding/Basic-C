#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	unsigned int num;
	unsigned int sum_divisor = 0;

	printf("nhap 1 so nguyen duong n\n");
	scanf("%u", &num);

	int i;
	for (int i = 1; i < num; i++) {
		int is_divisor = num % i == 0;

		if (is_divisor) {
			sum_divisor += i;
		}
	}

	printf("tong cac uoc cua %u la %u", num, sum_divisor);

	getch();
	return 0;
}
