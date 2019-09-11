#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define INPUT 1
#define PRINT 2
#define SUM_ODD 3
#define SUM_EVEN 4
#define SUM_PRIME 5
#define SORT 6
#define PRINT_BIGGEST_SMALLEST 7
#define EXIT 8

void input_array(int arr[], int len);
void print_array(int arr[], int len);
int sum_odd(int arr[], int len);
int sum_even(int arr[], int len);
void print_and_sum_prime(int arr[], int len);
int is_prime(int num);
void sort_sm_bg(int arr[], int len);
void print_bigest_smallest(int arr[], int len);

int main(int argc, char const *argv[])
{
	int opts;
	int is_opts_valid;
	int is_input_valid = 0;
	int len;
	printf("nhap chieu dai mang: ");
	scanf("%d", &len);
	int a[len];

	/* menu */
	while (1) {
		do {
			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. nhap du lieu cho mang\n", INPUT);
			printf("%d. in ra du lieu trong mang\n", PRINT);
			printf("%d. tinh tong cac phan tu la so le\n", SUM_ODD);
			printf("%d. tinh tong cac phan tu la so chan\n", SUM_EVEN);
			printf("%d. in ra va tinh tong cac phan tu la so nguyen to\n", SUM_PRIME);
			printf("%d. sap xep mang theo thu tu tang dan\n", SORT);
			printf("%d. in ra gia tri lon nhat va nho nhat\n", PRINT_BIGGEST_SMALLEST);
			printf("%d. thoat\n", EXIT);
			printf("lua chon cua ban la: ");
			scanf("%d", &opts);
			printf("\n");

			is_opts_valid = opts >= INPUT && opts <= EXIT;
			if (!is_opts_valid) {
				printf("lua chon cua ban (%d) khong hop le!\n", opts);
			}
			/* ask for input */
			is_input_valid = is_input_valid || opts == EXIT || opts == INPUT;
			while (!is_input_valid) {
				printf("ban chua nhap phan tu cho mang!\n");
				input_array(a, len);
				is_input_valid = 1;
			}
		} while (!is_opts_valid);


		switch (opts) {
		case INPUT:
			input_array(a, len);
			printf("-> mang da duoc nhap thanh cong!\n");
			printf("-> chon %d de xem ket qua\n", PRINT);
			break;
		case PRINT:
			print_array(a, len);
			break;
		case SUM_ODD:
			printf("-> tong cac phan tu le la: %d\n", sum_odd(a, len));
			break;
		case SUM_EVEN:
			printf("-> tong cac phan tu chan la: %d\n", sum_even(a, len));
			break;
		case SUM_PRIME:
			print_and_sum_prime(a, len);
			break;
		case SORT:
			sort_sm_bg(a, len);
			printf("-> mang da duoc sap xep tu nho den lon!\n");
			printf("-> chon %d de xem ket qua\n", PRINT);
			break;
		case PRINT_BIGGEST_SMALLEST:
			print_bigest_smallest(a, len);
			break;
		case EXIT:
			exit(0);
		default:
			printf("-> chuong chinh co loi, xin thu lai\n");
		}
		printf("\n");
	}

	getch();
	return 0;
}

void input_array(int arr[], int len)
{
	printf("xin hay nhap phan tu cho mang:\n");
	int i;
	for (i = 0; i < len; i++) {
		printf("nhap phan tu thu %d/%d: ", i + 1, len);
		scanf("%d", &arr[i]);
	}
	printf("\n");
}

void print_array(int arr[], int len)
{
	printf("-> cac phan tu trong mang:\n");
	int i;
	for (i = 0; i < len; i++) {
		printf("a[%d]=%d\n", i, arr[i]);
	}
}

int sum_odd(int arr[], int len)
{
	int sum = 0;
	int i;
	for (i = 0; i < len; i++) {
		if (arr[i] % 2 != 0) {
			sum += arr[i];
		}
	}
	return sum;
}

int sum_even(int arr[], int len)
{
	int sum = 0;
	int i;
	for (i = 0; i < len; i++) {
		if (arr[i] % 2 == 0) {
			sum += arr[i];
		}
	}
	return sum;
}

void print_and_sum_prime(int arr[], int len)
{
	printf("-> cac phan tu la so nguyen to: ");
	int sum = 0;
	int i;
	for (i = 0; i < len; i++) {
		int num = arr[i];
		if (is_prime(num)) {
			sum += num;
			printf("%d ", num);
		}
	}
	printf("\n-> tong cac phan tu nguyen to la: %d\n", sum);
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

/* buble sort */
void sort_sm_bg(int arr[], int len)
{
	int is_sorted;
	do {
		is_sorted = 1;
		int i;
		for (i = 1; i < len; i++) {
			int num = arr[i];
			int smaller = arr[i - 1];
			if (num < smaller) {
				/* swap */
				arr[i - 1] = num;
				arr[i] = smaller;
				is_sorted = 0;
			}
		}
	} while (!is_sorted);
}

void print_bigest_smallest(int arr[], int len)
{
	int biggest, smallest;
	int i;
	for (i = 0; i < len; i++) {
		int num = arr[i];
		if (i == 0) {
			biggest = num;
			smallest = num;
		}
		if (num > biggest) {
			biggest = num;
		}
		if (num < smallest) {
			smallest = num;
		}
	}
	printf("-> gia tri lon nhat la: %d\n", biggest);
	printf("-> gia tri nho nhat la: %d\n", smallest);
}
