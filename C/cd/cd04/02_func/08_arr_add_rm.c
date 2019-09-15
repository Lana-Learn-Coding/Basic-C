#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define ADD 1
#define REMOVE 2
#define PRINT 3
#define REVERT 4
#define EXIT 5

void get_input(int *ptr_arr, int size);

void print_arr(int *ptr_arr, int size);

void delete(int *ptr_arr, int size, int pos);

void arr_cpy(int *dst, int *src, int size);

int main(int argc, char const *argv[])
{

	int *p;
	int len, len_max;
	int opts;
	int is_opts_valid;
	printf("nhap kich thuoc mang: ");
	scanf("%d", &len_max);
	int a[len_max];
	int a_bak[len_max];
	p = &a[0];
	len = len_max;

	get_input(p, len_max);
	memcpy(a_bak, a, len_max * sizeof(int));

	while (1) {
		do {
			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. them phan tu\n", ADD);
			printf("%d. xoa phan tu\n", REMOVE);
			printf("%d. in cac phan tu\n", PRINT);
			printf("%d. quay lai trang thai ban dau\n", REVERT);
			printf("%d. thoat\n", EXIT);
			printf("lua chon cua ban la: ");
			scanf("%d", &opts);
			printf("\n");

			is_opts_valid = opts >= ADD && opts <= EXIT;
			if (!is_opts_valid) {
				printf("lua chon cua ban (%d) khong hop le!\n", opts);
			}
		} while (!is_opts_valid);

		int pos = 0;
		switch (opts) {
		case ADD:
			if (len >= len_max) {
				printf("mang da day, chon %d de xoa bot phan tu\n", REMOVE);
			} else if (pos < 0 || pos >= len_max) {
				printf("vi tri khong hop le (0-%d)\n", len_max);
			} else {

			}
			break;
		case REMOVE:
			if (len <= 0) {
				printf("mang da rong, chon %d de them phan tu\n", ADD);
			} else if (pos < 0 || pos >= len_max) {
				printf("vi tri khong hop le (0-%d)\n", len_max);
			} else {

			}
			break;
		case REVERT:
			memcpy(a, a_bak, len_max * sizeof(int));
			printf("da khoi phuc lai mang ban dau\n");
			printf("chon %d de in phan tu trong mang\n", PRINT);
			break;
		case PRINT:
			printf("cac phan tu trong mang: ");
			print_arr(p, len);
			break;
		case EXIT:
			exit(0);
		default:
			printf("chuong chinh co loi, xin sua lai\n");
		}
		printf("\n");
	}

	getch();
	return 0;
}

void get_input(int *ptr_arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("nhap phan tu %d/%d: ", (i + 1), size);
		scanf("%d", ptr_arr);
		ptr_arr++;
	}
	printf("\n");
}

void print_arr(int *ptr_arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		if (ptr_arr != NULL) {
			printf("%d ", *ptr_arr);
		}
		ptr_arr++;
	}
	printf("\n");
}

void delete(int *ptr_arr, int size, int pos)
{

}

void add(int *ptr_arr, int size, int pos)
{

}
