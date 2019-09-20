#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int cols = 3, rows = 3;
	int a[rows][cols];
	int main_diagonal = 0, sub_diagonal = 0;
	int row, col;

	/* input */
	for (col = 0; col < rows; col++) {
		printf("nhap hang thu %d\n", col + 1);
		for (row = 0; row < cols; row++) {
			printf("nhap phan tu a[%d][%d]: ", col, row);
			scanf("%d", &a[col][row]);
		}
	}

	/* draw */
	printf("\n");
	for (row = 0; row < rows; row++) {
		for (col = 0; col < cols; col++) {
			int is_boundary = row == 0 ||
			                  col == 0 ||
			                  row == rows - 1 ||
			                  col == cols - 1;
			if (is_boundary) {
				printf("%d\t", a[col][row]);
			} else {
				printf("\t");
			}
		}
		printf("\n");
	}
	printf("\n\n");
	for (col = 0; col < rows; col++) {
		for (row = 0; row < cols; row++) {
			printf("%d\t", a[col][row]);
		}
		printf("\n");
	}
	printf("\n");

	/* calculate diagonal */
	int i;
	for (i = 0; i < cols; i++) {
		int sub_row = cols - i - 1;
		main_diagonal += a[i][i];
		sub_diagonal += a[i][sub_row];
	}
	printf("tong phan tu tren duong cheo chinh la: %d\n", main_diagonal);
	printf("tong phan tu tren duong cheo phu la: %d\n", sub_diagonal);


	getch();
	return 0;
}
