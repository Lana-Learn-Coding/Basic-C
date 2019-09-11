#include <stdio.h>
#include <conio.h>

void check_even_odd(int number);

int main(int argc, char const *argv[])
{
	int num;
	printf("nhap 1 so nguyen: ");
	scanf("%d", &num);

	check_even_odd(num);

	getch();
	return 0;
}

void check_even_odd(int number) {
	if (number % 2 == 0) {
		printf("so %d la so chan\n", number);
	} else {
		printf("so %d la so le\n", number);
	}
}
