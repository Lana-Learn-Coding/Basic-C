#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	unsigned int a, b, sum;
	printf("nhap 2 so nguyen duong a va b: ");
	scanf("%u %u", &a, &b);

	sum = a + b;
	printf("%u + %u = %u ", a, b , sum);

	if (sum % 2 == 0)
		printf("la so chan\n");
	else
		printf("la so le\n");

	getch();
	return 0;
}
