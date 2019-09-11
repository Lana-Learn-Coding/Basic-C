#include <stdio.h>
#include <conio.h>

void check_perfect(int num);

int main(int argc, char const *argv[])
{
	int num;
	printf("nhap 1 so nguyen: ");
	scanf("%d", &num);

	check_perfect(num);

	getch();
	return 0;
}

void check_perfect(int num) {
	int sum_divisor = 0;
	int i;
	for (i = 1; i < num; i++) {
		if (num % i == 0) {
			sum_divisor += i;
		}
	}
	if (sum_divisor == num)
		printf("%d la so hoan hao\n", num);
	else
		printf("%d khong phai la so hoan hao\n", num );
}
