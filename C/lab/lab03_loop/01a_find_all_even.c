#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	unsigned int num;
	printf("nhap 1 so nguyen duong n\n");
	scanf("%u", &num);

	printf("cac so nguyen duong nho hon %u va chia het cho 2 la \n", num);

	int i;
	int even_cnt = 0, COL_MAX = 10;
	for (int i = 2; i <= num; i++) {
		int is_even = i % 2 == 0;

		if (is_even) {
			printf("%4d ", i);

			/* split line each COL_MAX printed */
			even_cnt++;
			if (even_cnt % COL_MAX == 0) {
				printf("\n");
			}
		}
	}

	getch();
	return 0;
}
