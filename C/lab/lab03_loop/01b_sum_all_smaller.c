#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	unsigned int num;
	unsigned int sum = 0;

	printf("nhap 1 so nguyen duong n\n");
	scanf("%u", &num);

	for (int i = 1; i < num; i++) {
		sum += i;
	}

	printf("tong cac so nho hon %u la %u\n", num, sum);

	getch();
	return 0;
}
