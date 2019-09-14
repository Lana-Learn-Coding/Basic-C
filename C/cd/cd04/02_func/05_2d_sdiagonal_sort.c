#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int rows, int columns);

void draw(int *ptr_arr, int rows, int columns);

void sort_sdiagonal_desc(int *ptr_arr, int rows, int columns);

void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
	int *ptr_arr;
	int rows;
	printf("nhap 1 canh ma tran: ");
	scanf("%d", &rows);
	int a[rows][rows];
	ptr_arr = &a[0][0];

	input(ptr_arr, rows, rows);
	sort_sdiagonal_desc(ptr_arr, rows, rows);
	printf("duong cheo phu duoc sap xep tu lon den nho");
	draw(ptr_arr, rows, rows);

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

void draw(int *ptr_arr, int rows, int columns)
{
	int size = rows * columns;
	int i;
	for (i = 0; i < size; i++) {
		if (i % rows == 0) {
			printf("\n");
		}
		printf("%d\t", *ptr_arr);
		ptr_arr++;
	}
	printf("\n\n");
}

void sort_sdiagonal_desc(int *ptr_arr, int rows, int columns)
{
	int is_square = rows == columns;
	if (is_square) {
		int i;
		for (i = 1; i < rows; i++) {
			int pre_i = i - 1;
			int *ptr_num = (i * rows) + (rows - i - 1) + ptr_arr;
			int *ptr_pre_num = (pre_i * rows) + (rows - pre_i - 1) + ptr_arr;
			if (*ptr_num < *ptr_pre_num) {
				swap(ptr_num, ptr_pre_num);
			}
		}
	}
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
