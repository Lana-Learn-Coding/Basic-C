#include <stdio.h>
#include <conio.h>

void input(int *ptr_arr, int size);

void print_filter(int *ptr_arr, int size, int(*p_fn_filter)(int));

int sum_filter(int *ptr_arr, int size, int(*p_fn_filter)(int));

int is_even(int num);

int is_odd(int num);

int main(int argc, char const *argv[])
{
	int (*pfn_odd_filter)(int) = is_odd;
	int (*pfn_even_filter)(int) = is_even;
	int size = 5;
	int a[size];
	int *ptr = &a[0];

	printf("moi nhap phan tu cho mang\n");
	input(ptr, size);

	printf("cac so le la: ");
	print_filter(ptr, size, pfn_odd_filter);
	printf("\ntong cac so le la: %d", sum_filter(ptr, size, pfn_odd_filter));
	printf("\n");

	printf("cac so chan la: ");
	print_filter(ptr, size, pfn_even_filter);
	printf("\ntong cac so chan la: %d", sum_filter(ptr, size, pfn_even_filter));
	printf("\n");

	getch();
	return 0;
}

void input(int *ptr_arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("nhap phan tu a[%d]: ", i);
		scanf("%d", ptr_arr);
		ptr_arr++;
	}
}

void print_filter(int *ptr_arr, int size, int(*p_fn_filter)(int))
{
	int i;
	for (i = 0; i < size; i++) {
		if (p_fn_filter(*ptr_arr)) {
			printf("%d \t", *ptr_arr);
		}
		ptr_arr++;
	}
}

int sum_filter(int *ptr_arr, int size, int(*p_fn_filter)(int))
{
	int sum = 0;
	int i;
	for (i = 0; i < size; i++) {
		if (p_fn_filter(*ptr_arr)) {
			sum += *ptr_arr;
		}
		ptr_arr++;
	}
	return sum;
}

int is_odd(int num)
{
	return num % 2 != 0;
}

int is_even(int num)
{
	return num % 2 == 0;
}
