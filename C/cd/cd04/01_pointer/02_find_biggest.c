#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int biggest;
	int size = 5;
	int a[size];
	int *ptr_arr = &a[0];

	printf("moi nhap phan tu cho mang\n");
	int i;
	for (i = 0; i < size; i++) {
		printf("nhap phan tu a[%d]: ", i);
		scanf("%d", ptr_arr);

		if (i == 0) {
			biggest = *ptr_arr;
		}
		if (*ptr_arr > biggest) {
			biggest = *ptr_arr;
		}
		ptr_arr++;
	}
	printf("phan tu lon nhat la %d\n", biggest);

	getch();
	return 0;
}
