#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int rows, int columns);
int is_odd(int num);

int main(int argc, char const *argv[])
{
	int sum_odd = 0;
	int *ptr_arr;
	int rows, columns, size;
	printf("nhap do dai ma tran: ");
	scanf("%d", &columns);
	printf("nhap do rong ma tran: ");
	scanf("%d", &rows);
	int a[columns][rows];
	size = rows * columns;
	ptr_arr = &a[0][0];

	input(ptr_arr, rows, columns);

	int i;
	printf("cac phan tu trong ma tran la: \n");
	for (i = 0; i < size; i++) {
		int num = *ptr_arr;
		if (i % rows == 0) {
			printf("\n");
		}
		printf("%d\t", num);
		if (is_odd(num)) {
			sum_odd += num;
		}
		ptr_arr++;
	}
	printf("\n\n");
	printf("tong cac so le la: %d\n", sum_odd);

	getch();
	return 0;
}

void input(int *ptr_arr, int rows, int columns)
{
	int size = rows * columns;
	int i;
	for (i = 0; i < size; i++) {
		int row = i / rows;
		int col = i % columns;
		printf("nhap phan tu a[%d][%d]: ", row, col);
		scanf("%d", ptr_arr);
		ptr_arr++;
	}
}

int is_odd(int num)
{
	return num % 2 != 0;
}
