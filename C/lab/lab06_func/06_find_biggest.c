#include <stdio.h>
#include <conio.h>

int biggest(int arr[], int size);

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

	printf("phan tu lon nhat trong mang la: %d\n", biggest(a, size));

	getch();
	return 0;
}

int biggest(int arr[], int size) {
	int max;
	int i;
	for (i = 0; i < size; i++) {
		if (i == 0) {
			max = arr[i];
		}
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}
