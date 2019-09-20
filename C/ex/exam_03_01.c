#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT 1
#define PRINT 2
#define BOUNDARY 3
#define DIAGONAL 4
#define SORT 5
#define EXIT 6

void input(int *ptr_arr, int rows, int cols);
void draw(int *ptr_arr, int rows, int cols);
void draw_and_sum_boundary(int *ptr_arr, int rows, int cols);
void print_sum_diagonal(int *ptr_arr, int cols, int rows);
void sort(int *ptr_arr, int size, int order);
void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
	int *ptr_arr;
	int is_input_valid = 0;
	int cols, rows;
	printf("nhap do dai ma tran: ");
	scanf("%d", &rows);
	printf("nhap do rong ma tran: ");
	scanf("%d", &cols);
	int a[rows][cols];
	ptr_arr = &a[0][0];

	while (1) {
		/* menu */
		int opts;
		int is_opts_valid;
		do {
			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. nhap du lieu cho ma tran\n", INPUT);
			printf("%d. in ra du lieu trong ma tran\n", PRINT);
			printf("%d. in va tinh tong duong bien ma tran\n", BOUNDARY);
			printf("%d. in va tinh tong duong cheo phu ma tran\n", DIAGONAL);
			printf("%d. sap xep cac hang trong ma tran\n", SORT);
			printf("%d. thoat\n", EXIT);
			printf("lua chon cua ban la: ");
			scanf("%d", &opts);
			fflush(stdin);
			is_opts_valid = opts >= INPUT && opts <= EXIT;
			if (!is_opts_valid) {
				printf("lua chon cua ban (%d) khong hop le!\n", opts);
			}
			/* ask for input */
			is_input_valid = is_input_valid || opts == EXIT || opts == INPUT;
			while (!is_input_valid) {
				printf("ban chua nhap phan tu cho ma tran!\n");
				input(ptr_arr, rows, cols);
				is_input_valid = 1;
			}
		} while (!is_opts_valid);

		switch (opts) {
		case INPUT:
			input(ptr_arr, rows, cols);
			break;
		case PRINT:
			draw(ptr_arr, rows, cols);
			break;
		case BOUNDARY:
			draw_and_sum_boundary(ptr_arr, rows, cols);
			break;
		case SORT: {
			int i;
			for (i = 0; i < rows; ++i) {
				sort(a[i], cols, -1);
			}
			printf("da sap xep mang\n");
			break;
		}
		case DIAGONAL:
			print_sum_diagonal(ptr_arr, rows, cols);
			break;
		case EXIT:
			exit(0);
		default:
			printf("-> chuong chinh co loi, xin thu lai\n");
		}
		printf("\n");
	}
	return 0;
}

void input(int *ptr_arr, int rows, int cols)
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

void draw(int *ptr_arr, int rows, int cols)
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

void print_sum_diagonal(int *ptr_arr, int cols, int rows)
{
	int is_square = cols == rows;
	int sub_diagonal_sum = 0;
	if (is_square) {
		printf("phan tu tren duong cheo phu la: ");
		int i;
		for (i = 0; i < cols; i++) {
			int sub_next = (i * cols) + (cols - i - 1);
			sub_diagonal_sum += *(ptr_arr + sub_next);
			printf("%d ", *(ptr_arr + sub_next));
		}
		printf("\n");
		printf("tong phan tu tren duong cheo phu la: %d\n", sub_diagonal_sum);
	} else {
		printf("khong phai ma tran vuong.\n");
	}
}

void draw_and_sum_boundary(int *ptr_arr, int rows, int cols)
{
	int sum = 0;
	int col, row;
	for (row = 0; row < rows; ++row) {
		printf("\n");
		for (col = 0; col < cols; ++col) {
			int is_boundary = row == 0 ||
			                  col == 0 ||
			                  row == rows - 1 ||
			                  col == cols - 1;
			if (is_boundary) {
				int num = *(ptr_arr + row * cols + col);
				printf("%d\t", num);
				sum += num;
			} else {
				printf("\t");
			}
		}
	}
	printf("\n\n");
	printf("\ntong duong bien: %d\n", sum);
	printf("\n");
}

/*
* sort array
* if order > 0 => ascending
* if order < 0 => descending
* if order = 0 no sort.
*/
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
