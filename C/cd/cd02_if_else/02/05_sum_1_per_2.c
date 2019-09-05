#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	unsigned int num;
	double sum = 0;

	printf("nhap 1 so nguyen duong n\n");
	scanf("%u", &num);
	num *= 2;
	double i;
	for (i = 2; i <= num; i++) {
		sum += 1 / (2 * i);
	}

	printf("tong cac so 1/2 1/4 ... 1/2n la %lf\n", sum);

	getch();
	return 0;
}
