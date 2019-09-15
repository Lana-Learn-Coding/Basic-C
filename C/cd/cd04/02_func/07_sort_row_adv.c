#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int cols, int rows);

void draw(int *ptr_arr, int cols, int rows);

void sort(int *ptr_arr, int size, int order);

void swap(int *a, int *b);

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

	int i;
	for (i = 0; i < rows; i++) {
		if (i % 2 == 0) {
			sort(ptr_arr + i * cols, cols, 1);
		} else {
			sort(ptr_arr + i * cols, cols, -1);
		}
	}
	draw(ptr_arr, cols, rows);

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

void draw(int *ptr_arr, int cols, int rows)
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
