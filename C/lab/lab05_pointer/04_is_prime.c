#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define ARR_1D 1
#define ARR_2D 2
#define EXIT 3

void input(int *ptr_arr, int size);

void input_2d(int *ptr_arr, int rows, int columns);

void print(int *ptr_arr, int rows, int columns);

void print_prime(int *ptr_arr, int size);

int is_prime(int num);

int main(int argc, char const *argv[])
{
	while (1) {
		int opts;
		int is_opts_valid;
		do {
			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. mang 1 chieu\n", ARR_1D);
			printf("%d. mang 2 chieu\n", ARR_2D);
			printf("%d. thoat\n", EXIT);
			printf("lua chon cua ban la: ");
			scanf("%d", &opts);
			printf("\n");

			is_opts_valid = opts >= 1 && opts <= EXIT;
		} while (!is_opts_valid);

		switch (opts) {
		case ARR_1D: {
			int *ptr_arr;
			int biggest, smallest;
			int size;
			printf("nhap kich thuoc mang: ");
			scanf("%d", &size);
			int a[size];
			ptr_arr = &a[0];

			input(ptr_arr, size);
			print(ptr_arr, 1, size);
			print_prime(ptr_arr, size);
			break;
		}
		case ARR_2D: {
			int *ptr_arr;
			int rows, columns;
			printf("nhap do dai mang: ");
			scanf("%d", &columns);
			printf("nhap do rong mang: ");
			scanf("%d", &rows);
			int a[columns][rows];
			ptr_arr = &a[0][0];

			input_2d(ptr_arr, rows, columns);
			print(ptr_arr, rows, columns);
			print_prime(ptr_arr, rows * columns);
			break;
		}
		case EXIT:
			exit(0);
		default:
			printf("chuong chinh co loi, xin sua lai\n");
		}
		printf("\n\n");
	}
	getch();
	return 0;
}

void input_2d(int *ptr_arr, int rows, int columns)
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

void input(int *ptr_arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("nhap phan tu a[%d]: ", i);
		scanf("%d", ptr_arr);
		ptr_arr++;
	}

}

void print(int *ptr_arr, int rows, int columns)
{
	int size = rows * columns;
	int i;
	printf("\ncac phan tu trong mang la: \n");
	for (i = 0; i < size; i++) {
		if (i % rows == 0) {
			printf("\n");
		}
		printf("%d\t", *ptr_arr);
		ptr_arr++;
	}
	printf("\n\n");
}

void print_prime(int *ptr_arr, int size) {
	printf("cac so nguyen to: ");
	int i;
	for (i = 0; i < size; i++) {
		if (is_prime(*ptr_arr)) {
			printf("%d ", *ptr_arr);
		}
		ptr_arr++;
	}
	printf("\n");
}

int is_prime(int num)
{
	int i;
	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return num >= 2;
}
