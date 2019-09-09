#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define PRINT 1
#define SUM_DIAGONAL 2
#define PRINT_BOUNDARY 3
#define EXIT 4

int main(int argc, char const *argv[])
{
	int opts;
	int is_opts_valid;
	int rows, columns;
	int is_square;
	printf("nhap do dai ma tran: ");
	scanf("%d", &columns);
	printf("nhap do rong ma tran: ");
	scanf("%d", &rows);
	int a[columns][rows];
	is_square = rows == columns;

	int row, col;
	for (col = 0; col < columns; col++) {
		printf("nhap hang thu %d\n", col + 1);
		for (row = 0; row < rows; row++) {
			printf("nhap phan tu a[%d][%d]: ", col, row);
			scanf("%d", &a[col][row]);
		}
	}

	while (1) {
		do {
			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. in du lieu vua nhap vao ma tran\n", PRINT);
			if (is_square) {
				printf("%d. in tong cac duong cheo cua ma tran vuong\n", SUM_DIAGONAL);
			} else {
				printf("%d. khong kha dung (chi dang cho ma tran vuong)\n", SUM_DIAGONAL);
			}
			printf("%d. in cac phan tu o bien ma tran\n", PRINT_BOUNDARY);
			printf("%d. thoat\n", EXIT);
			printf("lua chon cua ban la: ");
			scanf("%d", &opts);
			printf("\n");

			is_opts_valid = opts > 0 && opts <= EXIT && (is_square || opts == SUM_DIAGONAL);
			if (!is_opts_valid) {
				printf("lua chon khong hop le, thu lai!\n\n");
			}
		} while (!is_opts_valid);

		switch (opts) {
		case PRINT: {
			printf("cac phan tu trong ma tran la: \n");
			int row, col;
			for (col = 0; col < columns; col++) {
				for (row = 0; row < rows; row++) {
					printf("%d\t", a[col][row]);
				}
				printf("\n");
			}
			break;
		}
		case SUM_DIAGONAL: {
			int main_diagonal, sub_diagonal;
			int i;
			for (i = 0; i < rows; i++) {
				int sub_row = rows - i - 1;
				main_diagonal += a[i][i];
				sub_diagonal += a[i][sub_row];
			}
			printf("tong phan tu tren duong cheo chinh la: %d\n", main_diagonal);
			printf("tong phan tu tren duong cheo phu la: %d\n", sub_diagonal);
			break;
		}
		case PRINT_BOUNDARY: {
			printf("cac phan tu o bien ma tran la: \n");
			int row, col;
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
			break;
		}
		case EXIT:
			exit(0);
		default:
			printf("chuong trinh gap loi. xin thu lai.\n");
		}
		printf("\n");
	}

	getch();
	return 0;
}
