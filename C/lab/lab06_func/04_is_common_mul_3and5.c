#include <stdio.h>
#include <conio.h>

void check_common_multiple_3and5(int number);

int main(int argc, char const *argv[])
{
	int num;
	printf("nhap 1 so nguyen: ");
	scanf("%d", &num);

	check_common_multiple_3and5(num);

	getch();
	return 0;
}

void check_common_multiple_3and5(int number) {
	if (number % 3 == 0 && number % 5 == 0) {
		printf("so %d chia het cho 3 va 5\n", number);
	} else {
		printf("so %d khong chia het cho 3 va 5\n", number);
	}
}
