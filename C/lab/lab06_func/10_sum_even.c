#include <stdio.h>
#include <conio.h>

int sum_even(int arr[], int size);

int main(int argc, char const *argv[])
{
	int size;
	printf("nhap kich thuoc mang: ");
	scanf("%d", &size);
	int a[size];

	int i;
	for (i = 0; i < size; i++) {
		printf("nhap phan tu a[%d]: ", i);
		scanf("%d", &a[i]);
	}

	printf("tong cac phan tu chan trong mang la: %d\n", sum_even(a, size));

	getch();
	return 0;
}

int sum_even(int arr[], int size) {
	int sum = 0;
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) {
			sum += arr[i];
		}
	}
	return sum;
}
