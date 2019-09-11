#include <stdio.h>
#include <conio.h>

float average(int arr[], int size);

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

	printf("trung binh cong cac phan tu trong mang la: %.2f\n", average(a, size));

	getch();
	return 0;
}

float average(int arr[], int size) {
	int sum = 0;
	int i;
	for (i = 0; i < size; i++) {
		sum += arr[i];
	}
	return (float) sum / size;
}
