#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int rows, int columns);

void draw(int *ptr_arr, int rows, int columns);

void sort(int *ptr_arr, int size, int order);

void swap(int *a, int *b);

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
	int i;
	for (i = 0; i < columns; i++) {
		if (i % 2 == 0) {
			sort(ptr_arr + i * rows, rows, 1);
		} else {
			sort(ptr_arr + i * rows, rows, -1);
		}
	}
	draw(ptr_arr, rows, columns);

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
	printf("\ncac phan tu trong ma tran la: \n");
	for (i = 0; i < size; i++) {
		if (i % rows == 0) {
			printf("\n");
		}
		printf("%d\t", *ptr_arr);
		ptr_arr++;
	}
	printf("\n\n");
}

void sort(int *ptr_arr, int size, int order)
{
	int is_sorted;
	do {
		is_sorted = 1;
		int i;
		for (i = 1; i < size; i++) {
			int *ptr_num = ptr_arr + i;
			int *ptr_pre_num = ptr_arr + i - 1;
			if (*ptr_num < *ptr_pre_num) {
				if (order > 0) {
					swap(ptr_num, ptr_pre_num);
					is_sorted = 0;
				}
			} else if (*ptr_num > *ptr_pre_num) {
				if (order < 0) {
					swap(ptr_num, ptr_pre_num);
					is_sorted = 0;
				}
			}
		}
	} while (!is_sorted);
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
