#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int num;
	int is_prime = 1;	/* in C 1 is equal to true and 0 is false */

	printf("nhap 1 so nguyen n\n");
	scanf("%d", &num);

	int i;
	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			is_prime = 0;
			break;
		}
	}

	if (num < 2) {
		is_prime = 0;
	}

	if (is_prime) {
		printf("day la so nguyen to\n");
	} else {
		printf("day khong phai so nguyen to\n");
	}

	getch();
	return 0;
}
