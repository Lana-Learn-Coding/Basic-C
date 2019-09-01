#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	unsigned int num;
	unsigned int biggest = 0;


	printf("nhap 1 so nguyen duong n\n");
	scanf("%u", &num);

	for (int i = 1; i <= num; i++) {
		int is_odd = i % 2 != 0;
		int is_divisor = num % i == 0;

		if (is_divisor && is_odd) {
			if (i > biggest) {
				biggest = i;
			}
		}
	}

	printf("uoc le lon nhat cua %u la %d", num, biggest);

	getch();
	return 0;
}
