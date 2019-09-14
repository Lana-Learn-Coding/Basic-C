#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define PRINT 1
#define SORT_BIG_FIRST 2
#define SORT_SMALL_FIRST 3
#define EXIT 4

int main(int argc, char const *argv[])
{
	int opts;
	int is_opts_valid;
	int size;
	int *p;
	printf("nhap kich thuoc mang: ");
	scanf("%d", &size);
	int a[size];
	p = &a[0];

	int i;
	for (i = 0; i < size; i++) {
		printf("nhap phan tu a[%d]: ", i);
		scanf("%d", (p + i));
	}

	while (1) {
		do {
			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. in du lieu trong mang\n", PRINT);
			printf("%d. sap xep tu lon den nho\n", SORT_BIG_FIRST);
			printf("%d. sap xep tu nho den lon\n", SORT_SMALL_FIRST);
			printf("%d. thoat\n", EXIT);
			printf("lua chon cua ban la: ");
			scanf("%d", &opts);
			printf("\n");
			is_opts_valid = opts > 0 && opts <= EXIT;
			if (!is_opts_valid) {
				printf("lua chon khong hop le, thu lai!\n\n");
			}
		} while (!is_opts_valid);

		switch (opts) {
		case PRINT: {
			printf("cac phan tu trong mang la:\n");
			int i;
			for (i = 0; i < size; i++) {
				printf("a[%d]=%d\n", i, *(p + i));
			}
			break;
		}
		case SORT_SMALL_FIRST: {
			/*
			* buble sort :(
			* from smallest to biggest
			*/
			int is_sorted;
			do {
				is_sorted = 1;
				int i;
				for (i = 1; i < size; i++) {
					int num = *(p + i);
					int smaller = *(p + i - 1);
					if (num < smaller) {
						/* swap */
						*(p + i - 1) = num;
						*(p + i) = smaller;
						is_sorted = 0;
					}
				}
			} while (!is_sorted);
			printf("cac phan tu da duoc sap xep tu nho den lon!\n");
			printf("chon %d de xem ket qua\n", PRINT);
			break;
		}
		case SORT_BIG_FIRST: {
			/*
			* buble sort :(
			* from biggest to smallest
			*/
			int is_sorted;
			do {
				is_sorted = 1;
				int i;
				for (i = 1; i < size; i++) {
					int num = *(p + i);
					int bigger = *(p + i - 1);
					if (num > bigger) {
						/* swap */
						*(p + i - 1) = num;
						*(p + i) = bigger;
						is_sorted = 0;
					}
				}
			} while (!is_sorted);
			printf("cac phan tu da duoc sap xep tu lon den nho!\n");
			printf("chon %d de xem ket qua\n", PRINT);
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
