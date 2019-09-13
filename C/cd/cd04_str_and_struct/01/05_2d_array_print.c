#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int rows, int columns);

void draw(int *ptr_arr, int rows, int columns, int is_fill);

void print_sum_diagonal(int *ptr_arr, int rows, int columns);

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
	draw(ptr_arr, rows, columns, 0);
	printf("\n");
	draw(ptr_arr, rows, columns, 1);

	print_sum_diagonal(ptr_arr, rows, columns);

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

void draw(int *ptr_arr, int rows, int columns, int is_fill)
{
	int size = rows * columns;
	int i;
	for (i = 0; i < size; i++) {
		int row = i / columns;
		int col = i % columns;
		int is_boundary = row == 0 ||
		                  col == 0 ||
		                  row == rows - 1 ||
		                  col == columns - 1;
		if (i % rows == 0) {
			printf("\n");
		}
		if (is_fill || is_boundary) {
			printf("%d\t", *ptr_arr);
		} else {
			printf("\t");
		}
		ptr_arr++;
	}
	printf("\n\n");
}

void print_sum_diagonal(int *ptr_arr, int rows, int columns)
{
	int is_square = rows == columns;
	int main_diagonal_sum = 0, sub_diagonal_sum = 0;
	if (is_square) {
		int i;
		for (i = 0; i < rows; i++) {
			int main_nxt = i * rows + i;
			int sub_next = (i * rows) + (rows - i - 1);
			main_diagonal_sum += *(ptr_arr + main_nxt);
			sub_diagonal_sum += *(ptr_arr + sub_next);
		}
		printf("tong phan tu tren duong cheo chinh la: %d\n", main_diagonal_sum);
		printf("tong phan tu tren duong cheo phu la: %d\n", sub_diagonal_sum);
	} else {
		printf("khong phai ma tran vuong.\n");
	}
}
