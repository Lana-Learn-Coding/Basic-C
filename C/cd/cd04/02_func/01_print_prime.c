#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int size);

void print_prime(int *ptr_arr, int size, int threshold);

int is_prime(int num);

int main(int argc, char const *argv[])
{

	int *p;
	int max = 100;
	int len;
	printf("nhap chieu dai mang: ");
	scanf("%d", &len);
	int a[len];
	p = &a[0];

	input(p, len);
	printf("cac so nguyen to nho hon %d la: ", max);
	print_prime(p, len, max);

	getch();
	return 0;
}

void input(int *ptr_arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("nhap phan tu %d/%d: ", (i + 1), size);
		scanf("%d", ptr_arr);
		ptr_arr++;
	}
	printf("\n");
}

void print_prime(int *ptr_arr, int size, int threshold)
{
	int i;
	for (i = 0; i < size; i++) {
		int num = *ptr_arr;
		if (num < threshold && is_prime(num)) {
			printf("%d ", num);
		}
		ptr_arr++;
	}
	printf("\n");
}

int is_prime(int num)
{
	int i;
	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return num >= 2;
}
