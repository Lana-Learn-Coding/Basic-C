#include <stdio.h>
#include <conio.h>

int print_arr(int arr[], int size);

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

	print_arr(a, size);

	getch();
	return 0;
}

int print_arr(int arr[], int size) {
	printf("cac phan tu trong mang la:\n");
	int i;
	for (i = 0; i < size; i++) {
		printf("a[%d]=%d\n", i, arr[i]);
	}
}
