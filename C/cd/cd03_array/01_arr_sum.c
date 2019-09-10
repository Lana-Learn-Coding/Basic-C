#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int len = 5;
	int a[len];
	int odd_sum = 0 , even_sum = 0;
	int i;

	for (i = 0; i < len; i++) {
		printf("nhap phan tu %d/%d: ", (i + 1), len);
		scanf("%d", &a[i]);
	}

	printf("\ncac phan tu chan la: ");
	for (i = 0; i < len; i++) {
		int num = a[i];
		if (num % 2 == 0) {
			even_sum += num;
			printf("%d", num);
		}
	}
	printf("\ntong cac phan tu chan la: %d", even_sum);
	printf("\ncac phan tu le la: ");
	for (i = 0; i < len; i++) {
		int num = a[i];
		if (num % 2 != 0) {
			odd_sum += num;
			printf("%d", num);
		}
	}
	printf("\ntong cac phan tu chan la: %d", odd_sum);

	getch();
	return 0;
}
