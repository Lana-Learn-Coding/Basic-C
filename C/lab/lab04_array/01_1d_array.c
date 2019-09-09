#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define PRINT 1
#define SUM 2
#define PRINT_CMULTIPLE_3A4 3
#define FIND_BIGGEST 4
#define SORT 5
#define COUNT_NUM_ODD 6
#define EXIT 7

int main(int argc, char const *argv[])
{
	int opts;
	int is_opts_valid;
	int size;
	printf("nhap kich thuoc mang: ");
	scanf("%d", &size);
	int a[size];

	int i;
	for (i = 0; i < size; i++) {
		printf("nhap phan tu a[%d]: ", i);
		scanf("%d", &a[i]);
	}

	while (1) {
		do {
			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. in du lieu vua nhap vao mang\n", PRINT);
			printf("%d. in tong cac phan tu trong mang\n", SUM);
			printf("%d. in cac phan tu chia het cho 3 va 4\n", PRINT_CMULTIPLE_3A4);
			printf("%d. tim phan tu lon nhat\n", FIND_BIGGEST);
			printf("%d. sap xep cac phan tu trong mang\n", SORT);
			printf("%d. in so phan tu chan va le\n", COUNT_NUM_ODD);
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
				printf("a[%d]=%d\n", i, a[i]);
			}
			break;
		}
		case SUM: {
			int sum = 0;
			int i;
			for (i = 0; i < size; i++) {
				sum += a[i];
			}
			printf("tong cac phan tu la: %d", sum);
			break;
		}
		case PRINT_CMULTIPLE_3A4: {
			printf("cac phan tu chia het cho 3 va 4 la:\n");
			int i;
			for (i = 0; i < size; i++) {
				int num = a[i];
				if (num % 3 == 0 &&  num % 4 == 0) {
					printf("%d\t", num);
				}
			}
			break;
		}
		case FIND_BIGGEST: {
			int max;
			int i;
			for (i = 0; i < size; i++) {
				if (i == 0) {
					max = a[i];
				}
				if (max < a[i]) {
					max = a[i];
				}
			}
			printf("phan tu lon nhat trong mang la: %d\n", max);
			break;
		}
		case SORT: {
			/* TODO: implement */
			break;
		}
		case COUNT_NUM_ODD: {
			int odd_cnt = 0, even_cnt = 0;
			int i;
			for (i = 0; i < size; i++) {
				if (i % 2 == 0) {
					even_cnt++;
				} else {
					odd_cnt++;
				}
			}
			printf("so phan tu le: %d\n", odd_cnt);
			printf("so phan tu chan: %d\n", even_cnt);
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
