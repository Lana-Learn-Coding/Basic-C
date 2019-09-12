#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int i;
	int *ptr_arr;
	int biggest, smallest;
	int size;
	printf("nhap kich thuoc mang: ");
	scanf("%d", &size);
	int a[size];
	ptr_arr = &a[0];

	for (i = 0; i < size; i++) {
		printf("nhap phan tu a[%d]: ", i);
		scanf("%d", ptr_arr);
		ptr_arr++;
	}
	ptr_arr = &a[0];

	printf("cac phan tu trong mang la:\n");
	for (i = 0; i < size; i++) {
		int num = *ptr_arr;
		printf("a[%d]=%d\n", i, num);
		if (i == 0) {
			biggest = num;
			smallest = num;
		}
		if (biggest < num) { biggest = num; }
		if (smallest > num) { smallest = num; }
		ptr_arr++;
	}
	printf("so lon nhat la: %d\n", biggest);
	printf("so nho nhat la: %d\n", smallest);

	getch();
	return 0;
}
