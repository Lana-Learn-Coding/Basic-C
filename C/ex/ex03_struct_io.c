#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT 1
#define PRINT 2
#define SORT 3
#define WRITE 4
#define EXIT 5

typedef struct product {
	char code[11];
	char name[31];
	float price;
} product;

void input(product *ptr_arr, int size);
void print(product *ptr_arr, int size);
product get_product();
void get_string();

void write(const char *filename, product *ptr_arr, int size);

void sort_by_price(product *ptr_arr, int size);
void swap(product *a, product *b);

int main(int argc, char const *argv[])
{
	product *ptr_arr;
	int len;
	int is_input_valid = 0;
	printf("nhap so luong san pham: ");
	scanf("%d", &len);
	product a[len];
	ptr_arr = &a[0];

	while (1) {
		/* menu */
		int opts;
		int is_opts_valid;
		do {
			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. nhap du lieu cac san pham\n", INPUT);
			printf("%d. in ra du lieu cac san pham\n", PRINT);
			printf("%d. sap xep cac san pham theo gia\n", SORT);
			printf("%d. ghi thong tin cac san pham ra file\n", WRITE);
			printf("%d. thoat\n", EXIT);
			printf("lua chon cua ban la: ");
			scanf("%d", &opts);
			fflush(stdin);
			is_opts_valid = opts >= INPUT && opts <= EXIT;
			if (!is_opts_valid) {
				printf("lua chon cua ban (%d) khong hop le!\n", opts);
			}
			/* ask for input */
			is_input_valid = is_input_valid || opts == EXIT || opts == INPUT;
			while (!is_input_valid) {
				printf("ban chua nhap san pham!\n");
				input(ptr_arr, len);
				is_input_valid = 1;
				printf("\n");
			}
		} while (!is_opts_valid);

		switch (opts) {
		case INPUT:
			input(ptr_arr, len);
			break;
		case PRINT:
			print(ptr_arr, len);
			break;
		case SORT:
			sort_by_price(ptr_arr, len);
			printf("cac san pham da duoc sap xep theo gia tang dan\n");
			break;
		case WRITE:
			write("product.txt", ptr_arr, len);
			printf("da xuat %d san pham ra file %s\n", len, "product.txt");
			break;
		case EXIT:
			exit(0);
		default:
			printf("-> chuong chinh co loi, xin thu lai\n");
		}
		printf("\n");
	}
	return 0;
}

void write(const char *filename, product *ptr_arr, int size) {
	FILE *fp = fopen(filename, "w");
	int i;
	for (i = 0; i < size; i++) {
		product product = *(ptr_arr + i);
		fprintf(fp, "Ma SP: %s - Ten SP: %s - Gia: %2.f\n", product.code, product.name, product.price);
	}
	fprintf(fp, "\nTong so: %d SP\n", size);
	fflush(fp);
	fclose(fp);
}

void input(product *ptr_arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("nhap thong tin san pham %d/%d\n", i + 1, size);
		*(ptr_arr + i) = get_product();
	}
}

void print(product *ptr_arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		product product = *(ptr_arr + i);
		printf("Ma SP: %s - Ten SP: %s - Gia: %2.f\n", product.code, product.name, product.price);
	}
}

product get_product() {
	product product;
	printf("nhap ma san pham (toi da 10 ki tu): ");
	get_string(product.code, 10);
	fflush(stdin);
	printf("nhap ten san pham (toi da 30 ki tu): ");
	get_string(product.name, 30);
	fflush(stdin);
	printf("nhap gia san pham: ");
	scanf("%f", &product.price);
	fflush(stdin);
	return product;
}

void get_string(char *str, int num)
{
	char *pos;
	fgets(str, num, stdin);
	/* remove newline at the end */
	pos = strchr(str, '\n');
	if (pos != NULL) {
		*pos = '\0';
	}
}

void sort_by_price(product *ptr_arr, int size)
{
	int is_sorted;
	do {
		is_sorted = 1;
		int i;
		for (i = 1; i < size; i++) {
			product *ptr_product = ptr_arr + i;
			product *ptr_pre_product = ptr_arr + i - 1;
			if (ptr_product->price < ptr_pre_product->price) {
				swap(ptr_product, ptr_pre_product);
				is_sorted = 0;
			}
		}
	} while (!is_sorted);
}

void swap(product *a, product *b)
{
	product tmp = *a;
	*a = *b;
	*b = tmp;
}
