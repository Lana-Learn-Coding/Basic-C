#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int cols, int rows);

void draw(int *ptr_arr, int cols, int rows);

void print_sum_diagonal(int *ptr_arr, int cols, int rows);

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
	draw(ptr_arr, cols, rows);

	print_sum_diagonal(ptr_arr, cols, rows);

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

void print_sum_diagonal(int *ptr_arr, int cols, int rows)
{
	int is_square = cols == rows;
	int main_diagonal_sum = 0, sub_diagonal_sum = 0;
	if (is_square) {
		int i;
		for (i = 0; i < cols; i++) {
			int main_nxt = i * cols + i;
			int sub_next = (i * cols) + (cols - i - 1);
			main_diagonal_sum += *(ptr_arr + main_nxt);
			sub_diagonal_sum += *(ptr_arr + sub_next);
		}
		printf("tong phan tu tren duong cheo chinh la: %d\n", main_diagonal_sum);
		printf("tong phan tu tren duong cheo phu la: %d\n", sub_diagonal_sum);
	} else {
		printf("khong phai ma tran vuong.\n");
	}
}
