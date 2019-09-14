#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int size);

void print_arr(int *ptr_arr, int size);

void sort(int *ptr_arr, int size, int order);

void swap(int *a, int *b);

int main(int argc, char const *argv[])
{

	int *p;
	int len;
	printf("nhap chieu dai mang: ");
	scanf("%d", &len);
	int a[len];
	p = &a[0];

	input(p, len);
	sort(p, len, -1);
	printf("cac phan tu da duoc sap xep: ");
	print_arr(p, len);

	getch();
	return 0;
}

void input(int *ptr_arr, int size) {
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
		printf("%d ", *ptr_arr);
		ptr_arr++;
	}
	printf("\n");
}

/*
* sort array
* if order > 0 => ascending
* if order < 0 => descending
* if order = 0 no sort.
*/
void sort(int *ptr_arr, int size, int order)
{
	int is_sorted;
	do {
		is_sorted = 1;
		int i;
		for (i = 1; i < size; i++) {
			int *ptr_num = ptr_arr + i;
			int *ptr_pre_num = ptr_arr + i - 1;
			if (*ptr_num < *ptr_pre_num) {
				if (order > 0) {
					swap(ptr_num, ptr_pre_num);
					is_sorted = 0;
				}
			} else if (*ptr_num > *ptr_pre_num) {
				if (order < 0) {
					swap(ptr_num, ptr_pre_num);
					is_sorted = 0;
				}
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
