#include <stdio.h>
#include <stdlib.h>

#define INPUT 1
#define PRINT 2
#define PRINT_PRIME 3
#define SORT 4
#define EXIT 5

void input_array(int **p_arr, int *size);
void print_array(int *p_arr, int size);

void print_prime(int *p_arr, int size);
int is_prime(int num);

void sort(int *p_arr, int size);
void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
	int is_input_valid = 0;
	int len;
	int *pa;

	while (1) {
		/* menu */
		int opts;
		int is_opts_valid;
		do {
			printf("==================== CHUONG TRINH =====================\n");
			printf("%d. Nhap so phan tu cho mang va gia tri cac phan tu\n", INPUT);
			printf("%d. In mang vua nhap\n", PRINT);
			printf("%d. Hien thi danh sach cac so nguyen to\n", PRINT_PRIME);
			printf("%d. Sap xep mang tang dan\n", SORT);
			printf("%d. thoat\n", EXIT);
			printf("Lua chon cua ban la: ");
			scanf("%d", &opts);
			fflush(stdin);
			is_opts_valid = opts >= INPUT && opts <= EXIT;
			if (!is_opts_valid) {
				printf("Lua chon cua ban (%d) khong hop le!\n", opts);
			}
			/* ask for input */
			is_input_valid = is_input_valid || opts == EXIT || opts == INPUT;
			while (!is_input_valid) {
				printf("Ban chua nhap phan tu cho mang!\n");
				input_array(&pa, &len);
				is_input_valid = 1;
			}
		} while (!is_opts_valid);
		switch (opts) {
		case INPUT:
			input_array(&pa, &len);
			break;
		case PRINT:
			printf("Mang vua nhap la:\n");
			print_array(pa, len);
			break;
		case PRINT_PRIME:
			print_prime(pa, len);
			break;
		case SORT:
			printf("Mang truoc khi sap xep.\n");
			print_array(pa, len);

			sort(pa, len);
			printf("Mang sau khi sap xep.\n");
			print_array(pa, len);
			break;
		case EXIT:
			printf("Thoat\n");
			exit(0);
		default:
			printf("Chuong chinh co loi, xin thu lai :<\n");
		}
		printf("\n");
	}
	return 0;
}

void input_array(int **p_arr, int *size)
{
	int i;
	printf("Nhap so phan tu mang va gia tri cac phan tu\n");
	printf("n = ");
	scanf("%d", size);
	/* dynamic array allocation */
	int *p = (int *) malloc(*size * sizeof(int));
	for (i = 0; i < *size; i++) {
		printf("nhap a[%d] = ", i);
		scanf("%d", (p + i));
	}
	/* free exist mem allocation for previous array. */
	if (p_arr != NULL) {
		free(p_arr);
	}
	*p_arr = p;
	printf("\n");
}

void print_array(int *p_arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("%5d ", *(p_arr + i));
	}
	printf("\n");
}

void print_prime(int *p_arr, int size)
{
	printf("Cac so nguyen to trong mang la:\n");
	int is_contain_prime = 0;
	int i;
	for (i = 0; i < size; i++) {
		int num = *(p_arr + i);
		if (is_prime(num)) {
			printf("%d ", num);
			is_contain_prime = 1;
		}
	}
	if (!is_contain_prime) {
		printf("Mang khong co so nguyen to\n");
	}
}

int is_prime(int num)
{
	int i;
	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return num >= 2;
}


void sort(int *p_arr, int size)
{
	int is_sorted;
	do {
		is_sorted = 1;
		int i;
		for (i = 1; i < size; i++) {
			int *p_num = p_arr + i;
			int *p_pre_num = p_arr + i - 1;
			if (*p_pre_num > *p_num) {
				swap(p_num, p_pre_num);
				is_sorted = 0;
			}
		}
	} while (!is_sorted);
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
