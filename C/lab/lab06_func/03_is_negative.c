#include <stdio.h>
#include <conio.h>

void check_negative(int number);

int main(int argc, char const *argv[])
{
	int num;
	printf("nhap 1 so nguyen: ");
	scanf("%d", &num);

	check_negative(num);

	getch();
	return 0;
}

void check_negative(int number) {
	if (number > 0) {
		printf("so %d la so duong\n", number);
	} else if (number < 0) {
		printf("so %d la so am\n", number);
	} else {
		printf("%d is gay\n", number);
	}
}
