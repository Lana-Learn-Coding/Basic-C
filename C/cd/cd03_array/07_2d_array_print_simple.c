#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int is_square;
	int rows, columns;
	int main_diagonal = 0, sub_diagonal = 0;
	int row, col;
	printf("nhap do dai ma tran: ");
	scanf("%d", &columns);
	printf("nhap do rong ma tran: ");
	scanf("%d", &rows);
	int a[columns][rows];
	is_square = columns == rows;

	/* input */
	for (col = 0; col < columns; col++) {
		printf("nhap hang thu %d\n", col + 1);
		for (row = 0; row < rows; row++) {
			printf("nhap phan tu a[%d][%d]: ", col, row);
			scanf("%d", &a[col][row]);
		}
	}

	/* draw */
	printf("\n");
	for (col = 0; col < columns; col++) {
		for (row = 0; row < rows; row++) {
			printf("%d\t", a[col][row]);
		}
		printf("\n");
	}
	printf("\n");

	/* calculate diagonal */
	if (is_square) {
		int i;
		for (i = 0; i < rows; i++) {
			int sub_row = rows - i - 1;
			main_diagonal += a[i][i];
			sub_diagonal += a[i][sub_row];
		}
		printf("tong phan tu tren duong cheo chinh la: %d\n", main_diagonal);
		printf("tong phan tu tren duong cheo phu la: %d\n", sub_diagonal);
	} else {
		printf("day khong phai ma tran vuong.\n");
	}


	getch();
	return 0;
}
