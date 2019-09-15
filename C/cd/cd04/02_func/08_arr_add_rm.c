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

void shift(int *ptr_arr, int size, int pos);

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
		int element;
		switch (opts) {
		case ADD:
			printf("nhap vi tri can them: ");
			scanf("%d", &pos);
			if (len >= len_max) {
				printf("mang da day, chon %d de xoa bot phan tu\n", REMOVE);
			} else if (pos < 0 || pos >= len_max) {
				printf("vi tri khong hop le (0-%d)\n", len_max - 1);
			} else {
				printf("nhap phan tu can them: ");
				scanf("%d", &element);
				if (pos < len) {
					shift(p, len_max, pos);
					*(p + pos) = element;
				} else {
					printf("them phan tu vao cuoi mang\n");
					pos = len;
					*(p + pos) = element;
				}
				len++;
				printf("da them phan tu %d vao vi tri %d\n", element, pos);
				printf("chon %d de in phan tu trong mang\n", PRINT);
			}
			break;
		case REMOVE:
			printf("nhap vi tri can xoa: ");
			scanf("%d", &pos);
			if (len <= 0) {
				printf("mang da rong, chon %d de them phan tu\n", ADD);
			} else if (pos < 0 || pos >= len_max) {
				printf("vi tri khong hop le (0-%d)\n", len_max - 1);
			} else {
				element = *(p + pos);
				if (pos < len) {
					delete(p, len, pos);
					len--;
				}
				printf("da xoa phan tu %d tai vi tri %d\n", element, pos);
				printf("chon %d de in phan tu trong mang\n", PRINT);
			}
			break;
		case REVERT:
			memcpy(a, a_bak, len_max * sizeof(int));
			len = len_max;
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
		printf("nhap phan tu %d/%d: ", i, size);
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
	if (pos < size && pos >= 0) {
		int i = 0;
		for (i = pos; i < size - 1; i++)
		{
			int *ptr_current = ptr_arr + i;
			int *ptr_nxt = ptr_arr + i + 1;
			*ptr_current = *ptr_nxt;
		}
	}
	*(ptr_arr + (size - 1)) = 0;
}

void shift(int *ptr_arr, int size, int pos)
{
	if (pos < size && pos >= 0) {
		int tmp = *(ptr_arr + pos);
		int i = 0;
		for (i = pos + 1; i < size; i++)
		{
			int *ptr_current = ptr_arr + i;
			int current = *ptr_current;
			*ptr_current = tmp;
			tmp = current;
		}
	}
	*(ptr_arr + pos) = 0;
}
