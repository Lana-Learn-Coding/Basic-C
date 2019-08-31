#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	unsigned int num;
	printf("nhap 1 so nguyen duong n\n");
	scanf("%u", &num);

	printf("cac uoc cua %u la\n", num);

	int i;
	int divisor_cnt = 0;
	const int COL_MAX = 5;
	for (int i = 1; i <= num; i++) {
		int is_divisor = num % i == 0;

		if (is_divisor) {
			printf("|%-4d ", i);

			/* split line each COL_MAX printed */
			divisor_cnt++;
			if (divisor_cnt % COL_MAX == 0) {
				printf("\n");
			}
		}
	}

	getch();
	return 0;
}
