#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int cols, int rows);

void print(int *ptr_arr, int cols, int rows);

int main(int argc, char const *argv[])
{
	int *ptr_arr;
	int cols, rows;
	printf("nhap do dai ma tran: ");
	scanf("%d", &rows);
	printf("nhap do rong ma tran: ");
	scanf("%d", &cols);
	int a[rows][cols];
	ptr_arr = &a[0][0];

	input(ptr_arr, cols, rows);
	print(ptr_arr, cols, rows);

	getch();
	return 0;
}

void input(int *ptr_arr, int cols, int rows)
{
	int size = cols * rows;
	int i;
	for (i = 0; i < size; i++) {
		int row = i / cols;
		int col = i % cols;
		printf("nhap phan tu a[%d][%d]: ", row, col);
		scanf("%d", ptr_arr);
		ptr_arr++;
	}
}

void print(int *ptr_arr, int cols, int rows)
{
	int size = cols * rows;
	int i;
	printf("\ncac phan tu trong ma tran la: \n");
	for (i = 0; i < size; i++) {
		if (i % cols == 0) {
			printf("\n");
		}
		printf("%d\t", *ptr_arr);
		ptr_arr++;
	}
}
