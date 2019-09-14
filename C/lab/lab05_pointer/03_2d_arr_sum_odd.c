#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int cols, int rows);

int is_odd(int num);

int main(int argc, char const *argv[])
{
	int sum_odd = 0;
	int *ptr_arr;
	int cols, rows, size;
	printf("nhap do dai ma tran: ");
	scanf("%d", &rows);
	printf("nhap do rong ma tran: ");
	scanf("%d", &cols);
	int a[rows][cols];
	size = cols * rows;
	ptr_arr = &a[0][0];

	input(ptr_arr, cols, rows);

	int i;
	printf("cac phan tu trong ma tran la: \n");
	for (i = 0; i < size; i++) {
		int num = *ptr_arr;
		if (i % cols == 0) {
			printf("\n");
		}
		printf("%d\t", num);
		if (is_odd(num)) {
			sum_odd += num;
		}
		ptr_arr++;
	}
	printf("\n\n");
	printf("tong cac so le la: %d\n", sum_odd);

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

int is_odd(int num)
{
	return num % 2 != 0;
}
