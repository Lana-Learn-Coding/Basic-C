#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int rows, int columns);

void print(int *ptr_arr, int rows, int columns);

int main(int argc, char const *argv[])
{
	int *ptr_arr;
	int rows, columns;
	printf("nhap do dai ma tran: ");
	scanf("%d", &columns);
	printf("nhap do rong ma tran: ");
	scanf("%d", &rows);
	int a[columns][rows];
	ptr_arr = &a[0][0];

	input(ptr_arr, rows, columns);
	print(ptr_arr, rows, columns);

	getch();
	return 0;
}

void input(int *ptr_arr, int rows, int columns)
{
	int size = rows * columns;
	int i;
	for (i = 0; i < size; i++) {
		int row = i / rows;
		int col = i % rows;
		printf("nhap phan tu a[%d][%d]: ", row, col);
		scanf("%d", ptr_arr);
		ptr_arr++;
	}
}

void print(int *ptr_arr, int rows, int columns)
{
	int size = rows * columns;
	int i;
	printf("\ncac phan tu trong ma tran la: \n");
	for (i = 0; i < size; i++) {
		if (i % rows == 0) {
			printf("\n");
		}
		printf("%d\t", *ptr_arr);
		ptr_arr++;
	}
}
