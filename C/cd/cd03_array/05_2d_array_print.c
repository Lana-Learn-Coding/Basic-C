#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int rows = 3, columns = 3;
	int a[columns][rows];
	int main_diagonal = 0, sub_diagonal = 0;
	int row, col;

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
			int is_boundary = row == 0 ||
			                  col == 0 ||
			                  row == rows - 1 ||
			                  col == columns - 1;
			if (is_boundary) {
				printf("%d\t", a[col][row]);
			} else {
				printf("\t");
			}
		}
		printf("\n");
	}
	printf("\n\n");
	for (col = 0; col < columns; col++) {
		for (row = 0; row < rows; row++) {
			printf("%d\t", a[col][row]);
		}
		printf("\n");
	}
	printf("\n");

	/* calculate diagonal */
	int i;
	for (i = 0; i < rows; i++) {
		int sub_row = rows - i - 1;
		main_diagonal += a[i][i];
		sub_diagonal += a[i][sub_row];
	}
	printf("tong phan tu tren duong cheo chinh la: %d\n", main_diagonal);
	printf("tong phan tu tren duong cheo phu la: %d\n", sub_diagonal);


	getch();
	return 0;
}
