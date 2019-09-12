#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int rows, int columns);
void print(int *ptr_arr, int rows, int columns);
int sum_boundary(int *ptr_arr, int rows, int columns);

int main(int argc, char const *argv[])
{
	int *ptr_arr;
	int is_square;
	int main_diagonal_sum = 0, sub_diagonal_sum = 0;
	int rows, columns;
	printf("nhap do dai ma tran: ");
	scanf("%d", &columns);
	printf("nhap do rong ma tran: ");
	scanf("%d", &rows);
	int a[columns][rows];
	ptr_arr = &a[0][0];
	is_square = rows == columns;

	input(ptr_arr, rows, columns);
	print(ptr_arr, rows, columns);

	if (is_square) {
		int i;
		int *sub_ptr_arr = &a[0][rows - 1];
		for (i = 0; i < rows; i++) {
			main_diagonal_sum += *ptr_arr;
			sub_diagonal_sum += *sub_ptr_arr;
			ptr_arr += rows;
			sub_ptr_arr += rows - i - 1;
		}
		printf("tong phan tu tren duong cheo chinh la: %d\n", main_diagonal_sum);
		printf("tong phan tu tren duong cheo phu la: %d\n", sub_diagonal_sum);
	} else {
		printf("khong phai ma tran vuong.\n");
	}
	ptr_arr = &a[0][0];

	printf("tong cac phan tu o ria ma tran la:  %d\n", sum_boundary(ptr_arr, rows, columns));

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
	printf("\n\n");
}

int sum_boundary(int *ptr_arr, int rows, int columns)
{
	int size = rows * columns;
	int sum_boundary = 0;
	int i;
	for (i = 0; i < size; i++) {
		int row = i / rows;
		int col = i % columns;
		int is_boundary = row == 0 ||
		                  col == 0 ||
		                  row == rows - 1 ||
		                  col == columns - 1;
		if (is_boundary) {
			sum_boundary += *ptr_arr;
		}
		ptr_arr++;
	}
	return sum_boundary;
}
